#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxN = 15001,INF = (int)1e9;
int dist[maxN],x[maxN],y[maxN];
bool visited[maxN];
vector<int> md;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d %d",&x[i],&y[i]);
		dist[i] = INF;
	}
	int choose = 0;
	for(int i=0;i<n;++i){
		int current = choose, mn = INF;
		visited[current] = true;
		for(int j=0;j<n;++j){
			if(visited[j] == true) continue;
			int d = abs(x[current]-x[j])+abs(y[current]-y[j]);
			dist[j] = min(dist[j],d);
			if(mn > dist[j]){
				choose = j;
				mn = dist[j];
			}
		}
		md.push_back(mn);
	}
	long long sum = 0;
	sort(md.begin(),md.end());
	int last = n-k;
	for(int i=0;i<last;++i){
		sum += md[i];
	}
	printf("%lld\n",sum);
	return 0;
}