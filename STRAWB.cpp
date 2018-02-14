#include<bits/stdc++.h>

using namespace std;
const int INF = 1e5 + 7;
int n, k;
int arr[1000], dp[1000][1000];

int memo(int kanya, int enya){
	if(kanya > k || enya >= n) return INF;
	if(enya == n - 1) return 0;
	if(dp[kanya][enya] != -1) return dp[kanya][enya];
	//printf("%d\n", dp[2][5]);
	return dp[kanya][enya] = min(memo(kanya + 1, enya + arr[enya]), memo(kanya, enya + 1) + 1);
}

int main(){
	int tc; scanf("%d", &tc);
	for(int p = 1; p <= tc; p++){
		memset(dp, -1, sizeof dp);
		memset(arr, 0, sizeof arr);
		scanf("%d %d", &n, &k);
		for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
		int res = memo(0, 0);
		/*for(int i = 0; i <= k; i++){
			for(int j = 0; j < n; j++) printf("%d ", dp[i][j]);
			printf("\n");
		}*/
		printf("Scenario #%d:\n", p);
		if(res < n - 1) printf("Teresa will skip %d strawberries\n", res);
		else printf("Teresa will skip all the strawberries\n");
	}
}

///https://www.spoj.com/problems/STRAWB
