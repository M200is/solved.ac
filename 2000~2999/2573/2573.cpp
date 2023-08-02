#include <iostream>
#include <queue>

using namespace std;

int map[301][301];
int n,m;
int dx[]={0,0,1,-1};
int dy[]= {1,-1,0,0};

int bfs(int a, int b) {
    int visited[301][301]= {0};
    queue<pair<int,int>> q;
    visited[a][b]=1;
    q.push({a,b});
    int cnt = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && map[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny]=1;
                q.push({nx,ny});
                cnt++;
            }
        }
        //printf("[%d]\n", cnt);
    }
    return cnt;
}

void melt() {
    int melt_cnt[301][301] = {0};
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(map[i][j]!=0) {
                for(int k=0;k<4;k++) {
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && map[nx][ny]==0) {
                        melt_cnt[i][j]++;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(map[i][j]!=0) {
                map[i][j]-=melt_cnt[i][j];
                if(map[i][j]<=0) {
                    map[i][j]=0;
                }
            }
        }
    }
}

int main() {
    pair<int,int> s;
    int ice_cnt=0;
    int result =0;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> map[i][j];
            if(map[i][j]!=0) {
                ice_cnt++;
                s.first = i;
                s.second = j;
            }
        }
    }
    while(1) {
        if(bfs(s.first, s.second)!=ice_cnt) {
            cout << result;
            break;
        }
        ice_cnt =0;
        melt();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(map[i][j]!=0) {
                    ice_cnt++;
                    s.first = i;
                    s.second = j;
                }
            }
        }
        if(ice_cnt == 0) {
            cout << 0;
            break;
        }
        result++;
    }
    
}