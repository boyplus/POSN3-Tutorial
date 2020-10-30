#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
class graph{
public:
	int v,t;
	ll w;
	graph(int v,ll w,int t){
		this->v = v;
		this->w = w;
		this->t = t;
	}
};
class cmp{
public:
	bool operator()(const graph& a,const graph& b){
		return a.w > b.w;
	}
};
const int maxN = 10005;
const ll INF = (long long)1e18;
ll dist[maxN][9];
bool visited[maxN][9];
vector<pair<int,int>> vec[maxN];
int main(){
	int N,M,T,S,E,u,v,w;
	scanf("%d %d %d",&N,&M,&T);
	scanf("%d %d",&S,&E);
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&u,&v,&w);
		vec[u].push_back({v,w});
	}
	for(int i=1;i<=N;i++){
		for(int j=0;j<T;j++){
			dist[i][j] = INF;
		}
	}
	priority_queue<graph,vector<graph>,cmp> pq;
	dist[S][1%T] = 0;
	pq.push(graph(S,0,1));
	while(!pq.empty()){
		int u = pq.top().v, t = pq.top().t;
		int turn = (t+1)%T;
		ll d = pq.top().w;
		pq.pop();
		if(visited[u][t]) continue;
		visited[u][t] = true;
		for(int i=0;i<vec[u].size();i++){
			int v = vec[u][i].first;
			ll w = vec[u][i].second;
			ll newDist = dist[u][t]+w;
			if(!visited[v][turn] && newDist < dist[v][turn]){
				dist[v][turn] = newDist;
				pq.push(graph(v,newDist,turn));
			}
		}
	}
	if(dist[E][0] == INF){
		printf("-1\n");
	} else{
		printf("%lld\n",dist[E][0]);
	}
	return 0;
}