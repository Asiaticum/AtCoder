#include <bits/stdc++.h>
using namespace std;

int tmp = 1;

int tmp_func() {
    int tmp = 2;
    cout << tmp << endl;
    return tmp;
}

int main() {
    int a = tmp_func();
    cout << tmp << endl;
}
