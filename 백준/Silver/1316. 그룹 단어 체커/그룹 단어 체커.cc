#include <iostream>
#include <vector>
using namespace std;

int N;
vector<bool> alphabet(26);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int cnt = N;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			if (j < temp.length() - 1 && temp[j] == temp[j + 1])
				continue;

			if (!alphabet[temp[j] - 97])
				alphabet[temp[j] - 97] = true;
			else {
				cnt--;
				break;
			}
		}
		fill(alphabet.begin(), alphabet.end(), false);
	}

	cout << cnt;
}