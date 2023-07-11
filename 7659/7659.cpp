#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int tomato[105][105][105];

int dx[6]={0,0,1,-1,0,0};
int dz[6]={1,-1,0,0,0,0};
int dy[6]={0,0,0,0,1,-1};

int cnt;
int m, n, h;
queue<pair<pair<int,int>,int>> q;

bool all_check() {
    int i, j ,k;
    for(k=0;k<h;k++) {
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(tomato[i][j][k]==0) {
                    return false;
                }
            }
        }
    }
    return true;
}


void bfs() {
    while(!q.empty()) {
        int size = q.size();
        for(int i=0;i<size;i++) {
            int x = q.front().first.first;
            int z = q.front().first.second;
            int y = q.front().second;
            q.pop();
            for(int j=0;j<6;j++) {
                int x_ = x+dx[j];
                int y_ = y+dy[j];
                int z_ = z+dz[j];
                if(x_>=0 && x_<n && y_>=0 && y_<h && z_>=0 && z_<m) {
                    if(tomato[x_][z_][y_]==0) {
                        tomato[x_][z_][y_]=1;
                        q.push(make_pair(make_pair(x_,z_),y_));
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
    int i, j, k;
    bool only = true;
    cin >> m >> n >> h;
    for(k=0;k<h;k++) {
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                scanf("%d", &tomato[i][j][k]);
                if(tomato[i][j][k]==1) {
                    q.push(make_pair(make_pair(i,j),k));
                    only = false;
                }
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