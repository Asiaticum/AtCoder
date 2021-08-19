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

typedef pair<int, int> P;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int R, C;
    cin >> R >> C;

    int sy, sx;
    cin >> sy >> sx;
    sy--, sx--;

    int gy, gx;
    cin >> gy >> gx;
    gy--, gx--;

    vector<string> maze(R);
    for (int i = 0; i < R; i++) {
        cin >> maze.at(i);
    }

    vector<vector<int>> d(R, vector<int>(C, INF));
    vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};

    queue<P> que;
    que.push(P(sy, sx));
    d.at(sy).at(sx) = 0;

    while (que.size()) {
        P p = que.front();
        que.pop();
        if (p.first == gy && p.second == gx) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = p.second + dx.at(i), ny = p.first + dy.at(i);
            if (0 <= nx && nx < C && 0 <= ny && ny < R && maze.at(ny).at(nx) != '#' &&
                d.at(ny).at(nx) == INF) {
                que.push(P(ny, nx));
                d.at(ny).at(nx) = d.at(p.first).at(p.second) + 1;
            }
        }
    }

    cout << d.at(gy).at(gx) << endl;
    return 0;
}
