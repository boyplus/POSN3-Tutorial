#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxN = 10001;
int color[maxN];
vector<int> vec[maxN];
bool cycle = false;
void dfs(int u){
	if(color[u] == 1){
		cycle = true;
		return;
	}
	color[u] = 1;
	for(int i=0;i<vec[u].size();i++){
		int v = vec[u][i];
		if(color[v] != 2){
			dfs(v);
		}
	}
	color[u] = 2;
}
int main(){
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		vec[u].push_back(v);
	}
	for(int i=0;i<n;i++){
		if(color[i] == 0){
			dfs(i);
			if(cycle){
				break;
			}
		}
	}
	if(cycle){
		printf("Detected cycle\n");
	} else{
		printf("Not deteced cycle\n");
	}
	return 0;
}
/*
6 6
0 1
1 2
2 4
4 5
4 3
3 1
*/