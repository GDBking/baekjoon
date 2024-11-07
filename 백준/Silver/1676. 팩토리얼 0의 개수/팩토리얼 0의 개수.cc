#include <iostream>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int cnt = 0;
    for (int i = 5; i <= N; i += 5) {
        int temp = i;
        while (!(temp % 5)) {
            temp /= 5;
            cnt++;
        }
    }
    cout << cnt;
}