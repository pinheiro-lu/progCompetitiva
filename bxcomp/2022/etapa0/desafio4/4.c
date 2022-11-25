#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define dbg(args...) printf(args);
#define dbgi(args) //printf(#args); printf(" = %ld\n", args);
#define dbgf(args) printf(#args); printf(" = %lf\n", args);

typedef long long ll;

int min (int a, int b) {
	if (a < b) return a;
	return b;
}

int max (int a, int b) {
	if (a > b) return a;
	return b;
}

void solve() {
	int a[5][5];
	int x1, y1, x2, y2;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == -1) {
				x1 = i;
				y1 = j;
			}
			if (a[i][j] == -2) {
				x2 = i;
				y2 = j;
			}
		}
	}

	if (x1 == x2) {
		for (int i = min(y1, y2) + 1; i < max(y1, y2); i++) {
			if (a[x1][i] > 175) {
				puts("Oopa, nao vai dar nao.");
				return;
			}
		}
		puts("Por aqui Blu!");
		return;
	}

	if (y1 == y2) {
		for (int i = min(x1, x2) + 1; i < max(x1, x2); i++) {
			if (a[i][y1] > 175) {
				puts("Oopa, nao vai dar nao.");
				return;
			}
		}
		puts("Por aqui Blu!");
		return;
	}

	int dx = x2 - x1, dy = y2 - y1;

	if (abs(dx) != abs(dy)) {
		puts("Oopa, nao vai dar nao.");
		return;
	}

	int temp;

	if (min (x1, x2) == x2) {
		temp = y2;
		y2 = y1;
		y1 = temp;
	}

	for (int i = min (x1, x2) + 1, j = y1 + 1; j < y2; j++, i++) {
		dbgi (i) dbgi(j) 
		if (a[i][j] > 175) {
			puts("Oopa, nao vai dar nao.");
			return;
		}
	}
	for (int i = min (x1, x2) + 1, j = y1 - 1; j > y2; j--, i++) {
		dbgi (i) dbgi(j) 
		if (a[i][j] > 175) {
			puts("Oopa, nao vai dar nao.");
			return;
		}
	}

	puts ("Por aqui Blu!");
	
}

int main () {
	
	int t;
	
	scanf("%d", &t);
	
	while (t--)
		solve();
		
	return 0;
}
