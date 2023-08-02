#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, Q;

vector<pair<int, long long>> video[5001];
int d[5001];

int bfs(int k, int v) {
    bool visit[5001]={0};
    visit[v]=true;
    int cnt = 0;
    queue<pair<int, long long>> q;
    q.push({v,k});
    while(!q.empty()) { 
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();
        for(int i=0;i<video[now].size();i++) {  
            int next = video[now][i].first;
            int next_cost = video[now][i].second;
            if(!visit[next] && next_cost>=k) {
                visit[next]=1;
                cnt++;
                q.push({next, next_cost});
            }
        }
    }
    return cnt;
}

int main() {
    cin >> N >> Q;
    int k, v;
    for(int i=0;i<N-1;i++) {
        int p,q,r;
        cin >> p >> q >> r;
        video[p].push_back(make_pair(q,r));
        video[q].push_back(make_pair(p,r));
    }
    for(int i=0;i<Q;i++) {
        cin >> k >> v;
        cout << bfs(k,v) << "\n";
    }
}