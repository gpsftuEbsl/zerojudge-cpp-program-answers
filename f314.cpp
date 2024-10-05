#include<bits/stdc++.h>

using namespace std;

int m, n, dp[50][10000] = {};

int main(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        int a[10000], l[10000] = {}, r[10000] = {};
        for(int j = 1; j <= n; j++){
            cin >> a[j];
        }
        for(int j = 1; j <= n; j++){
            if(j == 1)
                l[j] = dp[i-1][j] + a[j];
            else
                l[j] = max(dp[i-1][j], l[j-1]) + a[j];
        }
        for(int j = n; j >= 1; j--){
            if(j == n)
                r[j] = dp[i-1][j] + a[j];
            else
                r[j] = max(dp[i-1][j], r[j+1]) + a[j];
        }
        for(int j = 1; j <= n; j++){
            dp[i][j] = max(l[j], r[j]);
        }
    }
    int ans = dp[1][1];
    for(int j = 1; j <= n; j++){
        ans = max(ans, dp[m][j]);
    }
    cout << ans << endl;
}
