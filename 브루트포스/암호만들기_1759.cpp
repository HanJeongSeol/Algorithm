#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

bool check(string & pwd) {
	int mo = 0;
	int ja = 0;
	for (char x : pwd) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
			mo += 1;
		}
		else {
			ja += 1;
		}
	}
	return mo >= 1 && ja >= 2;
}

void go(int n, vector<char> &alpha, string pwd, int i) {
	if (pwd.length() == n) {
		if (check(pwd)) {
			cout << pwd << '\n';
		}
		return;
	}
	if (i >= alpha.size()) return;
	go(n, alpha, pwd + alpha[i], i + 1);	//i번째 알파벳을 사용하는 경우 
	go(n, alpha, pwd, i + 1);	//i번째 알파벳 사용하지 않는 경우
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, l;
	cin >> n >> l;
	vector<char> alpha(l);
	for (int i = 0; i < l; i++) {
		cin >> alpha[i];
	}

	sort(alpha.begin(), alpha.end());

	go(n, alpha, "", 0);
}