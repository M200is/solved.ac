#include <bits/stdc++.h>

using namespace std;

int R, C;
int result;
bool visited[30];
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

int d[21][21];
char gamemap[21][21];

void dfs(int x, int y, int cnt) {
    result = max(result, cnt);
    for(int i=0;i<4;i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && nx<R && ny>=0 && ny<C) {
            if(visited[gamemap[nx][ny]-'A'] == false) {
                visited[gamemap[nx][ny]-'A'] = true;
                dfs(nx, ny, cnt+1);
                visited[gamemap[nx][ny]-'A'] = false;
            }
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
    visited[gamemap[0][0]-'A'] = true;
    dfs(0,0,1);
    cout << result;
}