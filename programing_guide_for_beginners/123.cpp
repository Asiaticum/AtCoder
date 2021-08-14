#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<int, vector<int>> A;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (A.count(a)) {
            A[a].push_back(a);
        } else {
            A[a] = {a};
        }
    }

    pair<int, int> tmp(0, 0);
    for (pair<int, vector<int>> a : A) {
        if (a.second.size() > tmp.second) {
            tmp.first = a.first;
            tmp.second = a.second.size();
        }
    }
    cout << tmp.first << " " << tmp.second << endl;

    return 0;
}
