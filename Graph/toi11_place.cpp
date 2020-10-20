#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 200005;
int parent[maxN];
class graph{
public:
	int u,v,w;
	graph(int u,int v,int w){
		this->u = u;
		this->v = v;
		this->w = w;
	}
};
bool cmp(graph& left,graph& right){
	return left.w > right.w;
}
vector<graph> vec;
int root(int u){
	if(u == parent[u]) return u;
	return parent[u] = root(parent[u]);
}
int main(){
	int n,m,u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		vec.push_back(graph(u,v,w-1));
	}
	for(int i=0;i<n;i++){
		parent[i] = i;
	}
	sort(vec.begin(),vec.end(),cmp);
	long long sum = 0;
	int idx = 0,cnt = 0;
	while(cnt < n-1 && idx < m){
		int u = vec[idx].u,v = vec[idx].v, w = vec[idx].w;
		int pu = root(u), pv = root(v);
		if(pu != pv){
			//merge
			cnt++;
			sum+=w;
			parent[pu] = pv;
		}
		idx++;
	}
	long long ans = sum;
	printf("%lld\n",ans);
	return 0;
}