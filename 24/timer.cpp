#include <bits/stdc++.h>
using namespace std;
const int pb = 5;
const int N = 5000010;
char str[N];
int main(){
    int n;
    scanf("%d",&n);
    scanf(" %s",str);
    for(int i=1;i<=n;++i){
        if(n%i != 0){
            continue;
        }
        bool pass = true;
        for(int j=0;j<n-i;++j){
            if(str[j] != str[i+j]){
                pass = false;
                break;
            }
        }
        if(pass){
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}
