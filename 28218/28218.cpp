#include <bits/stdc++.h>

using namespace std;

char gamemap[302][302];
int turnlist[301][301];
int n, m, k;
bool c=false;

int setting(int startx,int starty){
    c = false;
    if(gamemap[startx][starty+1]!='#' && turnlist[startx][starty+1] ==0)
        turnlist[startx][starty+1] = turnlist[startx][starty]+1;
    if(gamemap[startx+1][starty]!='#'&& turnlist[startx+1][starty] ==0)
        turnlist[startx+1][starty] = turnlist[startx][starty]+1;
    
    for(int i=1;i<=k;i++) {
        if(startx+i >n || starty+i>m) {
            //cout << "!!!!!!!!!!!!!!!!!!\n";
            return -1;
        }
        if(gamemap[startx+i][starty+i]!='#'&& turnlist[startx+i][starty+i] ==0) {
            turnlist[startx+i][starty+i]=turnlist[startx][starty]+1;
        }
    }
    for(int i=k;i>=0;i--) {
        if(i==0) {
            c = true;
            return startx;
        }
        if(turnlist[startx+i][starty+i]==turnlist[startx][starty]+1)
            return startx+i;
        
    }
}

int main() {
    cin >> n >> m >> k;
    bool check = true;
    int s=0;
    int cnt =1;
    int x[300], y[300];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> gamemap[i][j];
        }
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++) {
        cin >> x[i] >> y[i];
    }
    turnlist[0][0]=0;
    int temp;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(turnlist[i][j]!=0 || (i==0 && j==0)) {
                temp = setting(i,j);
            }
        }
    }
    /*
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << turnlist[i][j] << " ";
            }
        cout << "\n";
    }*/
    //cout << "||||||||||||||||||||||\n";
    //cout << "--------\n";
    for(int i=0;i<q;i++) {
        if((turnlist[n-1][m-1]-turnlist[x[i]-1][y[i]-1])%2 == 0) {
            cout << "Second\n";
        }
        else {
            cout << "First\n";
        }
    }
}