#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int n, m;
vi pil;

// bool dab indica se quem vai jogar é o dabriel
bool solve(bool dab) {
	bool best_sol = !dab;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= pil.at(i); ++j) {
			pil.at(i) -= j;
			if (solve(!dab) == dab) best_sol = dab;
			pil.at(i) += j;
		}
	}
	return best_sol;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	pil.resize(n);

	for (int &x : pil) { cin >> x; }

	cout << (solve(true) ? "Possivel" : "Impossivel") << '\n';

	return 0;
}
