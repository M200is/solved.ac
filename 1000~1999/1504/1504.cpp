#include <bits/stdc++.h>

using namespace std;

#define INF 1e9+7

vector<pair<int, int>> graph[1001];
int dist[1001];
int N, E;

void solve(int start) {
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(int i=0;i<graph[cur].size();i++) {
            int next = graph[cur][i].first;
            int next_cost = cost + graph[cur][i].second;
            if(dist[next]>next_cost) {
                dist[next]=next_cost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int result = -1;
    cin >> N >> E;
    int c, v ,t;    
    bool check[2];
    check[0] = false;
    check[1] = false;
    for(int i=0;i<E;i++) {
        cin >> c >> v >> t;
        graph[c].push_back({v, t});
        graph[v].push_back({c, t});
    }
    int a, b;
    cin >> a >> b;
    for(int i=1;i<=N;i++) {
        dist[i]=INF;
    }
    solve(1);
    int distA = dist[a];
    int distB = dist[b];
    if(distA == INF) {
        check[0] = true;
    }
    if(distB == INF) {
        check[1] = true;
    }
    for(int i=1;i<=N;i++) {
        dist[i]=INF;
    }
    solve(a);
    if(!check[0]) {
        distA += dist[b];
    }
    if(!check[1]) {
        distB += dist[b];
    }
    for(int i=1;i<=N;i++) {
        dist[i]=INF;
    }
    solve(b);
    if(!check[0]) {
        distA += dist[N];
    }
    for(int i=1;i<=N;i++) {
        dist[i]=INF;
    }
    solve(a);
    if(!check[1]) {
        distB += dist[N];
    }
    if(check[0] && check[1]) {
        result = -1;
    }
    else {
        result = min(distA, distB);
    }
    if(result >= INF) {
        result = -1;
    }
    cout << result << "\n";
}