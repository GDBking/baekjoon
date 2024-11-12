#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
int a, b;
vector<int> isPrime;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    isPrime.resize(N + 1, 1);
    isPrime[0] = 0;
    for (int i = 2; i <= sqrt(N); i++) {
        if (!isPrime[i])
            continue;
        for (int j = i + i; j <= N; j += i)
            isPrime[j] = 0;
    }

    for (int i = 1; i <= N; i++)
        isPrime[i] += isPrime[i - 1];

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << isPrime[b] - isPrime[a - 1] << "\n";
    }
}
