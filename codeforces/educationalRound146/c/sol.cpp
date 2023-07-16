#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve (){
	int n, s1, s2;
	
	cin >> n >> s1 >> s2;

	vector<int>r(n);

	for (int i : r) {
		cin >> i;
	}

	queue <int> a, b;

	int t1 = s1, t2 = s2;

	for (int i : r) {
		if (t1 < t2) {
			a.push(i);
			t1 += s1;
		} else {
			b.push(i);
			t2+=s2;
		}
	}

	cout << a.size() << ' ';

	while (!a.empty()) {
		cout << a.front() << ' ';
		a.pop();
	}
	cout << '\n';

	cout << b.size() << ' ';

	while (!b.empty()) {
		cout << b.front() << ' ';
		b.pop();
	}

	cout << '\n';

}

int main() {
	int t;

	cin >> t;
	while (t--) solve();

	return 0;
}
