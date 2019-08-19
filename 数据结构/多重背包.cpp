
inline int getbitmost(int x) {
    if (x == 0) return 0;
    int i = 0;
    while(x){
        i++;
        x >>= 1;
    }
    return i-1;
}
//////////////物品价值////物品体积//物品件数
int dp[maxn], val[maxn], v[maxn], qua[maxn];
int n;//n件物品
int vmax;
memset(dp, 0,sizeof(dp));
for(int i = 1; i <= n; i++){
           int t = getbitmost(qua[i]);
           for(int j = t-1; j >= 0; j--){
               int d = (1<<j) * v[i];
               for(int k = vmax-d; k >= 0; k--){
                   if (k + d > vmax) continue;
                   dp[k+d] = (dp[k+d] + dp[k]);
               }
           }
           int d = (cnt - (1<<t) + 1) * v[i];
           for (int j = vmax; j >= 0; j--) {
               if (j + d > vmax) continue;
               dp[j+d] = (dp[j+d]+dp[j]);
           }
      }
