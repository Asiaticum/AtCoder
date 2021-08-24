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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S, T;
    cin >> S;
    cin >> T;

    bool can_replace = false;
    for (int i = S.size() - 1; i >= 0; i--) {
        bool flag = true;
        if (S.at(i) == T.at(0) || S.at(i) == '?') {
            if (S.substr(i).size() >= T.size()) {
                string fragment = S.substr(i, T.size());
                for (int j = 0; j < fragment.size(); j++) {
                    if (!(fragment.at(j) == T.at(j)) && !(fragment.at(j) == '?')) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    S = S.replace(i, T.size(), T);
                    can_replace = true;
                    break;
                }
            }
        }
    }

    if (can_replace) {
        for (int i = 0; i < S.size(); i++) {
            if (S.at(i) == '?') {
                S.at(i) = 'a';
            }
        }
        cout << S << endl;
    } else {
        cout << "UNRESTORABLE" << endl;
    }


    return 0;
}
