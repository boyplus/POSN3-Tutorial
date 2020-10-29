#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxN = 10005,INF = (int)1e9;
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
	bool operator()(graph& l,graph& r){
		return l.w > r.w;
	}
};
vector<graph> vec[maxN];
int dist1[maxN],dist2[maxN];
int main(){
	int n,m,x,y,z,u,v,w;
	scanf("%d %d",&n,&m);
	scanf("%d %d %d",&x,&y,&z);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		vec[u].push_back(graph(v,w));
		vec[v].push_back(graph(u,w));
	}
	for(int i=0;i<n;i++){
		dist1[i] = INF;
		dist2[i] = INF;
	}
	priority_queue<graph,vector<graph>,cmp> pq;
	pq.push(graph(x,0));
	dist1[x] = 0;
	while(!pq.empty()){
		int u = pq.top().v,d = pq.top().w;
		pq.pop();
		for(int i=0;i<vec[u].size();i++){
			int v = vec[u][i].v, w = vec[u][i].w;
			int newDist = dist1[u]+w;
			if(newDist < dist1[v]){
				dist1[v] = newDist;
				pq.push(graph(v,newDist));
			}
		}
	}

	pq.push(graph(y,0));
	dist2[y] = 0;
	while(!pq.empty()){
		int u = pq.top().v,d = pq.top().w;
		pq.pop();
		for(int i=0;i<vec[u].size();i++){
			int v = vec[u][i].v, w = vec[u][i].w;
			int newDist = dist2[u]+w;
			if(newDist < dist2[v]){
				dist2[v] = newDist;
				pq.push(graph(v,newDist));
			}
		}
	}
	if(dist1[y] <= z){
		printf("%d %d %d\n",y,dist1[y],0);
		return 0;
	}
	int mn = INF,vertex = -1,distGo = -1;
	for(int i=0;i<n;i++){
		if(dist1[i] <= z){
			if(dist2[i] < mn){
				distGo = dist1[i];
				mn = dist2[i];
				vertex = i;
			}
		}
	}
	printf("%d %d %d\n",vertex,distGo,mn);
	return 0;
}