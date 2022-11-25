#include <stdio.h>
#include <stdlib.h>

#define dbg(args...) //printf(args);
#define dbgi(args) printf(#args); printf(" = %ld\n", args);
#define dbgf(args) printf(#args); printf(" = %lf\n", args);

typedef long long ll;
typedef int bool;

#define true 1
#define false 0

typedef struct {
	int x;
	int i;
} Y;

int comp (const void * a, const void * b){
	if (((Y*) a)->x < ((Y*)b)->x) return -1;
	if (((Y*) a)->x > ((Y*)b)->x) return 1;
	return 0;
} 

void solve(int m) {
	Y y[m];

	for (int i = 0; i < m; i++) {
		scanf("%d", &y[i].x);
		y[i].i = i;
	}

	qsort((void *)y, m, sizeof (Y) , comp);

	for (int i = 0; i < m; i++) {
		printf("%d-%d ", y[i].x, y[i].i);
	} 
	printf ("\n");
}

int main () {
	
	int t, m;
	
	scanf("%d %d", &t, &m);
	
	while (t--)
		solve(m);
		
	return 0;
}
