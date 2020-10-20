#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 10001;
bool visited[maxN];
vector<int> vec[maxN];
void dfs(int u){
	visited[u] = true;
	for(int i=0;i<vec[u].size();i++){
		int v = vec[u][i];
		if(visited[v] == false){
			dfs(v);
		}
	}
}
int main(){
	int n,m,u,v,cnt = 0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i=0;i<n;i++){
		if(visited[i] == false){
			dfs(i);
			cnt++;
		}
	}
	printf("%d\n",cnt);
    return 0;
}
/*
5 3
0 1
2 0
3 4
*/