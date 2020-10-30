#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxN = 10001, INF = (int)1e9;
int root[maxN];
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
int findRoot(int u){
	if(u == root[u]) return u;
	return root[u] = findRoot(root[u]);
}
bool cmp(graph& a,graph& b){
	return a.w < b.w;
}
int main(){
	int n,m,u,v,w,sum = 0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		vec.push_back(graph(u,v,w));
	}
	for(int i=0;i<n;i++){
		root[i] = i;
	}
	sort(vec.begin(),vec.end(),cmp);
	int idx = 0,cnt = 0;
	while(cnt < n-1){
		int u = vec[idx].u, v = vec[idx].v, w = vec[idx].w;
		int pu = findRoot(u);
		int pv = findRoot(v);
		if(pu != pv){
			//can merge
			root[pu] = pv;
			cnt++;
			sum+=w;
		}
		idx++;
	}
	printf("%d\n",sum);
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