#include <iostream>

using namespace std;


int min(int a, int b){ // 최소 값 리턴
    if(a>b)
        return b;
    return a;
}
int max(int a, int b){ // 최대 값 리턴
    if(a<b)
        return b;
    return a;
}

int arr[3];
int n;
int maxr[3]={0}, minr[3]={0};

int main() {
    cin >> n;
    int t0,t1,t2;
    for(int i=1;i<=n;i++) {
        cin >> arr[0] >> arr[1] >> arr[2];
        t0 = minr[0];
        t1 = minr[1];
        t2 = minr[2];
        minr[0] = min(t0, t1) + arr[0];
        minr[2] = min(t1, t2) + arr[2];
        minr[1] = min(min(t1,t0), t2) + arr[1];  
        t0=maxr[0];
        t1 = maxr[1];
        t2=maxr[2];
        maxr[0] = max(t0,t1) + arr[0];
        maxr[2] = max(t1,t2) + arr[2];
        maxr[1] = max(max(t1,t0), t2) + arr[1];   
    }   
    cout << max(max(maxr[1], maxr[0]), maxr[2]) << " " << min(min(minr[1], minr[0]), minr[2]) << "\n";
}