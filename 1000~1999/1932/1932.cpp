#include <bits/stdc++.h>

using namespace std;

int list_[501][501];
int sum_[501][501];
int result[501];

int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cin >> list_[i][j];
            sum_[i][j] = list_[i][j];
        }
    }
    //sum[2][1]+=
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            if(j==1) {
                sum_[i][j]+=sum_[i-1][j];
            }
            else
                sum_[i][j]+=max(sum_[i-1][j], sum_[i-1][j-1]);
        }
        /*
        cout << "\n";
        for(int j=1;j<=i;j++) {
            cout << sum_[i][j] << " ";
        }
        cout << "\n";
        */
    }

    sort(sum_[n], sum_[n]+n+1);
    cout << sum_[n][n];
}