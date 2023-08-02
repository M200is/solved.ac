#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int n, m;
int map[9][9];
int visit[9][9];
int cnt;
int dx[]= {0,0,1,-1};
int dy[] = {1,-1,0,0};
int virus;
int wall;
vector<pair<int, int>> way;
int result=-1;

int bfs() {
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            visit[i][j]=0;
        }
    }
    int c = virus;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(map[i][j]==2) {
                q.push({i,j});
            }
        }
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && visit[nx][ny]==0 && map[nx][ny]==0) {
                q.push({nx,ny});
                visit[nx][ny]=1;
                c++;
            }
        }
    }
    return n*m-(c+wall+3);
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> map[i][j];
            if(map[i][j]==2) {
                virus++;    
            }
            else if(map[i][j]==1) {
                wall++;
            }
            else {
                way.push_back({i,j});
            } 
        }
    }
    for(int i=0;i<way.size();i++) {
        for(int j=i+1;j<way.size();j++) {
            for(int k=j+1;k<way.size();k++) {
                map[way[i].first][way[i].second] = 1;
                map[way[j].first][way[j].second] = 1;
                map[way[k].first][way[k].second] = 1;
                result = max(result, bfs());
                map[way[i].first][way[i].second] = 0;
                map[way[j].first][way[j].second] = 0;
                map[way[k].first][way[k].second] = 0;
            }
        }
    }
    cout << result;
}