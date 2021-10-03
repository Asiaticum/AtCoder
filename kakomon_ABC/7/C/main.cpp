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

const int MAX_R = 50, MAX_C = 50;
int R, C;
int sy, sx;
int gy, gx;

vector<string> maze(MAX_R);
vector<vector<int>> ans(MAX_R, vector<int>(MAX_C, INF));

void bfs(int x, int y) {
    if (x + 1 <= R - 1 && maze.at(x + 1).at(y) == '.' && ans.at(x + 1).at(y) == -1) {
        ans.at(x + 1).at(y) = ans.at(x).at(y) + 1;
        bfs(x + 1, y);
    }
    if (x - 1 >= 0 && maze.at(x - 1).at(y) == '.' && ans.at(x - 1).at(y) == -1) {
        ans.at(x - 1).at(y) = ans.at(x).at(y) + 1;
        bfs(x - 1, y);
    }
    if (y - 1 >= 0 && maze.at(x).at(y - 1) == '.' && ans.at(x).at(y - 1) == -1) {
        ans.at(x).at(y - 1) = ans.at(x).at(y) + 1;
        bfs(x, y - 1);
    }
    if (y + 1 <= C - 1 && maze.at(x).at(y + 1) == '.' && ans.at(x).at(y + 1) == -1) {
        ans.at(x).at(y + 1) = ans.at(x).at(y) + 1;
        bfs(x, y + 1);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;

    for (int i = 0; i < R; i++) {
        cin >> maze.at(i);
    }

    ans.at(sy - 1).at(sx - 1) = 0;

    bfs(sy - 1, sx - 1);
    cout << ans.at(gy - 1).at(gx - 1) << endl;


    return 0;
}
