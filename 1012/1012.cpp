#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int,int> > q;

int origin[100][100], visit[100][100], k;
int m,n, k;
int cnt = 0;
int x1[] = {1, -1, 0, 0}, y1[4] = {0,0,1,-1};

void solve(int s_x, int s_y) {
    visit[s_x][s_y]==-1;
    q.push(make_pair(s_x,s_y));


}

int main() {
    int t, i, j, a[100], b[100];
    scanf("%d", &t);
    scanf("%d %d %d", &m, &n, &k);
    for(i=0;i<k;i++) {
        if(i==0)
        scanf("%d", &a[i], &b[i]);
        a[a[i]][b[i]]==1;
        b[a[i]][b[i]]==1;
    }
    solve(a[0], b[0]);
}