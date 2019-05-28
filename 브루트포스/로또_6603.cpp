#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> a;
		vector<int> k(n);
		for (int i = 0; i < n; i++) {
			cin >> k[i];
		}
		for (int i = 0; i < n - 6; i++) {
			a.push_back(0);
		}
		for (int i = 0; i < 6; i++) {
			a.push_back(1);
		}
		vector<vector<int>> save;
		do {
			vector<int> current;
			for (int i = 0; i < n; i++) {
				if (a[i] == 1) {
					current.push_back(k[i]);
				}
			}
			save.push_back(current);
		} while (next_permutation(a.begin(), a.end()));
		sort(save.begin(), save.end());
		for (auto x : save) {
			for (int i = 0; i < x.size(); i++) {
				cout << x[i] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}