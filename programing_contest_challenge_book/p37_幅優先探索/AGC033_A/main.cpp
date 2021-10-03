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

    vector<string> A(H);
    for (int i = 0; i < H; i++) {
        cin >> A.at(i);
    }

    vector<int> sx, sy;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A.at(i).at(j) == '#') {
                sy.push_back(i);
                sx.push_back(j);
            }
        }
    }

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    vector<vector<int>> ans(H, vector<int>(W, INF));
    queue<int> x, y;

    for (int i = 0; i < sx.size(); i++) {
        x.push(sx.at(i));
        y.push(sy.at(i));
        ans.at(sy.at(i)).at(sx.at(i)) = 0;
    }

    while (x.size()) {
        int x_now = x.front();
        int y_now = y.front();
        x.pop();
        y.pop();
        for (int j = 0; j < 4; j++) {
            int nx = x_now + dx.at(j);
            int ny = y_now + dy.at(j);
            if (0 <= nx && nx < W && 0 <= ny && ny < H) {
                int time_now = ans.at(y_now).at(x_now);
                int time_next = ans.at(ny).at(nx);
                if (A.at(ny).at(nx) == '.' && time_now + 1 < time_next) {
                    ans.at(ny).at(nx) = time_now + 1;
                    A.at(ny).at(nx) = '#';
                    x.push(nx);
                    y.push(ny);
                }
            }
        }
    }

    int max = 0;
    for (vector<int> a : ans) {
        int tmp = *max_element(a.begin(), a.end());
        if (tmp > max) {
            max = tmp;
        }
    }

    // for (int i = 0; i < H; i++) {
    //     for (int j = 0; j < W; j++) {
    //         cout << ans.at(i).at(j) << "";
    //     }
    //     cout << endl;
    // }


    cout << max << endl;

    return 0;
}
