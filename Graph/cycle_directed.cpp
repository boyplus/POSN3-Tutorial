#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 10001;
int color[maxN];
vector<int> vec[maxN];
bool dfs(int u){
	if(color[u] == 1){
		return true;
	}
	if(color[u] == 2){
		return false;
	}
	color[u] = 1;
	for(int i=0;i<vec[u].size();i++){
		int v = vec[u][i];
		if(dfs(v)){
			return true;
		}
	}
	color[u] = 2;
	return false;
}
int main(){
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		vec[u].push_back(v);
	}
	bool found_cycle = false;
	for(int i=0;i<n;i++){
		if(dfs(i)){
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
3 4
1 2
2 0
*/