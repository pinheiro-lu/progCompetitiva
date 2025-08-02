#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e5;
const int MOD = 1e9 + 7;

array<int, 26> cnt; // count of suffixes starting with each letter

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = n-1; i >= 0; i--) {
		switch (s[i]) {
			case 'i':
				cnt[8] += 1; // 'i' is the 9th letter (0-indexed)
				cnt[8] %= MOD;
				break;
			case 'a':
				cnt[0] += cnt[8]; // 'a' is the 1st letter (0-indexed)
				cnt[0] %= MOD;
				break;
			case 'd':
				cnt[3] += cnt[0]; // 'd' is the 4th letter (0-indexed)
				cnt[3] %= MOD;
				break;
			case 'u':
				cnt[20] += cnt[3]; // 'u' is the 21st letter (0-indexed)
				cnt[20] %= MOD;
				break;
			case 'k':
				cnt[10] += cnt[20]; // 'k' is the 11th letter (0-indexed)
				cnt[10] %= MOD;
				break;
			case 'o':
				cnt[14] += cnt[10]; // 'o' is the 15th letter (0-indexed)
				cnt[14] %= MOD;
				break;
			case 'h':
				cnt[7] += cnt[14]; // 'h' is the 8th letter (0-indexed)
				cnt[7] %= MOD;
				break;
			case 'c':
				cnt[2] += cnt[7]; // 'c' is the 3rd letter (0-indexed)
				cnt[2] %= MOD;
				break;
		}
	}

	cout << cnt[2] << '\n';


	return 0;
}
