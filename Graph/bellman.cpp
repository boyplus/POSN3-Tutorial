#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxN = 10005,INF = (int)1e9;
class graph{
public:
	int u,v,w;
	graph(int u,int v,int w){
		this->u = u;
		this->v = v;
		this->w = w;
	}
};
vector<graph> vec;
int dist[maxN];
int main(){
	int n,m,u,v,w,s,e;
	scanf("%d %d %d %d",&n,&m,&s,&e);
	//we store the data in form of edges list
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		vec.push_back(graph(u,v,w));
	}
	//initial the dist from source to that node are all INF
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	//dist from source to source is 0
	dist[s] = 0;
	//cnt is made for count the number of time that we can edit the distance
	//(foudn the shorter path)
	int cnt = 0;
	bool found_change = false,neg_cycle = false;
	do{
		//we loop all edge and if the dist[u] plus by weight of that edge
		//is less than dist[v], we can choose this edge as a new path from u to v
		//we keep doint this until there is no edge to choose
		found_change = false;
		for(int i=0;i<m;i++){
			int u = vec[i].u;
			int v = vec[i].v;
			int w = vec[i].w;
			int newWeight = dist[u]+w;
			if(newWeight < dist[v]){
				dist[v] = newWeight;
				found_change = true;
			}
		}
		cnt++;
		//if we made change more than n-1 times that means
		//there is a negative cycle in this graph
		if(cnt > n-1 && found_change){
			neg_cycle = true;
			break;
		}

	} while(found_change);
	if(neg_cycle){
		printf("This graph contains negatove cycle");
		return 0;
	}
	printf("%d\n",dist[e]);
	return 0;
}
/*
/*
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