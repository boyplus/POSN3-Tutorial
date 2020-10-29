#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
#define mxN 2500+1
#define INF 1e12
using namespace std;
using pii = pair<int, int>;
using lld = long long int;
struct edge { int u, v, w; };
bool cmpEdge(edge &e1, edge &e2){ return e1.w > e2.w; }
vector<edge> graph;
vector<int> parent(mxN, 0);
int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}
int main(){
    int n, m;
    int u, v, w;
    int s, d, p;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &u, &v, &w);
        graph.push_back({u, v, w-1});
    }
    scanf("%d %d %d", &s, &d, &p);
    sort(graph.begin(), graph.end(), cmpEdge);
    for(int i=1; i<=n; i++) parent[i] = i;
    int pu, pv;
    for(int i=0; i<m; i++){
        u = graph[i].u;
        v = graph[i].v;
        w = graph[i].w;
        pu = find(u);
        pv = find(v);
        if(pu == pv) continue;
        parent[pu] = pv;
        if(find(s) == find(d)){
            printf("%d", (p/w)+!!(p%w));
            return 0;
        }
    }
    return 0;
}