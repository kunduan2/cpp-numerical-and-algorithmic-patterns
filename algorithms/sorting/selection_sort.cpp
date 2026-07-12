#include <iostream>
#include <random>

using namespace std;

// Returns the index of the minimum element in ar[idx_start .. n-1].
int argmin(const int* ar, int n, int idx_start) {
    int minidx = idx_start;
    int tmp = ar[idx_start];
    for (int i = idx_start; i < n; i++) {
        if (ar[i] < tmp) {
            minidx = i;
            tmp = ar[i];
        }
    }
    return minidx;
}

// Prints array elements separated by spaces, followed by a newline.
void print(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

// Fills arr with n random integers in [lo, hi].
// Seed is fixed (42) for reproducible output; swap in random_device for true randomness.
void fillRandom(int arr[], int n, int lo, int hi) {
    // std::random_device rd;
    // int seed = rd();
    int seed = 42;
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> dist(lo, hi);
    for (int i = 0; i < n; i++) {
        arr[i] = dist(gen);
    }
}

int main() {
    const int n = 10;   // const so array size is a compile-time constant (avoids VLA)
    int ar[n];

    fillRandom(ar, n, 1, 100);
    cout << "unsorted array; \n";
    print(ar, n);

    // Selection sort: grow the sorted region one element at a time from the left.
    for (int i = 0; i < n; i++) {
        int tmp_idx = argmin(ar, n, i);
        int tmp2 = ar[i];
        ar[i] = ar[tmp_idx];
        ar[tmp_idx] = tmp2;
    }
    cout << "\nSorted array; \n";
    print(ar, n);

    return 0;
}