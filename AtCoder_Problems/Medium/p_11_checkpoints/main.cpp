#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;

    vector<vector<ll>> coordinates(N, vector<ll>(2, 0));
    for (int i = 0; i < N; i++) {
        cin >> coordinates.at(i).at(0) >> coordinates.at(i).at(1);
    }

    vector<vector<ll>> checkpoints(M, vector<ll>(2, 0));

    for (int i = 0; i < M; i++) {
        cin >> checkpoints.at(i).at(0) >> checkpoints.at(i).at(1);
    }

    for (int i = 0; i < N; i++) {
        vector<ll> dist(M, 0);
        for (int j = 0; j < M; j++) {
            dist.at(j) = abs(coordinates.at(i).at(0) - checkpoints.at(j).at(0)) +
                         abs(coordinates.at(i).at(1) - checkpoints.at(j).at(1));
        }
        int index = distance(dist.begin(), min_element(dist.begin(), dist.end())) + 1;
        cout << index << endl;
    }


    return 0;
}
