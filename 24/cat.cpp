#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <set>
using namespace std;
const int maxN = 2000003;
int arr[maxN];
vector<int> it;
int main(){
	int n,mx = INT_MIN;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		it.push_back(arr[i]);
		mx = max(mx,arr[i]);
	}
	it.push_back(0);
	sort(it.begin(),it.end());
	int left = 0,right = it.size()-1,ans = mx;
	while(left <= right){
		int mid = (left+right)/2;
		bool ok = true;
		vector<int> vec;
		for(int i=0;i<n;i++){
			if(arr[i] > it[mid]){
				vec.push_back(arr[i]);
				if(vec.size()%2 == 0){
					if(vec.back() != vec[vec.size()-2]){
						ok = false;
						break;
					}
				}
			}
		}
		if(ok){
			ans = it[mid];
			right = mid-1;
		} else{
			left = mid+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}