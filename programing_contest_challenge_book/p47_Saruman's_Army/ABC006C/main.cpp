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

    int N;
    cin >> N;

    vector<int> W(N);
    for (int i = 0; i < N; i++) {
        cin >> W.at(i);
    }

    vector<int> can_put(0);
    for (int w : W) {
        if (can_put.size() == 0) {
            can_put.push_back(w);
            continue;
        }

        bool is_heavier = true;
        for (int &p : can_put) {
            if (w <= p) {
                p = w;
                is_heavier = false;
                break;
            }
        }

        if (is_heavier) {
            can_put.push_back(w);
            sort(can_put.begin(), can_put.end());
        }
    }

    cout << can_put.size() << endl;

    return 0;
}
