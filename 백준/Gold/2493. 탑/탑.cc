#include <iostream>
#include <vector>
using namespace std;

int N;
int top[500001];
int ans[500001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> top[i];

    for (int i = 2; i <= N; i++)
    {
        if (top[i] < top[i - 1])
            ans[i] = i - 1;
        else
        {
            int idx = i - 1;
            while (true)
            {
                if (ans[idx] == 0)
                {
                    ans[i] = 0;
                    break;
                }
                else if (top[ans[idx]] > top[i])
                {
                    ans[i] = ans[idx];
                    break;
                }
                else
                    idx = ans[idx];
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << " ";
}