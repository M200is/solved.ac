#include <bits/stdc++.h>

using namespace std;
int x[51], y[51];
int n, k;

int fac(int n) {
    if(n==1) {
        return 1;
    }
    return n*fac(n-1);
}

int min_=INT_MAX;
void solve(vector<int> v) {
    int max_;
    max_=0;
    for(int i=0;i<n;i++) {
        int list[100000];
        int x_ = x[i];
        int y_ = y[i];
        for(int j=0;j<v.size();j++) {
            list[j]=(abs(x[v[j]]-x_) + abs(y[v[j]]-y_)); 
        }
        sort(list, list+v.size());
        max_ =max(max_, list[0]);
    }
    min_ = min(min_, max_);
}

void backtrac(vector<int> v, int t) {
    if(v.size()==k) {
        solve(v);
        return;
    }
    for(int i=t;i<n;i++) {
        v.push_back(i);
        backtrac(v, t);
        v.erase(v.end()-1);
    }
}

int main() {
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> x[i] >> y[i];
    }
    vector<int> a;
    backtrac(a, 0);
    cout << min_;
}