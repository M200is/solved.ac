#include <iostream>
#include <string>

using namespace std;


int main() {
    int i, j, n, m;
    int cnt = 0;
    string s;
    cin >> n >> m >> s;
    int result = 0;
    for(int i= 0;i<m;i++) {
        int cnt=0;
        if(s[i]== 'O') {
            continue;
        }
        else {
            while(s[i+1]== 'O' && s[i+2]== 'I') {
                cnt++;
                if(cnt==n) {
                    cnt--;
                    result++;
                    
                }
                i+=2;
            }
            cnt = 0;
        }
    }
    cout << result;
}