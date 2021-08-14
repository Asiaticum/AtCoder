#include <bits/stdc++.h>
using namespace std;

char mine_sweep(vector<vector<char>> &S, int i, int j) {
    int count = 0;
    for (int k = i - 1; k < i + 2; k++) {
        for (int l = j - 1; l < j + 2; l++) {
            if (S.at(k).at(l) == '#') {
                count++;
            }
        }
    }
    char count_char = '0' + count;
    return count_char;
}

using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int H, W;
    cin >> H >> W;

    vector<vector<char>> S(H + 2, vector<char>(W + 2, '.'));
    for (int i = 1; i < H + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            cin >> S.at(i).at(j);
        }
    }

    vector<vector<char>> ans(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S.at(i + 1).at(j + 1) == '#') {
                ans.at(i).at(j) = '#';
            } else {
                ans.at(i).at(j) = mine_sweep(S, i + 1, j + 1);
            }
        }
    }


    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans.at(0).size(); j++) {
            if (j != ans.at(0).size() - 1) {
                cout << ans.at(i).at(j);
            } else {
                cout << ans.at(i).at(j) << endl;
            }
        }
    }

    return 0;
}
