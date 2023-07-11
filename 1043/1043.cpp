#include <iostream>
#include <algorithm>

int parent[100001];

int find_parent(int parent[], int x){
    if(parent[x] != x)
        return parent[x] = find_parent(parent[x]) 
    return x;     
}
void merge(int parent[], int a, int b){
    int x = find_parent(parent, a);
    int y = find_parent(parent, b);
 
    if(x != y){
        if(x < y) // 그룹번호가 더 작은 쪽으로 합치기
            parent[y] = x;
        else
            parent[x] = y;
    }    
}

int main() {
    int n, m;
    cin >> n >> m;

    int know_true;
    cin >> know_true;
    int parent[100];
    for(int i =0;i<=n;i++) {
        parent[i]=i;
    }
    int temp;
    for(i=0;i<know_true;i++) {
        cin >> temp;
        parent[temp]=0;
    }
    int a, b;
    int arr[100][100];
    int size[100];
    for(int i=0;i<m;i++) {
        cin >> a >> temp;
        size[i]=a;
    }
}