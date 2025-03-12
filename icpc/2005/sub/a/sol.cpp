#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int n, m;
int v1, v2;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (true) {
		string s;
		cin >> s;
		if (s == "0") break;
		stringstream ss(s);
		ss >> v1;
		char ign;
		ss >> ign;
		ss >> v2;
		int intv = v1 * 100 + v2;
		cin >> n >> m;
		if (n % 10000 == m % 10000) intv *= 3000;
		else if (n % 1000 == m % 1000) intv *= 500;
		else if (n % 100 == m % 100) intv *= 50;
		else if ((n + 99) % 100 / 4 == (m + 99) % 100 / 4) intv *= 16;
		else intv = 0;
		cout << intv / 100 << '.' << setfill('0') << setw(2) << intv % 100 << '\n';
	}


	return 0;
}
