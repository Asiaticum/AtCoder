#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e8;
const int MOD = 1e9 + 7;
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

int A, B;
vector<int> a(A), b(B);
int score = 0;

int game(int i, int j) {
    if (i == a.size() - 1 && j == b.size() - 1) {
        return max(a.at(i), b.at(i));
    }

    if (i == a.size() - 1) {
        /* code */
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B;

    for (int i = 0; i < A; i++) {
        cin >> a.at(i);
    }

    for (int i = 0; i < B; i++) {
        cin >> b.at(i);
    }


    return 0;
}
