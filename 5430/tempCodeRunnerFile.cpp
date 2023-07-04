#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t, i, j, n;
    string temp="";
    string p, input;
    bool error;
    int reverse = -1;
    scanf("%d", &t);
    for(i=0;i<t;i++) {
        deque<int> arr;
        error = false;
        cin >> p;
        cin >> n;
        cin >> input;
        if(n) {
            for(j=0;j<input.length();j++) {
                if(input[j]=='[' || input[j]==']' || input[j]==',') {
                    if(input[j]!='[') {
                        arr.push_back(stoi(temp));
                    }
                    temp = "";
                    continue;
                }
                temp+=input[j];
            }
        }
        for(j=0;j<p.length();j++) { 
            if(p[j]=='R') {
                reverse *= -1;
            }
            else if(p[j]=='D'){
                if(arr.size()==0) {
                    cout << "error" <<"\n";
                    error = true;
                    break;
                }
                if(reverse == -1) {
                    arr.pop_front();
                }
                else {
                    arr.pop_back();
                }   
            }
        }
        if(!error) {
            cout <<"[";
            if(reverse == -1) {
                while(!arr.empty()) {
                    if(arr.size()==1) {
                        cout << arr.front();
                        arr.pop_front();
                    }
                    else {
                        cout << arr.front() << ",";
                        arr.pop_front();
                    }
                }
            }
            else {
                while(!arr.empty()) {
                    if(arr.size()==1) {
                        cout << arr.back();
                        arr.pop_back();
                    }
                    else {
                        cout << arr.back() << ",";
                        arr.pop_back();
                    }
                }
            }
            cout << "]\n";
        }
    }
    
}