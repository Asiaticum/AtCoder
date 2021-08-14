#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> d;
    int s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        d.push_back(s);
    }

    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    cout << d.size() << endl;

    return 0;
}
