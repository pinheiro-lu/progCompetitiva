#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int x, y, k;
		cin >> x >> y >> k;
		multiset<int> m, d;
		m.clear(); d.clear();
		for (int i = 2; i * i < y; i++) {
			if (y % i == 0) {
				m.insert(i);
				while (y % i == 0) {
					y /= i;
					m.insert(i);
				}
			}
		}
		if (y > 1) m.insert(y);
		cerr << "y insertred\n";
		for (int i = 2; i * i < x; i++) {
			if (x % i == 0) {
				if (m.find(i) != m.end()) {
					m.erase(m.find(i));
				} else {
					d.insert(i);
				}
				while (x % i == 0) {
					x /= i;
					if (m.find(i) != m.end()) {
						m.erase(m.find(i));
					} else {
						d.insert(i);
					}
				}
			}
		}
		if (x > 1) {
			if (m.find(x) != m.end()) {
				m.erase(m.find(x));
			} else {
				d.insert(x);
			}
		}
		cerr << "x insertred\n";
		cerr << m.size() << " " << d.size() << '\n';
		bool ok = true;
		for (auto it = m.begin(); it != m.end(); it++) {
			if (*it > k) {
				ok = false;
				break;
			}
			for (auto r_it = m.rbegin(); r_it != m.rend(); r_it++) {
				if (it == r_it.base()) break; // Avoid self multiplication
				if (*it * *r_it <= k) {
					auto to_erase = m.find(*r_it);
					if (to_erase != m.end()) {
						m.erase(to_erase);
					}
					cerr << "Erasing " << *r_it << " from m\n";
					break;
				}
			}
		}
		for (auto it = d.begin(); it != d.end(); it++) {
			if (*it > k) {
				ok = false;
				break;
			}
			for (auto r_it = d.rbegin(); r_it != d.rend(); r_it++) {
				if (it == r_it.base()) break;; // Avoid self multiplication
				if (*it * *r_it <= k) {
					auto to_erase = d.find(*r_it);
					if (to_erase != d.end()) {
						d.erase(to_erase);
					}
					cerr << "Erasing " << *r_it << " from d\n";
					break;
				}
			}
		}

		cout << (ok ? m.size() + d.size() : -1) << '\n';
	}


	return 0;
}
