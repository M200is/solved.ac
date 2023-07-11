#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int tomato[1001][1001];

int dx[6]={0,0,1,-1};
int dy[6]={1,-1,0,0};

int cnt;
int m, n, h;
queue<pair<int, int>> q;

bool all_check() {
    int i, j;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(tomato[i][j]==0) {
                return false;
            }
        }
    }
    return true;
}


void bfs() {
    while(!q.empty()) {
        int size = q.size();
        for(int i=0;i<size;i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int j=0;j<4;j++) {
                int x_ = x+dx[j];
                int y_ = y+dy[j];
                if(x_>=0 && x_<n && y_>=0 && y_<m) {
                    if(tomato[x_][y_]==0) {
                        tomato[x_][y_]=1;
                        q.push(make_pair(x_,y_));
                    }
                }
            }
            if(q.size()==0 && all_check()) {
                cout << cnt << "\n";
                return;
            }
            else if(q.size()==0 && !all_check()) {
                cout <<-1 << "\n";
                return;
            }
        }
        cnt++;
    }
}


int main() {
    int i, j;
    bool only = true;
    cin >> m >> n;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            scanf("%d", &tomato[i][j]);
            if(tomato[i][j]==1) {
                q.push(make_pair(i,j));
                only = false;
            }
        }
    }      
    if(only) {
        printf("-1\n");
    }
    else if(all_check()) {
        printf("0");
    }
    else {
        bfs();
    }
}