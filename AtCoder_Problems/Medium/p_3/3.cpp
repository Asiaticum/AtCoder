#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll sum(int l, int g) {
    ll s = 0;
    int bigger = max(l, g);
    int smaller = min(l, g);
    for (int i = 0; i < bigger + 1; i++) {
        s += i;
    }

    for (int i = 0; i < smaller; i++) {
        s += i;
    }

    return s;
}

int main() {
    string S;
    cin >> S;

    ll l_count = 0;
    ll g_count = 0;
    char flag = 'l';
    ll res = 0;
    int i = 0;
    while (true) {
        if (i >= S.size()) {
            res += sum(l_count, g_count);
            break;
        }

        if (S.at(i) == '<') {
            if (flag == 'g') {
                flag = 'l';
                res += sum(l_count, g_count);
                l_count = 0;
                g_count = 0;
            }
            l_count++;
        } else {
            if (flag == 'l') {
                flag = 'g';
            }
            g_count++;
        }
        i++;
    }
    cout << res << endl;

    return 0;
}
