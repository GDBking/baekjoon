#include<iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int i = 1;
    for (; i < N; i *= 2);

    cout << 2 * N - i;

    return 0;
}