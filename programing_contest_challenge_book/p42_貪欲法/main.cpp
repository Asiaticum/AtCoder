#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e8;
const int MOD = 1e9 + 7;
const ll LINF = 1e17;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int charge = 1000 - N;

    int counter = 0;

    while (true) {
        if (charge == 0) {
            break;
        }

        if (charge >= 500) {
            charge -= 500;
        } else if (charge >= 100) {
            charge -= 100;
        } else if (charge >= 50) {
            charge -= 50;
        } else if (charge >= 10) {
            charge -= 10;
        } else if (charge >= 5) {
            charge -= 5;
        } else if (charge >= 1) {
            charge -= 1;
        }
        counter++;
    }

    cout << counter << endl;

    return 0;
}
