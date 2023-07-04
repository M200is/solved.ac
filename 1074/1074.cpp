#include <stdio.h>
#include <algorithm>

using namespace std;

int n, r, c, result=0;

void Z(int y, int x, int size) {
	if(y==r && x == c) {
		printf("%d", result);
		return;
	}
	if(r<y+size && r>=y && c<x+size && c>= x) {
		// 1사분면
    	Z(y, x, size / 2);
	    // 2사분면
    	Z(y, x + size / 2, size / 2);
    	// 3사분면
		Z(y + size / 2, x, size / 2);
    	// 4사분면
    	Z(y + size / 2, x + size / 2, size / 2);
	}
	else {
    	result += size * size;
	}
}

int main() {
	scanf("%d %d %d", &n, &r, &c);
	Z(0,0,(1<<n));
}
