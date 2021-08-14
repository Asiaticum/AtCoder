#include <bits/stdc++.h>
using namespace std;

int sum_range(int A, int B) {
    if (A == B) {
        return B;
    }

    int sum = sum_range(A + 1, B);
    return sum + A;
}

int array_sum(vector<int> &array, int n) {
    if (n == array.size()) {
        return 0;
    }

    int sum = array_sum(array, n + 1);
    return sum + array.at(n);
}

bool is_indivisible(int &N, int n) {
    if (N == 1) {
        return false;
    }

    if (n == N) {
        return true;
    }

    bool flag = is_indivisible(N, n + 1);
    return (N % n != 0) && flag;
}

bool is_prime(int N) { return is_indivisible(N, 2); }

vector<int> reverse_array_from_i(vector<int> &data, int i) {
    if (i == data.size()) {
        vector<int> empty_array(0);
        return empty_array;
    }

    vector<int> tmp = reverse_array_from_i(data, i + 1);
    tmp.push_back(data.at(i));
    return tmp;
}

vector<int> reverse_array(vector<int> &data) { return reverse_array_from_i(data, 0); }

int main() {
    bool a = is_prime(1);
    cout << a << endl;
}
