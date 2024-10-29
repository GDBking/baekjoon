#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> A;
vector<int> result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A[i] = make_pair(temp, i);
    }
    sort(A.begin(), A.end());
    
    result.resize(N);
    result[A[0].second] = 0;
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (A[i].first == A[i - 1].first)
            result[A[i].second] = cnt;
        else
            result[A[i].second] = ++cnt;
    }

    for (int i : result)
        cout << i << " ";
}