#include <bits/stdc++.h>

#include <algorithm>
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S.at(i);
    }

    vector<vector<int>> ans(H, vector<int>(W, INF));
    ans.at(0).at(0) = 0;

    queue<int> qx, qy;
    qx.push(0);
    qy.push(0);
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    while (qx.size()) {
        int x_now = qx.front();
        int y_now = qy.front();
        qx.pop();
        qy.pop();

        for (int i = 0; i < 4; i++) {
            int x_next = x_now + dx.at(i);
            int y_next = y_now + dy.at(i);
            if (0 <= x_next && x_next < W && 0 <= y_next && y_next < H) {
                int time_now = ans.at(y_now).at(x_now);
                int time_next = ans.at(y_next).at(x_next);
                if (S.at(y_next).at(x_next) == '.' && time_now + 1 < time_next) {
                    ans.at(y_next).at(x_next) = time_now + 1;
                    qx.push(x_next);
                    qy.push(y_next);
                }
            }
        }
    }

    if (ans.at(H - 1).at(W - 1) == INF) {
        cout << -1 << endl;
        return 0;
    }

    int sharp_num = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S.at(i).at(j) == '#') {
                sharp_num++;
            }
        }
    }

    int cost = H * W - sharp_num - ans.at(H - 1).at(W - 1) - 1;
    cout << cost << endl;

    return 0;
}
