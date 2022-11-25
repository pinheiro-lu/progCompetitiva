#include <cstdio>
#include <iostream>

int main() {
	int n, l, d;
	
	scanf("%d %d %d", &n, &l, &d);
	
	float a = (float) d/1000 * n;
	int b = (int) a;
	
	if (a*10000 - b*10000 > 0) {
		b++;
	} 
	
	int r = l;
	
	for (int i = 0; r < b; i++) {
		r += l;
	}
	
	printf("%d\n", r); 

	return 0;
}
