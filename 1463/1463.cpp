#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int cnt[1000000];

int main() {
    int i, n;
    scanf("%d", &n);
    for(i=2;i<=n;i++) {
        cnt[i]=cnt[i-1]+1;
        if(i%2==0) {
            cnt[i]=min(cnt[i], cnt[i/2]+1);
        }
        if(i%3==0) {
            cnt[i]=min(cnt[i], cnt[i/3]+1);
        }
    }
    printf("%d", cnt[n]);
}