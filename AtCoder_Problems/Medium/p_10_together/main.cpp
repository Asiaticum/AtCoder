#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    vector<int> count(pow(10, 5), 0);

    for (int a : A) {
        if (a > 0 && a < count.size() - 1) {
            count.at(a)++;
            count.at(a + 1)++;
            count.at(a - 1)++;
        } else if (a == 0) {
            count.at(a)++;
            count.at(a + 1)++;
        } else {
            count.at(a)++;
            count.at(a - 1)++;
        }
    }

    int max = *max_element(count.begin(), count.end());
    cout << max << endl;


    return 0;
}
