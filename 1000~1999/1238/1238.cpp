#include <bits/stdc++.h>

#define INF 1e9+7

using namespace std;

vector<pair<int, int>> graph[2][1001];
vector<int> len[2];
int N, M, X;

void solve(int s) {
    len[s][X]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;    //우선순위 큐
    q.push(make_pair(X, 0));
    
    while(!q.empty()) {
        int cur = q.top().first;
        int cost = q.top().second;
        q.pop();
        if(cost > len[s][cur]) {
            continue;
        }
        for(int i=0;i<graph[s][cur].size();i++) {
            int next = graph[s][cur][i].first;
            int next_cost = cost + graph[s][cur][i].second;
            if(next_cost<len[s][next]) {
                len[s][next] = next_cost;
                q.push(make_pair(next, next_cost));
            }
        }
    }
}

int main() {
    int a, b, temp;
    cin >> N >> M >> X;
    for(int i=0;i<M;i++) {
        cin >> a >> b >> temp;
        graph[0][a].push_back(make_pair(b, temp));
        graph[1][b].push_back(make_pair(a, temp));
    }
    len[0].resize(N+1, INF);
    len[1].resize(N+1, INF);
    solve(1);
    solve(0);
    int result =0;
    for(int i=1;i<=N;i++) {
        result = max(result, len[0][i]+len[1][i]);
    }
    cout << result;
}