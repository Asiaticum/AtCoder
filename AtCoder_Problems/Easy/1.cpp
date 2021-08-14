#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int c = 1;
    int num = 0;
    while (true) {
        if (c >= B) {
            break;
        }

        c += A - 1;
        num++;
    }
    cout << num << endl;

    return 0;
}
