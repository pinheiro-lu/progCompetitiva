#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

int sx[10], sy[10];
int t[10][10];

struct A {
	int a;
	int b;

	friend bool operator< (const A & l, const A & r) {
		return l.b < r.b;
	}
};



void solve(void) {
	int n;

	cin >> n;

	A p[n];

	for (int i = 0; i < n; i++) {
		cin >> p[i].a;
	}
	for (int i = 0; i < n; i++) {
		cin >> p[i].b;
	}

	sort (p, p+n);

	ll sum = 0;

	for (int i = 0; i < n; i++) {
		sum += p[i].a + p[i].b;
		//cout << "a = " << p[i].a << " b = " << p[i].b << endl;
	}

	sum -= p[n-1].b;

	cout << sum << endl;

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
