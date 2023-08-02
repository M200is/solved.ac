#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int,int>> graph[1001];
bool visit[1001];
vector<int> d;

void solve(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start]=0;
    while(!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(d[now]<dist)
            continue;
        for(int i=0;i<graph[now].size();i++) {
            int cost = dist+graph[now][i].second;
            if(cost<d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }

}

int main() {
    int a, b, c;
    cin >>n >> m;
    int from, to;
    for(int i=0;i<m;i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    cin >> from >> to;
    d.assign(n+1, INT_MAX);
    solve(from);
    cout << d[to];
}