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
    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int temp;
            cin >> temp;
            q.push(temp);
        }
        else if (cmd == "pop") {
            if (q.empty())
                cout << "-1\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (cmd == "size")
            cout << q.size() << "\n";
        else if (cmd == "empty")
            cout << q.empty() << "\n";
        else if (cmd == "front") {
            if (q.empty())
                cout << "-1\n";
            else
                cout << q.front() << "\n";
        }
        else {
            if (q.empty())
                cout << "-1\n";
            else
                cout << q.back() << "\n";
        }
    }
}