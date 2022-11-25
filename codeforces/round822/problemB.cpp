#include <iostream>
#include <cstdio>

int main () {
	int t;
	
	scanf("%d", &t);
	
	int n[t];
	
	for (int i = 0; i < t; i++) {
		scanf("%d", &n[i]);
	}
	
	for (int i = 0; i < t; i++) {
		printf("1\n");
		for (int j = 1; j < n[i]; j++) {
			printf("1 ");
			for (int k = 1; k < j; k++) {
				printf("0 ");
			}
			printf("1\n");
		}
	}

	return 0;
}
