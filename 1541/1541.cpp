#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

int main() {
    int result=0;
    int temp;
    char str[51];
    bool check=false;
    stringstream ss;
    scanf("%s", str);
    ss.str(str);
    while (ss >> temp) {
        if(temp<0) {
            check = true;
        }
        if(check && temp>0) {
            result-=temp;
        }
        else {
            result += temp;
        }
    }
    printf("%d", result);
}