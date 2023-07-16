#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, a, b;

	cin >> n >> a >> b;

	if (a + b < n) {
		cout << n - (a + b) << '\n';
	} else {
		if (n == 1 && a == b) {
			cout << "1\n" << a << ':' << a << '\n';
			return 0;
		}
		cout << "0\n";
		if (a == 0) {
			for (int i = 0; i < n-1; i++) {
				cout << "0:1\n";
			}
			cout << "0:" << b - n + 1 << '\n';
			return 0;
		}
		if (b == 0) {
			for (int i = 0; i < n-1; i++) {
				cout << "1:0\n";
			}
			cout << a - n + 1 << ":0\n";
			return 0;
		}
	}
	if (n == 1) {cout << a << ':' << b << '\n'; return 0;}
	int i;
	for (i = 0; i < n - 2 && a; i++, a--) {
		cout << "1:0\n";
	}
	if (a) {
		i++;
		cout << a << ":0\n";
	}
	for (; i < n - 1 && b; i++, b--) {
		cout << "0:1\n";
	}
	if (b) {
		cout << "0:" << b << '\n';
		i++;
	}
	for (; i < n; i++) {
		cout << "0:0\n";
	}

	return 0;
}




