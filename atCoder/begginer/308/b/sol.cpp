#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
const int N = 100, M = 100;
string c[N+10], d[M+10];
int p[M+10];

int indice(int j) {
	for (int i = 1; i <= m; i++) {
		if (c[j] == d[i]) return i;
	}
	return 0;
}

void solve() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	
	for (int i = 1; i <= m; i++) {
		cin >> d[i];
	}

	for (int i = 0; i <= m; i++) {
		cin >> p[i];
	}
	
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum+=p[indice(i)];
	}

	cout << sum;


}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	//cin >> t;
	while (t--) solve();

	return 0;
}

