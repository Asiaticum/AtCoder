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

int H, W;
vector<string> c(500);
vector<vector<int>> reached(500, vector<int>(500, 0));

void dfs(int x, int y) {
    if (x < 0 || W <= x || y < 0 || H <= y) {
        return;
    } else if (c.at(y).at(x) == '#') {
        return;
    }

    if (reached.at(y).at(x)) {
        return;
    }

    reached.at(y).at(x) = 1;

    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        cin >> c.at(i);
    }

    int sx, sy, gx, gy;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (c.at(i).at(j) == 's') {
                sy = i;
                sx = j;
            } else if (c.at(i).at(j) == 'g') {
                gy = i;
                gx = j;
            }
        }
    }

    dfs(sx, sy);
    if (reached.at(gy).at(gx)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
