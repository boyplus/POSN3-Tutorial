#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxN = 2002,INF = (int)1e9;
char str[maxN][maxN];
class grid{
public:
	int r,c,d;
	grid(int r,int c,int d){
		this->r = r;
		this->c = c;
		this->d = d;
	}
};
int dist[maxN][maxN];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
int main(){
	int n,m,cnt = 0,sum = 0;
	scanf("%d %d",&n,&m);
	queue<grid> q;
	for(int i=0;i<n;i++){
		scanf("%s",str[i]);
		for(int j=0;j<m;j++){
			dist[i][j] = INF;
			if(str[i][j] == 'X'){
				q.push(grid(i,j,0));
				dist[i][j] = 0;
			}
		}
	}
	while(!q.empty()){
		int r = q.front().r,c = q.front().c,d = q.front().d;
		q.pop();
		for(int i=0;i<4;i++){
			int rr = r+dr[i],cc = c+dc[i];
			if(rr < 0 || rr >= n || cc < 0 || cc >= m) continue;
			if(str[rr][cc] == 'W') continue;
			if(d+1 < dist[rr][cc]){
				dist[rr][cc] = d+1;
				q.push(grid(rr,cc,d+1));
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(str[i][j] == 'A' && dist[i][j] != INF){
				cnt++;
				sum+=dist[i][j];
			}
		}
	}
	printf("%d %d\n",cnt,sum*2);
	return 0;
}
/*
5 5
EEEEE
AEAEW
WEEWW
WEEXE
WWEXA
*/