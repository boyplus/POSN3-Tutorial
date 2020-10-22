#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
const int maxN = 10005;
vector<int> vec[maxN];
bool visited[maxN];
stack<int> ans;
void dfs(int u){
	visited[u] = true;
	printf("inside %d\n",u);
	for(int i=0;i<vec[u].size();i++){
		int v = vec[u][i];
		if(visited[v] == false){
			dfs(v);
		}
	}
	ans.push(u);
}
int main(){
	//find topological on DAG graph
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		vec[u].push_back(v);
	}
	for(int i=0;i<n;i++){
		if(visited[i] == false){
			dfs(i);
		}
	}
	while(!ans.empty()){
		printf("%d ",ans.top());
		ans.pop();
	}
	printf("\n");
	return 0;
}

/*
7 12
0 1
0 2
2 5
1 4
1 6
6 4
6 5
3 0
3 1
3 2
3 5
3 6
*/