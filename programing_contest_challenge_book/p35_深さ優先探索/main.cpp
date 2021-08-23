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

int N, M;

void change_puddle_to_grass(int i, int j, vector<string> &S) {
    bool is_puddle = false;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if ((i + k >= 0 && i + k <= N - 1) && (j + l >= 0 && j + l <= M - 1)) {
                if (S.at(i + k).at(j + l) == 'W') {
                    S.at(i + k).at(j + l) = '.';
                    change_puddle_to_grass(i + k, j + l, S);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S.at(i);
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S.at(i).at(j) == 'W') {
                count++;
                change_puddle_to_grass(i, j, S);
            }
        }
    }

    cout << count << endl;

    return 0;
}
