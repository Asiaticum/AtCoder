#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;

    bool flag = false;
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1 - i; j++) {
            int k = N - i - j;
            if (10000 * i + 5000 * j + 1000 * k == Y) {
                flag = true;
                if (flag) {
                    cout << i << " " << j << " " << k << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}
