#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#define ll long long
using namespace std;
const int maxn = 2505;
const double eps = 1e-6;
double dp[maxn][maxn];
int now, pos[maxn], Size[maxn];
int n, m;
vector<int> g[maxn];
int a[maxn], b[maxn];
double mid;

inline  void dfs(int u){
    Size[u] = 1; dp[u][1] = double(a[u]-mid*b[u]);
    for(int k = 0; k < g[u].size(); k++){
        dfs(g[u][k]);
        for(int i = Size[u]; i >= 1; i--){
            for(int j = 0; j<=Size[g[u][k]]&&i+j<=m; j++){
                dp[u][i+j] = max(dp[u][i+j], dp[u][i]+dp[g[u][k]][j]);
            }
        }
        Size[u] += Size[g[u][k]];
    }
}

inline  bool check(){
    memset(dp,-10,sizeof(dp));
    a[0] = b[0] = 0;
    dfs(0);
    return dp[0][m] > 0;
}

int main() {
    cin >> m >> n;
    m++;
    for(int i = 1; i <= n; i++){
        int fa;
        scanf("%d%d%d", &b[i], &a[i], &fa);
        g[fa].push_back(i);
    }
    double L = 0, R = 10000.0001;
    while (R - L > eps) {
        mid = (L + R) / 2;
        if(check())  // mid 可行，答案比 mid 大
          L = mid;
        else  // mid 不可行，答案比 mid 小
          R = mid;
    }
    // 输出
    printf("%.3lf\n", L);
	return 0;
}
