#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int, vector<int>, less<int>> max_pq;
map<int, int> cnt;

int main()
{
    int T, n, k;
    char cmd;

    cin >> T;
    while (T--) 
    {
        min_pq = {};
        max_pq = {};
        cnt.clear();

        cin >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> cmd >> n;

            if (cmd == 'I')
            {
                min_pq.push(n);
                max_pq.push(n);
                cnt[n]++;
            }
            else {
                if (n == 1)
                {
                    if (!max_pq.empty()) {
                        cnt[max_pq.top()]--;
                        max_pq.pop();
                    }
                }
                else
                {
                    if (!min_pq.empty()) {
                        cnt[min_pq.top()]--;
                        min_pq.pop();
                    }
                }

                while (!min_pq.empty() && cnt[min_pq.top()] == 0)
                    min_pq.pop();
                while (!max_pq.empty() && cnt[max_pq.top()] == 0)
                    max_pq.pop();
            }
        }

        if (max_pq.empty() || min_pq.empty())
            cout << "EMPTY\n";
        else
            cout << max_pq.top() << " " << min_pq.top() << "\n";
    }

    return 0;
}