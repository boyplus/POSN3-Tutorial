#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
const int maxN = 2505;
class graph{
public:
	int u,v,w;
	graph(int u,int v,int w){
		this->u = u;
		this->v = v;
		this->w = w;
	}
};
bool cmp(graph& lef,graph& right){
	return lef.w > right.w;
}
vector<graph> vec;
int parent[maxN];
int root(int u){
	if(u == parent[u]) return u;
	return parent[u] = root(parent[u]);
}
int main(){
	int n,m,u,v,w,s,d,p;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		vec.push_back(graph(u,v,w));
	}
	scanf("%d %d %d",&s,&d,&p);
	for(int i=1;i<=n;i++){
		parent[i] = i;
	}
	sort(vec.begin(),vec.end(),cmp);
	int idx = 0,cnt = 0,now = 0;
	while(cnt < n-1 && idx < m){
		int u = vec[idx].u,v = vec[idx].v,w = vec[idx].w;
		int pu = root(u), pv = root(v);
		if(pu != pv){
			parent[pu] = pv;
			cnt++;
			if(root(s) == root(d)){
				int ans = ceil((float)p/(w-1));
				printf("%d\n",ans);
				break;
			}
		}
		idx++;
	}
	return 0;
}
/*
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
4 7 35
3 6 20
5 7 20
7 6 30
1 7 99
*/