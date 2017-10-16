//SPOJ DCEPC501 : save thy toys

#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ll tc; scanf("%lld" ,&tc);
	while(tc--){
		ll n; scanf("%lld", &n);
		ll val[123456]; memset(val, 0, sizeof val);
		for(ll i = 0; i < n; i++) scanf("%lld", &val[i]);
		ll dp[123456];
		memset(dp, 0, sizeof dp);
		for(ll i = n - 1; i >= 0; i--){
			dp[i] = max(val[i] + dp[i + 2], max(val[i] + val[i + 1] + dp[i + 4], val[i] + val[i + 1] + val[i + 2] + dp[i + 6]));
		}
		printf("%lld\n", dp[0]);
	}
	return 0;
}
