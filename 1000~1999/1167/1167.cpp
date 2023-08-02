#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[100001];
bool visited[100001];
int max_node, max_len;

void dfs(int x, int len) {
    if(visited[x]) {
        return;
    }
    if(max_len<len) {
        max_len = len;
        max_node = x;
    }
    visited[x]=true;
    for(int i =0;i<graph[x].size();i++) {
        int y_node = graph[x][i].first;
        int y_len = graph[x][i].second;
        dfs(y_node, y_len+len);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V;
    cin >> V;
    int a, b, len;
    int check = 1;
    for(int i=0;i<V;i++) {
        cin >> a;
        while(1) {
            cin >> b;
            if(b==-1) {
                break;
            }
            cin >> len;
            graph[a].push_back({b, len});
            graph[b].push_back({a, len});

        }
    }
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    max_len = 0;
    dfs(max_node, 0);
    cout << max_len;
}