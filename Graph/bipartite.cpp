#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 10001;
int color[maxN];
vector<int> vec[maxN];
bool dfs(int u,int c){
	if(color[u] != 0){
		if(color[u] == c) return true;
		return false;
	}
	color[u] = c;
	for(int i=0;i<vec[u].size();i++){
		int v = vec[u][i];
		int newColor = 1;
		if(c == 1){
			newColor = 2;
		}
		bool try_paint = dfs(v,newColor);
		if(try_paint == false){
			return false;
		}
	}
	return true;
}
int main(){
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	bool is_bipartite = true;
	for(int i=0;i<n;i++){
		if(color[i] == 0){
			//not paint yet
			bool try_paint = dfs(i,1);
			if(try_paint == false){
				is_bipartite = false;
				break;
			}
		}
	}
	if(is_bipartite) printf("This graph is a bipartite graph\n");
	else printf("This graph is not a bipartite graph\n");
	return 0;
}
/*
5 4
0 1
1 2
4 3
0 2
*/