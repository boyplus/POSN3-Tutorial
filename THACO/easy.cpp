#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
const int maxN = 100005;
char a[maxN],b[maxN];
stack<int> s;
int main(){
	scanf("%s %s",a,b);
	int i = strlen(a)-1,j = strlen(b)-1;
	int tod = 0;
	while(i >=0 || j >=0 ){
		if(i < 0){
			int temp = b[j]-48+tod;
			if(temp >= 10) tod = 1;
			else tod = 0;
			s.push(temp%10);
			j--;

		} else if(j < 0){
			int temp = a[i]-48+tod;
			if(temp >= 10) tod = 1;
			else tod = 0;
			s.push(temp%10);
			i--;
		} else{
			int temp = a[i]-48+b[j]-48+tod;
			if(temp >= 10) tod = 1;
			else tod = 0;
			s.push(temp%10);
			i--;
			j--;
		}
	}
	if(tod > 0){
		s.push(1);
	}
	while(!s.empty()){
		printf("%d",s.top());
		s.pop();
	}
	return  0;
}