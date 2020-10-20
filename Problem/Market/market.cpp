#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
const int maxn = 100005;
ll a[maxn];
int main(){
	ll n,s,temp,ans_k = 0;
	ll ans_sum = 0;
	scanf("%lld %lld",&n,&s);
	for(int i=0;i<n;i++){
		scanf("%lld",&temp);
		a[i] = temp;
	}
	ll left = 0, right = n;
	while(left <= right){
		ll mid = (left+right)/2;
		ll sum = 0;
		vector<ll> vec;
		for(int i=0;i<n;i++){
			ll temp = a[i]+((i+1)*mid);
			vec.push_back(temp);
		}
		sort(vec.begin(),vec.end());
		for(int i=0;i<mid;i++){
			sum+=vec[i];
			if(sum > s) break;
		}
		if(sum <= s){
			left = mid+1;
			ans_k = mid;
			ans_sum = sum;
		} else{
			right = mid-1;
		}
	}
	printf("%lld %lld\n",ans_k,ans_sum);
	return 0;
}