#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
class Point{
public:
    double x,y;
    Point(double x,double y){
        this->x = x;
        this->y = y;
    }
};
vector<Point> vecX,vecY;
double abso(double x){
    return x < 0 ? -x:x;
}
bool cmpX(Point& a,Point& b){
    return a.x < b.x;
}
bool cmpY(Point& a,Point& b){
    return a.y > b.y;
}
double dist(Point a,Point b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx+dy*dy);
}
const double INF = 1e9;

double closetPair(vector<Point> xsort,vector<Point> ysort){
    int n = xsort.size();
    if(n <= 1){
        return INF;
    }
    if(n == 2){
        return dist(xsort[0],xsort[1]);
    }
    int mid = n/2;
    Point midPoint = xsort[mid];
    vector<Point> xL(xsort.begin(),xsort.begin()+mid+1);
    vector<Point> xR(xsort.begin()+mid+1,xsort.end());
    vector<Point> yL,yR;
    for(int i=0;i<ysort.size();i++){
        if(ysort[i].x <= midPoint.x){
            yL.push_back(ysort[i]);
        } else{
            yR.push_back(ysort[i]);
        }
    }
    double dLeft = closetPair(xL,yL);
    double dRight = closetPair(xR,yR);
    double d = min(dLeft,dRight);
    vector<Point> strip;
    for(int i=0;i<ysort.size();i++){
        if(abso(ysort[i].x-midPoint.x) <= d){
            strip.push_back(ysort[i]);
        }
    }
    for(int i=0;i<strip.size();i++){
        for(int j=i+1;j<strip.size();j++){
            if(abso(strip[i].y - strip[j].y) >= d)
                break;
            d = min(d,dist(strip[i],strip[j]));
        }
    }
    return d;
}
int main(){
    int T,x,y;
    scanf("%d",&T);
    while(T--){
        int N;
        double R,D;
        vecX.clear();
        vecY.clear();
        scanf("%d %lf %lf",&N,&R,&D);
        for(int i=0;i<N;i++){
            scanf("%d %d",&x,&y);
            vecX.push_back(Point(x,y));
            vecY.push_back(Point(x,y));
        }
        sort(vecX.begin(),vecX.end(),cmpX);
        sort(vecY.begin(),vecY.end(),cmpY);
        double ans = closetPair(vecX,vecY);
        if(ans-2*R < D){
            printf("N\n");
        } else{
            printf("Y\n");
        }
    }
    return 0;
}
