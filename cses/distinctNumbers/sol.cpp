#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;

	cin >> n;

	unordered_set <int> s;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	cout << s.size() << '\n';

	return 0;
}

