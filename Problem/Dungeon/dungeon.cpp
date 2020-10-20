#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxN = 505;
char str[maxN][maxN];
bool visited[maxN][maxN][66];
class Grid{
public:
	int y,x,cnt,bit;
	Grid(int y,int x,int cnt,int bit){
		this->y = y;
		this->x = x;
		this->cnt = cnt;
		this->bit = bit;
	}
};
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	pair<int,int> s,e;
	for(int i=0;i<n;i++){
		scanf("%s",str[i]);
		for(int j=0;j<m;j++){
			if(str[i][j] == 'S') s = {i,j};
		}
	}
	queue<Grid> q;
	q.push(Grid(s.first,s.second,0,0));
	char city[7] = "abcdef";
	while(!q.empty()){
		int y = q.front().y, x = q.front().x, bit = q.front().bit;
		int cnt = q.front().cnt;
		if(str[y][x] == 'E'){
			printf("%d\n",cnt);
			return 0;
		}
		visited[y][x][bit] = true;
		q.pop();
		for(int i=0;i<4;i++){
			int yy = y+dy[i];
			int xx = x+dx[i];
			int newbit = bit;
			if(yy >= n || yy < 0 || xx >= m || xx < 0) continue;
			if(str[yy][xx] == '#') continue;
			if((str[yy][xx] == 'E' || str[yy][xx] == '.' || str[yy][xx] == 'S') && visited[yy][xx][newbit] == false){
				q.push(Grid(yy,xx,cnt+1,newbit));
				visited[yy][xx][newbit] = true;
				continue;
			}
			for(int j=0;j<6;j++){
				if(str[yy][xx] == city[j]-32){
					if(newbit&(1<<j)){
						if(visited[yy][xx][newbit] == false){
							q.push(Grid(yy,xx,cnt+1,newbit));
							visited[yy][xx][newbit] = true;
						}
					}
					break;
				}
			}
			for(int j=0;j<6;j++){
				if(str[yy][xx] == city[j]){
					if(visited[yy][xx][newbit] == false){
						q.push(Grid(yy,xx,cnt+1,newbit|(1<<j)));
						visited[yy][xx][newbit|(1<<j)] = true;
					}
					break;
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}