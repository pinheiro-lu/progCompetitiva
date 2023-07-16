#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	vector<string> s(52);

	for (int i = 0; i < 52; i++) {
		cin >> s[i];
	}

	int y = 0;

	for (int i = 0; i < 3; i++){
		int n = s.size()-26;
		int x = s[n][0] >= '2' && s[n][0] <= '9' ? stoi(s[s.size()-26].substr(0,1)) : 10;
		s.erase(s.begin()+s.size()-26, s.begin()+s.size()-25);
		y+=x;
		s.erase(s.end()-25 - (10-x), s.end()-25);
	}

	cout << s[y-1] << '\n';

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;

	for (int i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";
		solve();
	}
	return 0;
}

