#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector<long long> dp(101);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = 2;
    for (int i = 5; i <= 100; i++)
        dp[i] = dp[i - 1] + dp[i - 5];

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << dp[N] << "\n";
    }
}