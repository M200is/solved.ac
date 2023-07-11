#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int price[1001][3];
int result[1001][3];

int main() {
    int n;
    cin >> n;
    int i, j;
    int temp=-1;
    int cnt=0;
    int list[3];
    for(i=1;i<=n;i++ ) {
        cin >> price[i][0] >> price[i][1] >> price[i][2];
    }
    for(i=1;i<=n;i++) {
        result[i][0] = min(result[i-1][1], result[i-1][2]) + price[i][0];
        result[i][1] = min(result[i-1][0], result[i-1][2]) + price[i][1];
        result[i][2] = min(result[i-1][1], result[i-1][0]) + price[i][2];
    }
    cout << min(result[n][2], min(result[n][0], result[n][1]));
}