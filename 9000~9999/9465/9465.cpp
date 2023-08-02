#include <bits/stdc++.h>

using namespace std;

int list_[2][200001];
int dp[2][200001];

int main() {
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++) {
        cin >> n;
        for(int j=0;j<2;j++) {
            for(int k=1;k<=n;k++) {
                cin >> list_[j][k];
            }
        }
        dp[0][0] = dp[1][0]=0;
        dp[0][1] = list_[0][1];
        dp[1][1] = list_[1][1];
        for(int i=0;i<=n;i++) {
            dp[0][i]=max(dp[1][i-1], dp[1][i-2]) + list_[0][i];
            dp[1][i]=max(dp[0][i-1], dp[0][i-2]) + list_[1][i];
        }
        cout << max(dp[0][n], dp[1][n]) << "\n";
    }
}