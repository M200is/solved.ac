#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main() {
    int n, i, temp;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d", &temp);
        if(temp == 0) {
            if(q.empty()) {
                printf("0\n");
            }
            else {
                printf("%d\n", q.top());
                q.pop();
            }
        }
        else {
            q.push(temp);
        }
    }
}