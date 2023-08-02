#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int,int>>> graph;
vector<int> dist;
int n, m, w;

string bellman_ford() {
    dist[1] = 0;
    for(int i=1;i<n;i++) {
        for(int j=0;j<graph.size();j++) {
            int from = graph[j].first;
            int to  = graph[j].second.first;
            int cost = graph[j].second.second;
            if(dist[to]>dist[from]+cost) {
                dist[to]=dist[from]+cost;
            }
        }
    }
    for(int j=0;j<graph.size();j++) {
        int from = graph[j].first;
        int to  = graph[j].second.first;
        int cost = graph[j].second.second;
        if(dist[to]>dist[from]+cost) {
            return "YES";
        }
    }
    return "NO";
}


int main() {
    int tc;
    int s,e,t;
    cin >> tc;
    for(int i=0;i<tc;i++) {
        cin >> n >> m >> w;
        graph.assign(n+1, {0,{0,0}});
        dist.assign(n+1, 100000);
        for(int j=0;j<m;j++) {
            cin >> s >> e >> t;
            graph.push_back({s,{e,t}});
            graph.push_back({e,{s,t}});
        }
        for(int j=0;j<w;j++) {
            cin >> s >> e >> t;
            graph.push_back({s,{e,-t}});
        }
        cout << bellman_ford() << "\n";
    }
    
}