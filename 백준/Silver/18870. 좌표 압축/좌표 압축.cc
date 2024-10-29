#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> A;

bool compare(pair<int, int> a, pair<int, int> b);

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
    int temp = A[0].first;
    A[0].first = 0;
    for (int i = 1; i < N; i++) {
        if (A[i].first == temp)
            A[i].first = A[i - 1].first;
        else {
            temp = A[i].first;
            A[i].first = A[i - 1].first + 1;
        }
    }

    sort(A.begin(), A.end(), compare);
    for (pair<int, int> i : A)
        cout << i.first << " ";
}

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}