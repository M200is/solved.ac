#include <bits/stdc++.h>

using namespace std;

int R, C;
int cnt=0;
char visited[30];
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

int d[21][21];
char gamemap[21][21];

void dfs(int x, int y) {
    if(x!=0 || y!=0) {
        if(strchr(visited, gamemap[x][y]))
        return;
    }
    visited[cnt]=gamemap[x][y];
    cnt++;
    for(int i=0;i<4;i++) {
        int x_ = x+dx[i];
        int y_ = y+dy[i];
        if((x_>=0 && x<R) && (y_>=0 && y_<C) && strchr(visited, gamemap[x_][y_])==NULL) {
            dfs(x_,y_);
        }
    }
}

int main() {
    string temp;
    cin >> R >> C;
    for(int i=0;i<R;i++) {
        cin >> temp;
        for(int j=0;j<C;j++) {
            gamemap[i][j] = temp[j];
        }
    }
    dfs(0,0);
    cout << cnt;
}