#include <bits/stdc++.h>

using namespace std;

struct Coord {
	int x;
	int y;
};

bool operator<(const Coord & lhs, const Coord & rhs) {
	return lhs.y < rhs.y;
}

int main() {
	int n;

	cin >> n;

	Coord a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}

	sort(a, a + n);

	return 0;
}



