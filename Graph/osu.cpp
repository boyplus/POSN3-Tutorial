#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class graph{
public:
	int v,w,t;
	graph(int v,int w,int t){
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
int dist[maxN][9];
vector<pair<int,int>> vec[maxN];
int main(){
	int N,M,T,S,E,u,v,w;
	scanf("%d %d %d",&N,&M,&T);
	scanf("%d %d",&S,&E);
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&u,&v,&w);
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
	}
	priority_queue<graph,vector<graph>,cmp> pq;
	pq.push(graph(S,0,0));
	while(!pq.empty()){
		int u = pq.top().v, d = pq.top().w, t = pq.top().t;
		pq.pop();
		for(int i=0;i<vec[u].size();i++){
			int v = vec[u][i].first;

		}
	}
	return 0;
}