#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int s = 0;
int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int num;
		string sen;
		cin >> sen;
		if (sen == "add") {
			cin >> num; num--;
			s = s | (1 << num);
		}
		if (sen == "check") {
			cin >> num; num--;
			int s1 = s & (1 << num);
			if (s1)
				puts("1");
			else
				puts("0");
		}
		if (sen == "remove") {
			cin >> num; num--;
			s = s & ~(1 << num);
		}
		if (sen == "toggle") {
			cin >> num; num--;
			s = s ^ (1 << num);
		}
		if (sen == "all") {
			s = s | (1 << 20) - 1;
		}
		if (sen == "empty") {
			s = 0;
		}
	}
}