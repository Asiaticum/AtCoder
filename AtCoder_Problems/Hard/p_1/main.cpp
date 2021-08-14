#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int rounder_up(int a, int b) { return (a + (b - 1)) / b; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;
    cin >> S;

    vector<int> res(S.size(), 0);

    vector<char> grid = {'R', 'L'};
    int g = 0;
    char grid_now = grid.at(g);
    int count = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) != grid_now) {
            if (grid_now == 'L') {
                res.at(i - count - 1) += count / 2;
                res.at(i - count) += rounder_up(count, 2);
            } else {
                res.at(i) += count / 2;
                res.at(i - 1) += rounder_up(count, 2);
            }

            g++;
            grid_now = grid.at(g % 2);
            count = 0;
        }
        count++;

        if (i == S.size() - 1) {
            res.at(i - count) += count / 2;
            res.at(i - count + 1) += rounder_up(count, 2);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        if (i != res.size() - 1) {
            cout << res.at(i) << " ";
        } else {
            cout << res.at(i) << endl;
        }
    }


    return 0;
}
