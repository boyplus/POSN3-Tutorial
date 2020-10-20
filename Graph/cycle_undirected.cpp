#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 10001;
bool visited[maxN];
vector<int> vec[maxN];
bool dfs(int u,int p){
	if(visited[u] == true){
		return true;
	}
	visited[u] = true;
	for(int i=0;i<vec[u].size();i++){
		int v = vec[u][i];
		if(v == p){
			continue;
		}
		if(dfs(v,u)){
			return true;
		}
	}
	return false;
}
int main(){
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	bool found_cycle = false;
	for(int i=0;i<n;i++){
		if(dfs(i,-1)){
			found_cycle = true;
			break;
		}
	}
	if(found_cycle){
		printf("Found cycle\n");
	} else{
		printf("Not found cycle");
	}
	return 0;
}
/*
5 4
0 1
2 1
3 4
0 2
*/