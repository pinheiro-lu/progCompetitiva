#include <bits/stdc++.h>
using namespace std;

#define dbg(args...) printf(args)
#define endl '\n'

typedef long long ll;

#define MAX 100000009

int divb[MAX];

int div2 (ll a) {
	if (divb[a] != -1) return divb[a];
	if (a % 2 == 0) {
		int aux = 1 + div2(a/2);
		divb[a] = aux;
		return aux;
	}
	divb[a] = 0; return 0;
}

void solve(void) {
	int n;

	cin >> n;

	ll a[n];

	int sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += div2(a[i]);
	}

	int ans = 0;

	dbg("sum = %d\n", sum);

	sort(divb, divb + MAX);

	for (int i = MAX-1; divb[i] > -1 && sum < n; i--) {
		dbg("oi");
		sum += divb[i];
		if(i % 2 == 0)ans++;
	}

	//if (sum < n) dbg("%d\n\n", sum);
	cout << ((sum >= n) ? ans : -1) << endl;

	

}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
 
	for (int i = 0; i < MAX; i++) {
		divb[i] = -1;
	}
	
	cin >> t;
	
	while (t--)
		solve();
		
	return 0;
}
