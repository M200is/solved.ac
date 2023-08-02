#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int, vector<int>> pq2;
    cin >> n;
    int l[n];
    for(int i=0;i<n;i++) {
        cin >> l[i];
    }
    for(int i=0;i<n;i++) {
        if(pq1.size()<pq2.size()) {
            pq1.push(l[i]);
        }
        else {
            pq2.push(l[i]);
        }
        if(!pq1.empty() && !pq2.empty()) {
            if(pq1.top()<pq2.top()) {
                int t1 = pq1.top();
                int t2 = pq2.top();
                pq1.pop();
                pq2.pop();
                pq1.push(t2);
                pq2.push(t1);
            }
        }
        cout <<pq2.top() << "\n";
    }

}