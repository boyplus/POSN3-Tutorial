#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class graph{
public:
	int u,v,w;
	graph(int u,int v,int w){
		this->u = u;
		this->v = v;
		this->w = w;
	}
};
const int maxN = 10001, INF = (int)1e9;
vector<graph> vec;
int dist[maxN];
int main(){
	int n,m,u,v,w,s,e;
	scanf("%d %d %d %d",&n,&m,&s,&e);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		vec.push_back(graph(u,v,w));
	}
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	dist[s] = 0;
	bool found_change = false;
	bool neg_cycle = false;
	int cnt = 0;
	do{
		found_change = false;
		for(int i=0;i<m;i++){
			int u = vec[i].u, v = vec[i].v, w = vec[i].w;
			int newDist = dist[u]+w;
			if(newDist < dist[v]){
				dist[v] = newDist;
				found_change = true;
			}
		}
		cnt++;
		if(cnt > n-1 && found_change){
			neg_cycle = true;
			break;
		}
	}while(found_change);

	if(neg_cycle){
		printf("This graph contains negative cycle\n");
	} else{
		printf("%d\n",dist[e]);
	}
	return 0;
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