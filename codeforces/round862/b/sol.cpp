#include <bits/stdc++.h>

using namespace std;

string solveRec (string s, int i, multiset<char> a) {
	if (i == s.length() - 1) {
		return s;
	}
	if (s[i] == *a.begin()) {
		a.erase(a.begin());
		return solveRec(s, i+1, a);
	}
	string sol1 = s;
	int j;
	for (j = s.length() - 1; j > i; j--) {
		if (s[j] == *a.begin()) break;
	}
	sol1.insert(i, 1, s[j]);
       	sol1.erase(j,1);
	string sol2 = s;
	if (s[i+1] == *a.begin()) {
		sol2.erase(i+1, 1);
		for (int j = i+2; j < s.length(); j++) {
			if (s[j] >= s[i+1]) {
				sol2.insert(j,1, s[i+1]);
				break;
			}
		}
		if (j == s.length()) {
			sol2.push_back(s[i+1]);
		}
	}
	return sol2;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	multiset<char> a;
	for (char c : s) {
		a.insert(c);
	}
	s = solveRec(s, 0, a);
	cout << s << '\n';
					
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}	

