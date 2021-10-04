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

vector<string> maze(10);
vector<string> maze_copy(10);

void dfs(int x, int y) {
    if (x < 0 || 10 <= x || y < 0 || 10 <= y) {
        return;
    } else if (maze.at(y).at(x) == 'x') {
        return;
    }

    maze.at(y).at(x) = 'x';

    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

bool is_adjacent(int x, int y) {
    char left, right, up, under;
    if (x - 1 >= 0) {
        left = maze.at(y).at(x - 1);
    }
    if (x + 1 < 10) {
        right = maze.at(y).at(x + 1);
    }
    if (y - 1 >= 0) {
        under = maze.at(y - 1).at(x);
    }
    if (y + 1 < 10) {
        up = maze.at(y + 1).at(x);
    }

    if (left == 'o' || right == 'o' || up == 'o' || under == 'o') {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 10; i++) {
        cin >> maze_copy.at(i);
    }

    int ans;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maze = maze_copy;
            if (is_adjacent(j, i) || maze.at(i).at(j) == 'o') {
                ans = 0;
                maze.at(i).at(j) = 'o';
                for (int k = 0; k < 10; k++) {
                    for (int l = 0; l < 10; l++) {
                        if (maze.at(k).at(l) == 'o') {
                            dfs(l, k);
                            ans++;
                        }
                    }
                }
                if (ans == 1) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
