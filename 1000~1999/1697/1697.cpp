#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int,int>> q;
int result;
int n, k;
bool visit[100001];

bool valid(int n) {
	if (n < 0 || n > 100000 || visit[n])
		return false;
	return true;
}


void bfs(int start) {
    while (!q.empty()) {
        int data = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(data == k) {
            result = depth;
            break;
        }
        if(valid(data-1)) {
            visit[data-1] = true;
            q.push({data-1, depth+1});
        }
        if(valid(data+1)) {
            visit[data+1] = true;
            q.push({data+1, depth+1});
        }
        if(valid(data*2)) {
            visit[data*2] = true;
            q.push({data*2, depth+1});
        }
    }
}


int main() {
    cin >> n >> k;
    q.push({n, 0});
    visit[n]= true;
    bfs(n);
    cout << result;
    return 0;
}