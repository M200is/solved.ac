#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;


vector<int> w[102];
int cnt[102];
int result[102];
bool visit[102];
int min_=100000;
int m;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visit[start]= true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=0;i<w[x].size();i++) {
            int y = w[x][i];
            if(!visit[y]) {
                q.push(y);
                visit[y]=true;
                cnt[y]+=cnt[x]+1;
            }
        }
    }
}


int main() {
    int n, m, a, b;
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=0;i<m;i++) {
        scanf("%d %d", &a, &b);
        w[a].push_back(b);
        w[b].push_back(a);
    }
    for(i=1;i<=n;i++) {
        bfs(i);
        for(j=1;j<=n;j++) {
            if(i==j) {
                continue;
            }
            else {
                result[i]+=cnt[j];
            }
        }
        memset(visit, false, sizeof(visit));
        memset(cnt, 0, sizeof(cnt));
    }
    for(i=1;i<=n;i++) {
        if(result[i]<min_) {
            min_ = result[i];
            m=i;
        }
    }
    printf("%d",m);
}