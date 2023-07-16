#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string l;
	while (getline(cin, l)) {
		int n;
		const char * a = l.c_str();

		sscanf(a, "%d", &n);
		getline(cin, l);
		a = l.c_str();
		char *token = strtok((char*)a, " ");
		int mel = 0;
		for (int i = 0; i < n; i++) {
			int x;
			sscanf(token, "%d", &x);
			if (x > mel) mel = x;
			token = strtok(NULL, " ");
		}
		cout << (mel < 10? 1 : mel < 20? 2 : 3) << '\n';
	}


}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}

