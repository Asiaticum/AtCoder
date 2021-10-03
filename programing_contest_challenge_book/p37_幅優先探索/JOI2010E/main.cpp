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

const int max_w = 10;
const int max_h = 1000;
int H, W, N;
vector<string> maze(max_h);
vector<int> sx(max_w), sy(max_w), gx(max_w), gy(max_w);

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
queue<int> x_now, y_now;

void input() {
    cin >> H >> W >> N;

    for (int i = 0; i < H; i++) {
        cin >> maze.at(i);
    }

    for (int w = 0; w < N; w++) {
        char now = '0' + w;
        char next = now + 1;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (w == 0 && maze.at(i).at(j) == 'S') {
                    sx.at(w) = j;
                    sy.at(w) = i;
                } else if (w == 0 && maze.at(i).at(j) == '1') {
                    gx.at(w) = j;
                    gy.at(w) = i;
                    sx.at(w + 1) = j;
                    sy.at(w + 1) = i;
                } else if (w < N - 1 && maze.at(i).at(j) == next) {
                    gx.at(w) = j;
                    gy.at(w) = i;
                    sx.at(w + 1) = j;
                    sy.at(w + 1) = i;
                } else if (w == N - 1 && maze.at(i).at(j) == next) {
                    gx.at(w) = j;
                    gy.at(w) = i;
                }
            }
        }
    }
}

int solve(int sx, int sy, int gx, int gy, vector<string> &maze) {
    // cout << sx << sy << gx << gy << endl;
    vector<vector<int>> ans(H, vector<int>(W, INF));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans.at(i).at(j) = INF;
        }
    }
    ans.at(sy).at(sx) = 0;

    x_now.push(sx);
    y_now.push(sy);

    while (x_now.size()) {
        int x = x_now.front();
        int y = y_now.front();
        x_now.pop();
        y_now.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx.at(i);
            int ny = y + dy.at(i);
            int time_now = ans.at(y).at(x);
            if (0 <= nx && 0 <= ny && nx < W && ny < H) {
                int time_next = ans.at(ny).at(nx);

                if (nx == gx && ny == gy && time_now + 1 < time_next) {
                    ans.at(ny).at(nx) = time_now + 1;
                } else if (maze.at(ny).at(nx) != 'X' && time_now + 1 < time_next) {
                    x_now.push(nx);
                    y_now.push(ny);
                    ans.at(ny).at(nx) = time_now + 1;
                }
            }
        }
    }

    return ans.at(gy).at(gx);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int res = 0;
    input();
    for (int i = 0; i < N; i++) {
        res += solve(sx.at(i), sy.at(i), gx.at(i), gy.at(i), maze);
    }

    cout << res << endl;
    return 0;
}
