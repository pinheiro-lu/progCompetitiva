#include <bits/stdc++.h>

using namespace std;

int main() {
	int v[] = {1, 2, 3 , 4 , 5 , 6 , 7 , 8};
	int k = 3;
    const int n = 8;

	vector<bool> b(n);

	for (int i = n-1; k; --k, --i) {
		b[i] = true;
	}
	

	do {
		for (int i = 0; i < n; ++i) {
			if (b[i]) cout << v[i]  << " ";
		}
		cout << '\n';
	} while (next_permutation(b.begin(), b.end()));

	return 0;
}
