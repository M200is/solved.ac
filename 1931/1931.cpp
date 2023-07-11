#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<pair<int,int>> graph;


int main() {
    int n, i, a, b, temp;
    int cnt=1;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d %d", &a, &b);
        graph.push_back(make_pair(b, a));
    }
    sort(graph.begin(),graph.end());
    temp = graph[0].first;
    for(i=1;i<n;i++) {
        if(temp<=graph[i].second) {
            cnt++;
            temp = graph[i].first;
        }
    }
    printf("%d", cnt);
}