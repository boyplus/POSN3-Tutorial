#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxN = 10005,INF = (int)1e9;
vector<pair<int,int>> vec[maxN];
int dist[maxN];
int main(){
	int n,m,u,v,w,s,e;
	scanf("%d %d %d %d",&n,&m,&s,&e);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
	}
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	dist[s] = 0;
	int cnt = 0;
	bool found_change = false,neg_cycle = false;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=0;i<vec[u].size();i++){
			int v = vec[u][i].first;
			int w = vec[u][i].second;
			int newWeight = dist[u]+w;
			if(newWeight < dist[v]){
				dist[v] = newWeight;
				q.push(v);
			}
		}
	}
	if(neg_cycle){
		printf("This graph contains negatove cycle");
		return 0;
	}
	printf("%d\n",dist[e]);
	return 0;
}
/*/*
9 14
0 1 4
0 7 8
1 7 11
1 2 8
2 3 7
3 4 9
4 5 10
6 5 2
7 6 1
7 8 7
2 8 2
2 5 4
3 5 14
8 6 6
*/