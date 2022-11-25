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

void solve(void) {
	
}

int main () {
	
	int t;
	
	scanf("%d", &t);
	
	while (t--)
		solve(m);
		
	return 0;
}
