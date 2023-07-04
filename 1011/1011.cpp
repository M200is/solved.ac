#include <stdio.h>
#include <math.h>

int solve(int l) {
	int a = sqrt(l);
	int move;
	if(pow(a, 2) == l) {
		move = a*2-1;
	}
	else {
		move = a*2;
	}
	if(l > a*(a+1)) {
		move = a*2+1;
	}
	return move;
}



int main() {
	int t, x[1001], y[1001], i;
	scanf("%d", &t);
	for(i=0;i<t;i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	for(i=0;i<t;i++) {
		printf("%d\n", solve(y[i]-x[i]));
	}
}
