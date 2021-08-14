#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abcde";
    string a = "a";
    int start = s.find('b');
    int end = s.find('c');
    cout << s.substr(0, 2) << endl;
    cout << s.substr(2) << endl;
    cout << a << endl;

    for (int i = 0; i != 5; i++) {
        continue;
    }
    cout << -1 % 2 << endl;


    return 0;
}
