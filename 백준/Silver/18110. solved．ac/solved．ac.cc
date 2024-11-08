#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

double n;
vector<int> score;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    score.resize(n);
    for (int i = 0; i < n; i++)
        cin >> score[i];
    sort(score.begin(), score.end());

    double truncation = round(n / 100 * 15);

    int sum = 0;
    for (int i = truncation; i < n - truncation; i++)
        sum += score[i];
    
    double avg = round((double)sum / (n - truncation * 2));
    cout << avg;
}