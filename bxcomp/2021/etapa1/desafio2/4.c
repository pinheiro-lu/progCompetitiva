#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define dbg(args...) printf(args);
#define dbgi(args) dbg(#args) dbg(" = %ld\n", args)
#define dbgf(args) dbg(#args) dbg(" = %lf\n", args)
#define fir(i, a, b) for (int i = (a); i < (b); i++)
#define f0r(i, a) fir(i, 0, a)

typedef long long ll;

int min (int a, int b) {
	if (a < b) return a;
	return b;
}

int max (int a, int b) {
	if (a > b) return a;
	return b;
}

void solve(int m) {
	int a[m];
	int p[2] = {0, 0};

	f0r (i, m) {
		scanf("%d", &a[i]);
	}

	f0r (i, m) {
		if(a[i] & 1) {
			printf("%d ", p[0] + p[1]);
		} else {
			p[1] = p[0];
			p[0] = a[i];
			printf("%d ", a[i] * i);
		}
	}
	puts("");

}

int main () {
	
	int t, m;
	
	scanf("%d %d", &t, &m);
	
	while (t--)
		solve(m);
		
	return 0;
}
