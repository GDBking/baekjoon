#include <iostream>
#include <cmath>

using namespace std;

int Z(int n, int r, int c) {
    if (n == 0) {
        return 0;
    }
    int half = 1 << (n - 1);
    if (r < half && c < half) {
        // 1사분면
        return Z(n - 1, r, c);
    }
    else if (r < half && c >= half) {
        // 2사분면
        return half * half + Z(n - 1, r, c - half);
    }
    else if (r >= half && c < half) {
        // 3사분면
        return 2 * half * half + Z(n - 1, r - half, c);
    }
    else {
        // 4사분면
        return 3 * half * half + Z(n - 1, r - half, c - half);
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    cout << Z(N, r, c) << endl;
    return 0;
}
