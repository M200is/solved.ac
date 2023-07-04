#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main() {
	int n, m, list[10]={0}, t, cnt, arr[8], check=1, minimum;
	int i,j;
	scanf("%d\n%d", &n,&m);
	minimum = abs(100-n);
	for(i=0;i<m;i++) {
		scanf("%d", &t);
		list[t]=-1;
	}
	t=n;
	while (t>0) {	
    	arr[cnt]= t%10;
        t /= 10;
        cnt++;
    }
    if(n==0) {
		arr[0]=0;
	}
	for(i=0;i<=999999;i++) {
		t=i;
		while (t != 0) {	
    		if(list[t%10]==-1) {
    			check=0;
				break;
			}
        	t /= 10;
    	}
    	if(check==0 || (i==0 && list[i]==-1)) {
    		check=1;
    		continue;
		}
		else {
			cnt=0;
			t=i;
			while (t>0) {	
       			t /= 10;
        		cnt++;
    		}
    		if(i==0) {
    			minimum = min(minimum, abs(i-n)+1);
			}
			else {
				minimum = min(minimum, abs(i-n)+cnt);	
			}
		}
	}
	printf("%d", minimum);
}
