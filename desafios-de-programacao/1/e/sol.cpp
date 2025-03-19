#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 50;

array<int, N> a;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a.at(i);
	}

	vector<int> revans;
	for (int i = n-1; i >=0; --i) {
		if (find(revans.begin(), revans.end(), a.at(i)) == revans.end()) revans.push_back(a.at(i));
	}
	cout << revans.size() << '\n';
	for (auto it = revans.rbegin(); it != revans.rend(); ++it) {
		cout << *it << ' ';
	}



	return 0;
}
