#include <iostream>

using namespace std;


int dp[101][100001];

int main() {
    int n, k, w[101], v[101];
    cin >> n >> k;
    for(int i=1;i<=n;i++) {
        cin >> w[i] >> v[i];
    }
    for(int i=1;i<=n;i++) {
        for(int j =1;j<=k;j++) {
            if(w[i]<=j) {
                if((v[i]+dp[i-1][j-w[i]])>dp[i-1][j]) {
                    dp[i][j]=v[i]+dp[i-1][j-w[i]];
                }
                else {
                    dp[i][j]=dp[i-1][j];
                }
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout << dp[n][k];
}