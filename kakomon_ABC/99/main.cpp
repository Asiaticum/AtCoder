#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e8;
const ll MOD = 1e9 + 7;
const ll LINF = 1e17;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

int N;
vector<int> memo(100001, 0);

int f(int cu) {
    if (cu == 0) {
        return 0;
    }
    if (memo.at(cu)) {
        return memo.at(cu);
    }

    int res = INF;
    chmin(res, f(cu - 1) + 1);

    int x = 6;
    while (x <= cu) {
        chmin(res, f(cu - x) + 1);
        x *= 6;
    }

    x = 9;
    while (x <= cu) {
        chmin(res, f(cu - x) + 1);
        x *= 9;
    }

    return memo.at(cu) = res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    cout << f(N) << endl;

    return 0;
}
