#include <bits/stdc++.h>

using namespace std;

int list_[3];
int n;
int dp[4][3];

int main() {
    cin >> n;
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
    dp[1][0]=dp[0][0];
    dp[1][1]=dp[0][1];
    dp[1][2]=dp[0][2];
    for(int i=1;i<n;i++) {
        cin >> list_[0] >> list_[1] >> list_[2];
        int t0=dp[0][0],t1 = dp[0][1], t2=dp[0][2];
        dp[0][0] = max(t1,t1) + list_[0];
        dp[0][2] = max(t1,t2) + list_[2];
        dp[0][1] = max(max(t1,t0), t2) + list_[1];
        t0 = dp[1][0];
        t1 = dp[1][1];
        t2 = dp[1][2];
        dp[1][0] = min(t0, t1) + list_[0];
        dp[1][2] = min(t1, t2) + list_[2];
        dp[1][1] = min(min(t1,t0), t2) + list_[1];   
    }
    cout <<  max(max(dp[0][1], dp[0][0]), dp[0][2]) << " " << min(min(dp[1][1], dp[1][0]), dp[1][2]);
}