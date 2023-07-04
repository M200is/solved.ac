#include <stdio.h>

int zero_cnt[41];
int one_cnt[41];

int main() {
    int t, n, i;
    zero_cnt[0] = 1;
    zero_cnt[1] = 0;
    one_cnt[0] = 0;
    one_cnt[1]= 1;
    for(i=2;i<=40;i++) {
        zero_cnt[i] = zero_cnt[i-1] + zero_cnt[i-2];
    	one_cnt[i] = one_cnt[i-1] + one_cnt[i-2];
    }
    scanf("%d", &t);
	for(i=0;i<t;i++) {
		scanf("%d", &n);
        printf("%d %d\n", zero_cnt[n], one_cnt[n]);
    }
}
