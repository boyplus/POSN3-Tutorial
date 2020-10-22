#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxN = 10005;
int indeg[maxN];
vector<int> ans,vec[maxN];
int main(){
	//find topological on DAG graph
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		vec[u].push_back(v);
		indeg[v]++;
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		if(indeg[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		ans.push_back(u);
		for(int i=0;i<vec[u].size();i++){
			int v = vec[u][i];
			indeg[v]--;
			if(indeg[v] == 0) q.push(v);
		}
	}

	if(ans.size() != n){
		printf("This graph has no topological sort\n");
		return 0;
	}
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
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