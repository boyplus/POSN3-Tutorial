#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxN = 10001, INF = (int)1e9;
int dist[maxN];
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
	int n,m,u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		vec[u].push_back(graph(v,w));
	}
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	int start = 0;
	priority_queue<graph,vector<graph>,cmp> pq;
	pq.push({});
}