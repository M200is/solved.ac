#include <bits/stdc++.h>

using namespace std;

int cnt[32001];
vector<int> v[32001];
int n, m;

void solve() {
    vector<int> result;
    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(cnt[i]==0) {
            q.push(i);
        }
    }
    while ((!q.empty())) {
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for(int i=0;i<v[cur].size();i++) {
            int next = v[cur][i];
            cnt[next]--;
            if(cnt[next]==0) {
                q.push(next);
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout << result[i] << " ";
    }
}

int main() {
    cin >> n >> m;
    vector<int> temp;
    int a, b;
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        v[a].push_back(b);
        temp.push_back(a);
        cnt[b]++;
    }
    solve();
}