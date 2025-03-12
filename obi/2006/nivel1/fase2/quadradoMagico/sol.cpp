#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

array<array<int, 3>, 3>grid;

int sum = 0;

void solve(int x, int y) {
	int aux = 0, cnt = 0;
	for (int i = 0; i < 3; ++i) {
		aux += grid.at(i).at(y);
		cnt += grid.at(i).at(y) == 0;
	}
	if (cnt == 1) {
		grid.at(x).at(y) = sum - aux;
		return;
	}
	aux = 0, cnt = 0;
	for (int i = 0; i < 3; ++i) {
		aux += grid.at(x).at(i);
		cnt += grid.at(x).at(i) == 0;
	}
	if (cnt == 1) {
		grid.at(x).at(y) = sum - aux;
		return;
	}
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> grid.at(i).at(j);
		}
	}

	for (int i = 0; i < 3; ++i) {
		int aux = 0;
		bool summed = true;
		for (int j = 0; j < 3; ++j) {
			if (grid.at(i).at(j) == 0) summed = false;
			aux += grid.at(i).at(j);
		}
		if (summed) sum = aux;
	}
	for (int i = 0; i < 3; ++i) {
		int aux = 0;
		bool summed = true;
		for (int j = 0; j < 3; ++j) {
			if (grid.at(j).at(i) == 0) summed = false;
			aux += grid.at(j).at(i);
		}
		if (summed) sum = aux;
	}

	int aux = 0;
	bool summed = true;
	for (int i = 0; i < 3; ++i) {
		if (grid.at(i).at(i) == 0) summed = false;
		aux += grid.at(i).at(i);
	}
	if (summed) sum = aux;

	aux = 0;
	summed = true;
	for (int i = 0; i < 3; ++i) {
		if (grid.at(i).at(2-i) == 0) summed = false;
		aux += grid.at(i).at(2-i);
	}
	if (summed) sum = aux;

	bool fim = false;
	while (!fim) {
		for (int i = 0; i < 3; ++i) {
			for (int j =0; j < 3; ++j) {
				if (grid.at(i).at(j) == 0) solve(i, j);
			}
		}
		fim = true;
		for (int i = 0; i < 3; ++i) {
			for (int j =0; j < 3; ++j) {
				if (grid.at(i).at(j) == 0) fim = false;
			}
		}
	}

	if (grid.at(0).at(0) < 0) {
		while (grid.at(0).at(0) + grid.at(0).at(1) + grid.at(0).at(2) != grid.at(0).at(0) + grid.at(1).at(1) + grid.at(2).at(2)) {
			grid.at(0).at(0)++;
			grid.at(1).at(1)++;
			grid.at(2).at(2)++;
		}
	}
	if (grid.at(0).at(2) < 0) {
		while (grid.at(0).at(0) + grid.at(0).at(1) + grid.at(0).at(2) != grid.at(0).at(2) + grid.at(1).at(1) + grid.at(2).at(0)) {
			grid.at(0).at(2)++;
			grid.at(1).at(1)++;
			grid.at(2).at(0)++;
		}
	}
		
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << grid.at(i).at(j) << ' ';
		}
		cout << '\n';
	}

	return 0;
}
