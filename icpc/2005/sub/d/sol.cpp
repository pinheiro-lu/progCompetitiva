#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

bool are_same(array<int, 6> lhs, array<int, 6> rhs) {
	array<int, 6> aux;
	for (int i = 0; i < 6; ++i) {
		//cerr << lhs.at(i) << ' ' << rhs.at(i) << '\n';
	}
	//cerr << '\n';
	vector<array<int, 6>> perms;
	for (int k = 0; k < 8; ++k) {
		aux = rhs;
		for (int i = 0; i < 6; ++i) {
			//cerr << aux.at(i) << ' ';
		}
		//cerr << '\n';
		for (int i = 0; i < 6; ++i) {
			//cerr << rhs.at(i) << ' ';
		}
		//cerr << '\n';
		aux.at(0) = rhs.at(1);
		aux.at(3) = rhs.at(0);
		aux.at(5) = rhs.at(3);
		aux.at(1) = rhs.at(5);
		rhs = aux;
		for (int j = 0; j < 4; ++j) {
			aux = rhs;
			aux.at(1) = rhs.at(4);
			aux.at(2) = rhs.at(1);
			aux.at(3) = rhs.at(2);
			aux.at(4) = rhs.at(3);
			rhs = aux;
			bool eq = true;
			for (int i = 0; i < 6; ++i) {
				if (lhs.at(i) != rhs.at(i)) eq = false;
			}
			perms.push_back(rhs);
			if (eq == true) return true;
		}
		if (k == 3) {
			aux = rhs;
			aux.at(1) = rhs.at(4);
			aux.at(2) = rhs.at(1);
			aux.at(3) = rhs.at(2);
			aux.at(4) = rhs.at(3);
			rhs = aux;
		}
	}
	//cerr << '\n';
	for (auto perm : perms) {
		for (int i = 0; i < 6; ++i) {
			//cerr << perm.at(i) << ' ';
		}
		//cerr << '\n';
	}
	//cerr << '\n';
	//cerr << "false\n";
	return false;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<array<int, 6>> cube;
		for (int i = 0; i < n; ++i) {
			array<int, 6> aux;
			for (int j = 0; j < 6; ++j) {
				cin >> aux.at(j);
			}
			auto it = cube.begin();
			for (;it != cube.end(); ++it) {
				if (are_same(*it, aux)) break;
			}
			if (it == cube.end()) {
				cube.push_back(aux);
			}
		}
		cout << cube.size() << '\n';
	}

	return 0;
}
