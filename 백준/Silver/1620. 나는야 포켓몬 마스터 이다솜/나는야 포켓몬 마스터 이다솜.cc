#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
vector<pair<string, int>> dict;
vector<string> monsterNo;

int binarySearch(string key);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    dict.resize(N);
    monsterNo.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> monsterNo[i];
        dict[i - 1] = make_pair(monsterNo[i], i);
    }
    sort(dict.begin(), dict.end());

    for (int i = 0; i < M; i++) {
        string temp;
        cin >> temp;
        if (temp[0] > '0' && temp[0] <= '9')
            cout << monsterNo[stoi(temp)] << "\n";
        else {
            cout << binarySearch(temp) << "\n";
        }
    }
}

int binarySearch(string key) {
    int l = 0, r = N - 1;
    while (true) {
        int pivot = (l + r) / 2;
        if (dict[pivot].first == key)
            return dict[pivot].second;
        else if (dict[pivot].first < key)
            l = pivot + 1;
        else
            r = pivot - 1;
    }
    return -1;
}