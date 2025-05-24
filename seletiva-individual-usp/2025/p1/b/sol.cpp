#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	string s;
	cin >> n >> k >> s;
	s.insert(0, 1, '.');
	s.append(1, '.');
	vector<pair<int, int>> ind;
	int cnt_o = 0, vag = 0, cnt_vag = 0;
	for (int i = 1; i <= n+1; ++i) {
		if (s[i] == '?' && (s[i-1] == 'o' || s[i+1] == 'o')) {
			s[i] = '.';
		}
		if (s[i] == '?') {
			++vag;
		} else {
			if (vag) {
				ind.push_back({i - vag, vag});
				cnt_vag += (vag+1) / 2;
			}
			vag = 0;
		}
		cnt_o += (s[i] == 'o');
	}
	if (cnt_o + cnt_vag == k) {
		for (auto [idx, v] : ind) {
			if (v & 1) {
				s[idx] = 'o';
				for (int i = idx+1; i < idx + v; i+=2) {
					s[i] = '.';
					s[i+1] = 'o';
				}
			}
		}
	}
	if (cnt_o == k) {
		for (char &c : s) {
			if (c == '?') {
				c = '.';
			}
		}
	}
	cout << s.substr(1, n) << '\n';

	return 0;
}
