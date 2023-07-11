#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> graph[100000];

int solve(int start, int end) {
    int cnt=0;
    int a = start;
    int i;
    for(i=start;i<=end;i++) {
        while(!graph[a].empty()) {
            sort(graph[a].begin(), graph[a].end());
            if(a==graph[a][0]) {
                cnt++;
                break;
            }
            a = graph[a][0];
            cnt++;
        }
        a++;
    }
    return cnt;
}


int main() {
    int n, i, a, b;
    int result=-1;
    int start = 2147483647;
    int end = -1;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d %d", &a, &b);
        if(start>a) {
            start = a;
        }
        if(end<a) {
            end = a;
        }
        graph[a].push_back(b);
    }
    for(i=start;i<=end;i++) {
        result = max(result, solve(i, end));
        //printf("[%d]\n", solve(i,end));
    }
    printf("%d", result);
}