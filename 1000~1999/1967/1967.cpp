#include <bits/stdc++.h>

using namespace std;

int n;
int endnode;
int result;
vector<pair<int,int>> graph[100001];
bool visited[100001];

void dfs(int s, int l) {
    if(visited[s]) {
        return;
    }
    visited[s]=true;
    if(result<l) {
        result = l;
        endnode = s;
    }
    for(int i=0;i<graph[s].size();i++) {
        dfs(graph[s][i].first, l+graph[s][i].second);
    }
}

int main() {
    cin >> n;
    for(int i=0;i<n-1;i++) {
        int a, b, c;
        cin >> a >> b >>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dfs(1,0);
    memset(visited, false, sizeof(visited));
    dfs(endnode, 0);
    cout << result;
}