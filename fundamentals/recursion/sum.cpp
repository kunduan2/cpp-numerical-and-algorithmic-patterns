#include <iostream>
#include <vector>
using namespace std;

// Recursive sum of elements of a vector
int sum(const vector<int>& p, int n) {
    if (n == 0) return 0;
    return p[n - 1] + sum(p, n - 1);
}

int main() {
    vector<int> v = {1, 2, 3, 4};
    cout << sum(v, v.size()) << endl;
    return 0;
}
