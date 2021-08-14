#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> A;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        A.push_back(make_pair(b, a));
    }
    sort(A.begin(), A.end());

    for (pair<int, int> a : A) {
        cout << a.second << " " << a.first << endl;
    }


    return 0;
}
