#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

#define MAX 30

void solve(void) {
	int n, k;
	string a;
	
	cin >> n >> k;
	cin >> a;
	
	//sort(a.begin(), a.end());
	int l[MAX];
	for (int i = 0; i < MAX; i++) {
		l[i] = 0;
		debug("%d: %d\n", i, l[i]);
	}
	
	for (int i = 0; i < n; i++) {
		l[a[i]-'a']++;
	}
	for (int i = 0; i < MAX; i++) {
		debug("%d: %d\n", i, l[i]);
	}
	
	while (k--) {
		int aux = n/k;
		debug("ok\n");
		for (int i = 0; i < MAX && aux; i++) {
			if (l[i]) {
				l[i]--;
				aux--;
			}
		}
		debug("ok\n");
		for (int i = 0; i < MAX; i++) {
			debug("%d: %d\n", i, l[i]);
			if (l[i] == 0) {
				char cux = i+'a';
				cout << i+'a';
				debug("%c", cux); 
				break;
			}			
		}
		debug("ok\n");
	}
	cout << endl;
	
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
