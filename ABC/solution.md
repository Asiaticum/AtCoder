# 解法
## D
### 方針
${\rm gcd}(A_{i},k)=1$ となるのは$k$が$A_{i}$の任意の素因数を持たないことと同値である．今回の問題は$1\leq p \leq {\rm max}A$かつ，$p$がある$A_i$の素因数となるようなものを求める．このような$p$について，${\rm gcd}(A_{i},p)\neq 1$であり，任意の整数$n$について${\rm gcd}(A_{i},np)\neq 1$である．よって，このような$p$と$1\leq np \leq M$となるような$np$を全て求めて，$1$から$M$までの数から消去すれば残った数が答えとなる．
### 実装
```cpp
int maxA = 100000;

int N, M;
cin >> N >> M;

vector<bool> k(maxA + 1, true);
for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a != 1) {
        k.at(a) = false;
    }
}
```
まず，与えられた整数列$A$の各要素は，$1$でない限り条件を満たすような$k$の要素になり得ないので$k$から消す．次に，実際に素数$p$を求める．
```cpp
vector<bool> isprime(maxA + 1, true);
vector<int> prime; // 素数が格納されるベクトル
for (int i = 2; i < maxA + 1; i++) {
    if (!isprime.at(i)) {
        continue;
    }
    for (int j = i + i; j < maxA + 1; j += i) {
        isprime.at(j) = false; // pの整数倍を消去
        k.at(i) = k.at(i) & k.at(j); // j(iの整数倍)がAの要素であればiは使えない素数
    }
    if (!k.at(i)) {
        prime.push_back(i); // iが使えない素数ならprimeにiを格納する．
    }
}

for (int p : prime) {
    for (int j = p + p; j < M + 1; j += p) {
        k.at(j) = false; // 使えない素数pの倍数を消去していく．
    }
}
```
各素数$i$について，$2$以上の整数$n$をかけた$ni$は素数にはなり得ないので$isprime$の$ni$番目の要素を削除する操作を繰り返すことで，素数$p$を抽出できる．素数$p$が$k$で使える素数に含まれていなければ$prime$に$p$を格納する．その後各$p$の整数倍を$k$で使えない数に指定すれば，残った数が条件を満たす数となる．