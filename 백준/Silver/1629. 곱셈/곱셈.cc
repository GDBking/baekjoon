#include <iostream>
using namespace std;

long long A, B, C;

int power(long long square);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    cout << power(B);
}

int power(long long square) {
    if (square == 1) return A % C;

    long long k = power(square / 2) % C;
    if (square % 2 == 0) return k * k % C;
    return k * k % C * A % C;
}