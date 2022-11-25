#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main () {
	int t;
	
	scanf("%d", &t);
	
	int n[t];
	int c[t];
	int * a[t];
	int aux;
	int r[t];
	
	for (int i = 0; i < t; i++) {
		r[i] = 0;
		scanf("%d %d", &n[i], &c[i]);
		//printf("n: %d\n", n[i]);
		a[i] = (int*) malloc(sizeof(int)*n[i]);
		for (int j = 0; j < n[i]; j++) {
			scanf("%d", &a[i][j]);
		}
	//	printf("n: %d\n", n[i]);
		sort (a[i], a[i]+n[i]);
	//	printf("Sorted!\n");
	//	printf("n: %d\n", n[i]);
		aux = 1;
		for (int j = 0; j < n[i]-1; j++) {
	//		printf("j : %d; elemento: %d\n", j, a[i][j]);
			if (a[i][j] == a[i][j+1]) aux++;
			else {
				if (aux >= c[i]) r[i]+=c[i];
				else r[i]+=aux;
				aux = 1;
			}
		}
		if (aux >= c[i]) r[i]+=c[i];
				else r[i]+=aux;
	}
	
	for (int i = 0; i < t; i++) {
		printf("%d\n", r[i]);
	}
	

	return 0;
}
