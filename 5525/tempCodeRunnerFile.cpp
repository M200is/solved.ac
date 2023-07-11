#include <iostream>
#include <string>

using namespace std;

int main() {
    int i, j, n, m;
    int cnt = 0;
    int temp_cnt = 0;
    string temp_str = "O";
    string s;
    cin >> n >> m >> s;
    for(i=0;i<m;i++) {
        if((s[i]=='I' && s[i]!=temp_str[0]) || s[i]=='O' && s[i]!=temp_str[0]) {
            temp_cnt++;
            temp_str[0]=s[i];
        }
        else if(temp_cnt>=n*2+1) {
            cnt+= temp_cnt - (2*n+1);
            temp_str ='O';
            temp_cnt =0;
        }
    }
    cout << cnt;
}