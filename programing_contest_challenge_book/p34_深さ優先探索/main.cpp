#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
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

const int MAX_N = 20;
int n, k;
vector<ll> A(MAX_N);

bool dfs(int i, ll sum) {
    if (i == n) {
        return sum == k;
    }

    if (dfs(i + 1, sum)) {
        return true;
    }

    if (dfs(i + 1, sum + A.at(i))) {
        return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A.at(i);
    }

    cin >> k;

    if (dfs(0, 0)) {
        cout << "YES" << endl;
    }


    return 0;
}
