#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        q.push(i);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
        if (!q.empty()) {
            q.push(q.front());
            q.pop();
        }
    }
}