#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int N = 101;

array<int, N> a;

int solve(int ini, int fim) {
	array<int, N> b;
	for (int i = ini; i <= fim; ++i) {
		b.at(i-ini) = a.at(i);
	}
	vi cnt;
	int aux = 1;
	for (int i = 1; i <= fim+1; ++i) {
		if (b.at(i) == b.at(i-1)) {
			++aux;
		} else {
			cnt.push_back(aux);
			aux = 1;
		}
	}
	if (cnt.size() == 1) return 1;
	if (cnt.size() & 1) return 4;
	set <int>s1, s2, s3;
	for (int i = 0; i < fim-ini+1; ++i) {
		s3.insert(b.at(i));
	}
	if (s3.size() > 2) return 4;
	for (int i = 0, j = 1; j < cnt.size(); i += 2, j += 2) {
		s1.insert(cnt.at(i));
		s2.insert(cnt.at(j));
	}
	if (s1.size() == 1 && s2.size() == 1) return 2;
	return 4;
}

signed main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		fill (a.begin(), a.end(), 0);
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			cin >> a.at(i);
		}
		if (k == 1) {
			cout << "YES\n";
			continue;
		}
		if (k == 2) {
			vi cnt;
			int aux = 1;
			for (int i = 1; i <= n; ++i) {
				if (a.at(i) == a.at(i-1)) {
					++aux;
				} else {
					cnt.push_back(aux);
					aux = 1;
				}
			}
			if (cnt.size() == 1) {
				cout << "YES\n";
				continue;
			}
			if (cnt.size() & 1) {
				cout << "NO\n";
				continue;
			}
			set <int>s1, s2;
			for (int i = 0, j = 1; j < cnt.size(); i += 2, j += 2) {
				s1.insert(cnt.at(i));
				s2.insert(cnt.at(j));
			}
			if (s1.size() == 1 && s2.size() == 1) {
				cout << "YES\n";
				continue;
			}
			cout << "NO\n";
			continue;
		}
		bool finish = false;
		for (int i = 0; i < n; ++i) {
			int ans = solve(0, i) + solve(i+1,n-1);
			if (ans <= 3) {
				finish = true;
				cout << "YES\n";
				break;
			}
		}
		if (finish) continue;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				int ans = solve(0,j) + solve(j+1,i-1);
				cerr << '(' << i <<',' << j << ')' << ' ' << ans << '\n';
				if (ans <= 3) {
					int it = i;
					bool can = true;
					while (it < n) {
						if (a.at(it-i) != a.at(it)) {
							can = false;
							break;
						}
						++it;
					}
					if (can) {
						cout << "YES\n";
						finish = true;
						break;
					}
				}
			}
		}
		if (finish) continue;
		cout << "NO\n";

	}
	return 0;
}




