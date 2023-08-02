#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int T;
int N, K, W;

int main() {
    cin >> T;
    for(int i=0;i<T;i++) {
        int maxtime=-1;
        int time[1001];
        int temp[1001] = {0};
        int result[1001] = {0};
        cin >> N >> K;
        for(int j=1;j<=N;j++) {
            cin >> time[j];
        }
        vector<int> map[1001];
        queue<int> q;
        for(int j=0;j<K;j++) {
            int x, y;
            cin >> x >> y;
            map[x].push_back(y);
            temp[y]++;
        }
        cin >> W;
        for(int i=1;i<=N;i++) {
            if(temp[i]==0) {
                q.push(i);
            }
            result[i] = time[i];
        }
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int i=0;i<map[cur].size();i++) {
                int next = map[cur][i];
                temp[next]--;
                result[next]=max(result[next], result[cur]+time[next]);
                if(temp[next]==0) {
                    q.push(next);
                }
            }
        }
        cout << result[W] << "\n";
    }
}