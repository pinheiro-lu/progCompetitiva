#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> in(3, vector<int>(2));
vector<vector<char>> ans;

int free_y;
vector<int> free_xs;

bool solved;

void rec(int logo) {
	if (logo == 3) {
		solved = true;
		return;
	}

	int &comp = in.at(logo).at(0);
	int &larg = in.at(logo).at(1);

	vector<int>::iterator free_x = free_xs.begin();

	for (auto &it = free_xs.begin(); it != free_xs.end(); ++it) {
		if (*it + larg <= ans.size()) {
			free_x = it;
			break;
		}
	}


	if (free_y + comp <= ans.at(0).size() && *free_x + larg <= ans.size()) {
		for (int i = free_y; i < comp + free_y; ++i) {
			for (int j = *free_x; j < larg + *free_x; ++j) {
				ans.at(i).at(j) = logo == 0 ? 'A' : logo == 1 ? 'B' : 'C';
			}
		}
		free_y += comp;
		*free_x += larg;

		rec(logo + 1);
		if (solved) return;
		free_y -= comp;
		*free_x -= larg;
	} 

	for (auto &it = free_xs.begin(); it != free_xs.end(); ++it) {
		if (*it + comp <= ans.size()) {
			free_x = it;
			break;
		}
	}

	if (free_y + larg <= ans.at(0).size() && *free_x + comp <= ans.size()) {
		for (int i = free_y; i < larg + free_y; ++i) {
			for (int j = *free_x; j < comp + *free_x; ++j) {
				ans.at(i).at(j) = logo == 0 ? 'A' : logo == 1 ? 'B' : 'C';
			}
		}
		*free_x += comp;
		free_y += larg;

		rec(logo + 1);
		if (solved) return;
		*free_x -= comp;
		free_y -= larg;
	}

}


void solve() {
	int sum = 0;
	for (int i = 0; i < 3; ++i) {
		int aux = 1;
		for (int j = 0; j < 2; ++j) {
			cin >> in.at(i).at(j);
			aux *= in.at(i).at(j);
		}
		sum += aux;
	}

	int side = sqrt(sum);

	ans.resize(side, vector<char>(side));
	free_xs.resize(side);

	rec(0);

	if (!solved) {
		cout << -1 << '\n';
		return;
	}

	cout << side << '\n';

	for (auto &lin : ans) {
		for (char &c : lin) {
			cout << c;
		}
		cout << '\n';
	}

	

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
