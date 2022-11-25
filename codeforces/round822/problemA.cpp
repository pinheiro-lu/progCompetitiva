#include <iostream>
#include <cstdio>
#include <climits>

void swap (int * a, const int i, const int j)
{
    int k = a[i];
    a[i] = a[j];
    a[j] = k;
}

int partition (int * a, int s, int e) {
	int j = s;
	
	for (int i = s; i < e; i++) {
		if (a[i] <= a[e]) {
			swap(a, j++, i); 
		} 	
	}
	swap(a, j, e);
	return j;
}

void sort (int * a, int s, int e) {
	if (s >= e) return;
	
	int pivot = partition (a, s, e);
	
	sort(a, s, pivot-1);
	sort(a, pivot+1, e);
}

int qtd(int n, int m, int p) {
	return p - n;
}

int min (int * a, int n) {
	int min, aux = INT_MAX;
	
	min = aux;
	
	for (int i = 0; i < n-2; i++) {
		aux = qtd(a[i], a[i+1], a[i+2]);
	//	printf("aux: %d\n", aux);
		if (aux < min) min = aux; 
	}
	return min;
}

int main () {
	int t;
	
	scanf("%d", &t);
	
	int n[t];
	int * a[t];
	
	for (int i = 0; i < t; i++) {
		scanf("%d", &n[i]);
		a[i] = (int *) malloc(sizeof(int)*n[i]);
		for (int j = 0; j < n[i]; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	for (int i = 0; i < t; i++) {
		sort(a[i], 0, n[i]-1);
	/*	for (int j = 0; j < n[i]; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n"); */
		printf("%d\n", min(a[i], n[i]));
	}	

	return 0;
}
