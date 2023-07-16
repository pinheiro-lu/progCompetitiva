#include <bits/stdc++.h>

using namespace std;

int ans(string s, int l, int r) {
	if (r-l < 1) return 0;
	//for (int i = l; i <=r; i++) cout << s[i]; cout << '\n';	
	if (s[l] == s[r]) {
		if (s[l] == s[l+1]) return ans(s, l+1, r-1);
	//	cout << "1\n";
		return 1 + ans(s, l+2, r-1);
	}
	if (r-l == 1) { 
	//	cout << "1\n";
		return 1;
	}
	for (int i = l; i <= r; i++) {
		if (s[i] == s[r]) {
	//		cout << "1\n";
			return 1 + ans(s, l, i-1) + ans(s, i, r);
		}
	}	
}

void solve(int n, string s) {
	int l, r;

	cin >> l >> r;
	
	cout << ans(s, l-1, r-1) << '\n';	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	string s;

	cin >> n >> q >> s;

	while (q--) solve(n, s);

	return 0;
}
