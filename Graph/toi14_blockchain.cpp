#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
using pii = pair<int,int>;
bool cmp(pii& a,pii& b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first < b.first;
}
map<vector<pii>,int> mp;
int main(){
	int t,q,n,u,v;
	scanf("%d %d",&t,&q);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		vector<pair<int,int>> graph;
		for(int j=1;j<n;j++){
			scanf("%d %d",&u,&v);
			if(u > v){
				int temp = u;
				u = v;
				v = temp;
			}
			graph.push_back({u,v});
		}
		sort(graph.begin(),graph.end());
		mp[graph]++;
	}

	for(int i=0;i<q;i++){
		scanf("%d",&n);
		vector<pii> graph;
		for(int j=1;j<n;j++){
			scanf("%d %d",&u,&v);
			if(u > v){
				int temp = u;
				u = v;
				v = temp;
			}
			graph.push_back({u,v});
		}
		sort(graph.begin(),graph.end(),cmp);
		printf("%d\n",mp[graph]);
	}
	return 0;
}