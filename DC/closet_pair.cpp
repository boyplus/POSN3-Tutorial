#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
const double INF = 1e9;
class Point{
public:
	double x,y;
	Point(double x,double y){
		this->x = x;
		this->y = y;
	}
};
vector<Point> vecX,vecY;
bool cmpX(Point& a,Point& b){
	return a.x < b.x;
}
bool cmpY(Point& a,Point& b){
	return a.y > b.y;
}
double cal(Point a,Point b){
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx+dy*dy);
}
double abso(double x){
	return x < 0 ? -x:x;
}
double closetPair(int left,int right){
	if(left == right){
		return INF;
	}
	if(right - left == 1){
		return cal(vecX[left],vecX[right]);
	}
	int mid = (left+right)/2;
	double dLeft = closetPair(left,mid);
	double dRight = closetPair(mid+1,right);
	double d = min(dLeft,dRight);
	Point pMid = vecX[mid];
	vector<Point> strip;
	for(int i=left;i<=right;i++){
		if(abso(vecY[i].x - vecY[mid].x) <= d){
			strip.push_back(vecY[i]);
		}
	}
	for(int i=0;i<strip.size();i++){
		for(int j=i+1;j<strip.size();j++){
			if(abso(strip[i].y - strip[j].y) >= d){
				break;
			}
			d = min(d,cal(strip[i],strip[j]));
		}
	}
	return d;
}
int main(){
	int n,x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		vecX.push_back(Point(x,y));
		vecY.push_back(Point(x,y));
	}
	sort(vecX.begin(),vecX.end(),cmpX);
	sort(vecY.begin(),vecY.end(),cmpY);
	double ans = closetPair(0,n-1);
	printf("%f\n",ans);
	return 0;
}

/*
6
2 3
12 30 
40 50
5 1
12 10 
3 4
*/