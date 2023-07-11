#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int, int>> q;

bool visit[101][101];
char maze[101][101];
int n, m;
int dx[4]= {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int cnt[101][101];

void bfs() {
    q.push(make_pair(0,0));
    visit[0][0]=true;
    cnt[0][0]=1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();     
        for(int i=0;i<4;i++) {
            int x_ = x+dx[i];
            int y_ = y+dy[i];
            if(x_>=0 && x_<n && y_>=0 && y_<m) {
                if(!visit[x_][y_]&&maze[x_][y_]=='1') {
                    visit[x_][y_]=true;
                    cnt[x_][y_]=cnt[x][y]+1;
                    q.push(make_pair(x_, y_));
                }
            }
        }
    }
}


int main() {
    int i,j;
    cin >> n >> m;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cin >> maze[i][j];
        }
    }
    bfs();
    cout << cnt[n-1][m-1] <<"\n";
}