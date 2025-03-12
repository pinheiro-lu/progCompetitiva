#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		vi c(5);
		vi cnt(14);
		for (int &x : c) {
			cin >> x;
			cnt[x]++;
		}
		priority_queue<pair<int, int>> pq;
		for (int i = 1; i <= 13; ++i) pq.push({cnt.at(i), i});
		sort(c.begin(), c.end());
		bool sorted = true;
		for (int i = 0; i < 5; ++i) {
			if (c.at(i) != c.at(0) + i) sorted = false;
		}

		int score = 0;
		int x;
		auto &[a, b] = pq.top();
		switch (a) {
			case 4:
				score = b + 180;
				break;
			case 3:
				x = b;
				pq.pop();
				if (pq.top().first == 2) {
					score = 160 + x;
				} else {
					score = 140 + x;
				}
				break;
			case 2:
				x = b;
				pq.pop();
				if (pq.top().first == 2) {
					int y = pq.top().second;
					score = 3*max(x, y) + 2 *min(x, y) + 20;
				} else score = x;
				break;
		}

		if (sorted) score = c.at(0) + 200;

		cout << "Teste " << i << '\n';
		cout << score << "\n\n";
	}



	return 0;
}
