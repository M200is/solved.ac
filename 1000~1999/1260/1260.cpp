#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool visit1[1002];
bool visit2[1002];
vector<int> w[10002];

int  n, m, v;

int dfs(int x) {
	visit1[x]= 1;
	printf("%d ", x);
	for(int i=0;i<w[x].size();i++) {
		int y = w[x][i];
		if(visit1[y]==0) {
			dfs(y);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit2[start]=1;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for(int i=0;i<w[x].size();i++) {
			int y = w[x][i];
			if(visit2[y]==0) {
				q.push(y);
				visit2[y]=1;
			}
		}
	}
}

int main() {
	int v1, v2, i;
	scanf("%d %d %d", &n, &m, &v);
	for(i=0;i<m;i++) {
		scanf("%d %d", &v1, &v2);
		w[v1].push_back(v2);
		w[v2].push_back(v1);
	}
	for(int i=1;i<=n;i++){
        sort(w[i].begin(), w[i].end());
    }
    
	dfs(v);
	printf("\n");
	bfs(v);
	return 0;
}
