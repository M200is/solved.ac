#include <bits/stdc++.h>

using namespace std;

stack<char> stack_;


int main() {
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++) {
        if(s[i]>='A' && s[i]<='Z') {
            cout << s[i];
        }
        else {
            if(s[i]== '(') {
                stack_.push(s[i]);
            }
            else if(s[i]=='*' || s[i] == '/') {
                while(!stack_.empty() && (stack_.top()=='*' || stack_.top()=='/')) {
                    cout << stack_.top();
                    stack_.pop();
                }
                stack_.push(s[i]);
            }
            else if(s[i]=='-' || s[i] == '+') {
                while(!stack_.empty() && stack_.top()!='(') {
                    cout << stack_.top();
                    stack_.pop();
                }
                stack_.push(s[i]);
            }
            else if(s[i]==')') {
                while(!stack_.empty() && stack_.top()!='(') {
                    cout << stack_.top();
                    stack_.pop();
                }
                stack_.pop();
            }
        }
    }
    while(!stack_.empty()) {
        cout << stack_.top();
        stack_.pop();
    }
}