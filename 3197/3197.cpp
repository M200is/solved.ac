#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
    int x;
    int y;
}cord;


int dx[]={0,0,1,-1};
int r, c;
int dy[]={1,-1,0,0};
int parent[1500*1500];
int swan[2][2];
char char_map[1500][1500];
int int_map[1500][1500];
queue<cord> q_lake, q_melt;

int union_find(int x) {
    if(parent[x]==x) 
        return x;
    return parent[x]=union_find(parent[x]);
}


void union_merge(int x, int y) {
    x=union_find(x);
    y=union_find(y);
    if(x==y) 
        return  ;
    parent[x]=y;
}

bool check(int x, int y) {
    if(x>=0 && x<r && y>=0 && y<c)
        return true;
    return false;
}

void bfs() {
    while(!q_lake.empty()) {
        int x = q_lake.front().x;
        int y = q_lake.front().y;
        q_melt.push({x,y});
        q_lake.pop();
        for(int i=0;i<4;i++) {
            int x_= x+dx[i];
            int y_ = y+dy[i];
            if(check(x_,y_)) {
                if(int_map[x_][y_]>0 && int_map[x][y] != int_map[x_][y_]) {
                    union_merge(int_map[x_][y_], int_map[x][y]);
                }
            }
        }
    }
}


void melt() {
    while(!q_melt.empty()) {
        int x = q_melt.front().x;
        int y = q_melt.front().y;
        q_melt.pop();
        for(int i=0;i<4;i++) {
            int x_= x+dx[i];    
            int y_ = y+dy[i];
            if(check(x_,y_)) {
                if(int_map[x_][y_]==0) {    //얼음이면
                    int_map[x_][y_]=int_map[x][y];
                    q_lake.push({x_,y_});
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &r, &c);
    int temp=0;
    int cnt=0;
    for(int i=0;i<r;i++) {
        scanf("%s", char_map[i]);
        for(int j=0;j<c;j++) {
            if(char_map[i][j]=='L') {
                swan[temp][0]=i;
                swan[temp][1]=j;
                temp++;
            }
            if(char_map[i][j]=='L' || char_map[i][j]=='.') {
                int_map[i][j]=cnt;
                parent[cnt]=cnt;
                cnt++;
                q_lake.push({i,j});
            }
        }
    }
    /*for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            printf("%d ", int_map[i][j]);
        }
        printf("\n");
    }*/
    int result=0;
    while(1) {
        bfs();
        if(union_find(int_map[swan[0][0]][swan[0][1]])== union_find(int_map[swan[1][0]][swan[1][1]])) {
            printf("%d", result);
            return 0;
        }
        melt();
        result++;
    }
}
