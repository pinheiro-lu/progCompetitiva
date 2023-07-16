#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string line;

start:
	while (getline(cin, line)) {
		int n;
		stringstream ss(line);
		ss >> n;
		set <int> s;
		int u[n];
		for (int i = 0; i < n; i++) {
			ss >> u[i];
		}
		for (int i = 1; i < n; i++) {
			int x = abs(u[i]-u[i-1]);
			s.insert(x);
			if (x == 0 || x >= n) {cout << "Not jolly\n"; goto start;}
		}

		if (s.size() == n-1) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}

