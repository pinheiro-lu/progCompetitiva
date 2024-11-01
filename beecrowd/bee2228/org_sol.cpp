#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<bool>> dp;

vector<int> a;
int n;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x, y;
	int cnt = 1;
	cin >> x >> y >> n;
	while (x || y || n) {
		a.resize(n+1);

		int sum = x + y;

		for (int i = 1; i <= n; ++i) {
			cin >> a.at(i);
			sum += a.at(i);
		}

		cout << "Teste " << cnt++ << '\n';
		dp.assign(n+1, vector<bool>(max(0, sum/2-x)+1, false));

		for (int i = 0; i <= n; ++i) {
			dp.at(i).at(0) = true;
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= sum/2-x; ++j) {
				dp.at(i).at(j) = dp.at(i-1).at(j);
				if (j >= a.at(i)) {
					dp.at(i).at(j) = dp.at(i).at(j) || dp.at(i-1).at(j-a.at(i));
				}
			}
		}

		if (dp.at(n).at(sum/2-x) && sum % 2 == 0) {
			cout << "S\n\n";
		} else {
			cout << "N\n\n";
		}

		cin >> x >> y >> n;
	}

	return 0;
}

