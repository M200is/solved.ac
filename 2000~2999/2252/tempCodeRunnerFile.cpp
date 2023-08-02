#include <bits/stdc++.h>

using namespace std;

int cnt[32001];
vector<int> v[32001];

void solve(int start) {
    vector<int> result;
    queue<int> q;
    q.push(start);
    result.push_back(start);
    while ((!q.empty())) {
        int cur = q.front();
        q.pop();
        for(int i=0;i<v[cur].size();i++) {
            int next = v[cur][i];
            cnt[next]--;
            if(cnt[next]==0) {
                q.push(next);
                result.push_back(next);
            }
        }
    }
    for(int i=0;i<result.size();i++) {
        cout << result[i] << " ";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> temp;
    int a, b;
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        v[a].push_back(b);
        temp.push_back(a);
        cnt[b]++;
    }
    for(int i=0;i<n;i++) {
        if(cnt[temp[i]]==0) {
            solve(temp[i]);
        }
    }
}