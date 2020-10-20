#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxN = 10005,INF = (int)1e9;
vector<pair<int,int>> vec[maxN];
int dist[maxN],cnt[maxN];
int main(){
	//This concept is similar to bellam-ford but in this algorithm
	//We see that we can edit the distance according to the currect node
	//and if we can edit the dist, we push it in the queue and kepp doing this
	//until the queue is empty, we can see that this algorithm is faster than
	//the previous bc we focus on only the node that can edit distance,
	//not all edge in each time
	int n,m,u,v,w,s,e;
	scanf("%d %d %d %d",&n,&m,&s,&e);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		//we store the graph in adjacency list
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
	}
	//dist from source to every nodes are all INF
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	//dist from source to source is 0
	dist[s] = 0;
	bool neg_cycle = false;
	//we use queue to consider the node and push the source node
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		//if we consider the node u more than n-1 times, that means
		//there is a negative cycle in this graph
		cnt[u]++;
		if(cnt[u] > n-1){
			neg_cycle = true;
			break;
		}
		//get all adjacent node of node u
		for(int i=0;i<vec[u].size();i++){
			int v = vec[u][i].first;
			int w = vec[u][i].second;
			int newWeight = dist[u]+w;
			//if the dist[u] plus by that weight of that edge
			//is less than old dist[v], we can edit the distance
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