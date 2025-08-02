#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int EXPN = 17*2e5;

array<int, EXPN> a;
int n, m;

void build() {
	int off = 0;
	for (int k = n; k > 0; --k) {
		for (int i = 0; i < (1 << k); i += 2) {
			a[off+i/2 + (1<<k)] = a[off+i] | a[off+i+1];
		}
		off += 1 << k;
		--k;
		for (int i = 0; i < (1 << k); i += 2) {
			a[off+i/2 + (1<<k)] = a[off+i] ^ a[off+i+1];
		}
		off += 1 << k;
	}
	/*
	for (int i = 0; i < (1 << (n+1)) -1; ++i) {
		cerr << fixed << setw(8) << i << ' ';
	}
	cerr << '\n';
	for (int i = 0; i < (1 << (n+1)) -1; ++i) {
		cerr << bitset<8>{a[i]} << ' ';
	}
	cerr << '\n';
	*/
}

void rebuild (int p, int b) {
	a[p] = b;
	int off = 0;
	int i = (p >> 1) << 1;
	for (int k = n; k > 0; --k) {
	//	cerr << i << ' ' << k << '\n';
		a[off+i/2 + (1<<k)] = a[off+i] | a[off+i+1];
		off += 1 << k;
		--k;
		i = (i >> 1) & ((1 << k) - 2); // divide by 2 and remove the last bit
		a[off+i/2 + (1<<k)] = a[off+i] ^ a[off+i+1];
		off += 1 << k;
		i = (i >> 1) & ((1 << k) - 2); // divide by 2 and remove the last bit
	}
	/*
	for (int i = 0; i < (1 << (n+1)) -1; ++i) {
		cerr << fixed << setw(8) << i << ' ';
	}
	cerr << '\n';
	for (int i = 0; i < (1 << (n+1)) -1; ++i) {
		cerr << bitset<8>{a[i]} << ' ';
	}
	cerr << '\n';
	*/
}



signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < (1 << n); i++) {
		cin >> a[i];
	}
	build();

	while (m--) {
		int p, b;
		cin >> p >> b;
		p--;
		rebuild(p, b);
		cout << a[(1 << (n+1)) - 2] << '\n';
	}


	return 0;
}
