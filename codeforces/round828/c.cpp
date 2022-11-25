#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	int n;
	char c;
	string s;

	cin >> n >> c;
	cin >> s;

	string s2 = s + s;

	int aux = 0, ans = 0;

	for (int i = 0; i < n; i++) {
		if (s2[i] == c) {
			while (s2[i] != 'g') {
				aux++;
				i++;
			}
		}
		ans = max(ans, aux);
		aux = 0;
	}

	cout << ans << endl;

}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	
	cin >> t;
	
	while (t--)
		solve();
		
	return 0;
}
