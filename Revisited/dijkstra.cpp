#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxN = 10001, INF = (int)1e9;
int dist[maxN];
bool visited[maxN];
class graph{
public:
	int v,w;
	graph(int v,int w){
		this->v = v;
		this->w = w;
	}
};
class cmp{
public:
	bool operator()(graph& left, graph& right){
		return left.w > right.w;
	}
};
vector<graph> vec[maxN];
int main(){
	int n,m,s,e,u,v,w,sum = 0;
	scanf("%d %d %d %d",&n,&m,&s,&e);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		vec[u].push_back(graph(v,w));
		vec[v].push_back(graph(u,w));
	}
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	dist[s] = 0;
	priority_queue<graph,vector<graph>,cmp> pq;
	pq.push(graph(s,dist[s]));
	while(!pq.empty()){
		int u = pq.top().v, d = pq.top().w;
		pq.pop();
		if(visited[u]) continue;
		visited[u] = true;
		for(int i=0;i<vec[u].size();i++){
			int v = vec[u][i].v, w = vec[u][i].w;
			int newDist = dist[u] + w;
			if(newDist < dist[v] && visited[v] == false){
				dist[v] = newDist;
				pq.push(graph(v,dist[v]));
			}
		}
	}
	printf("%d\n",dist[e]);
}
/*
9 14 0 8
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