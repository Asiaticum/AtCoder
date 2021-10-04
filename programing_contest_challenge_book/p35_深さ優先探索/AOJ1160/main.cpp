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

const int max_w = 50, max_h = 50;
int w, h;
vector<vector<int>> maze(max_h, vector<int>(max_w, 0));
vector<vector<int>> reached(max_h, vector<int>(max_w, 0));

void dfs(int x, int y) {
    if (x < 0 || w <= x || y < 0 || h <= y) {
        return;
    } else if (maze.at(y).at(x) == 0) {
        return;
    }

    maze.at(y).at(x) = 0;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
    dfs(x + 1, y + 1);
    dfs(x - 1, y - 1);
    dfs(x - 1, y + 1);
    dfs(x + 1, y - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ans;
    while (true) {
        cin >> w >> h;
        if (w == 0 && w == h) {
            return 0;
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> maze.at(i).at(j);
            }
        }

        ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (maze.at(i).at(j) == 1) {
                    dfs(j, i);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    cout << ans << endl;

    return 0;
}
