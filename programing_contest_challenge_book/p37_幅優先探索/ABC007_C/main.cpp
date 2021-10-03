#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using ll = long long;
const int INF = 1e8;
const ll MOD = 1e9+7;
const ll LINF = 1e17;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int R, C;
    cin >> R >> C;

    int sy, sx;
    cin >> sy >> sx;

    int gy, gx;
    cin >> gy >> gx;

    vector<string> c(R);
    for (int i = 0; i < R; i++)
    {
        cin >> c.at(i);
    }

    vector<vector<int>> ans(R, vector<int>(C, INF));
    queue<int> qx, qy;
    vector<int> dx={0, 1, 0, -1};
    vector<int> dy={1, 0, -1, 0};

    qx.push(sx-1);
    qy.push(sy-1);

    ans.at(sy-1).at(sx-1) = 0;

    while (!qx.empty())
    {
        int nx = qx.front();
        int ny = qy.front();
        qx.pop();
        qy.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = nx + dx.at(i);
            int xy = ny + dy.at(i);
            int nn = ans.at(ny).at(nx);
            int xn = ans.at(xy).at(xx);
            if (c.at(xy).at(xx)=='.' && nn + 1 < xn)
            {
                ans.at(xy).at(xx) = nn + 1;
                qx.push(xx);
                qy.push(xy);
            }
        }
    }

    cout << ans.at(gy-1).at(gx-1) << endl;

    return 0;
}
