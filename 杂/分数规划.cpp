/*
有n个物品，每个物品有两个权值a和b。求一组wi∈[0,1]最大化(Σai*wi）/(Σbi*wi)
二分答案mid
若答案mid可行
则存在一组wi 使得 Σwi*(ai-mid*bi)>0
贪心求取Σwi*(ai-mid*bi)最大值  //最大值

最小化(Σai*wi）/(Σbi*wi)
若答案mid可行
则存在一组wi 使得 Σwi*(ai-mid*bi)<0
贪心求取Σwi*(ai-mid*bi)最小值  //最小值

*/
const double eps = 1e-6;
double a[N], b[N];

inline bool check(double mid) {
  double s = 0;
  for (int i = 1; i <= n; ++i)
    if (a[i] - mid * b[i] > 0)  // 如果权值大于 0
      s += a[i] - mid * b[i];   // 选这个物品
  return s > 0;
}

int main() {
  // 二分
  double L = 0, R = 1e9;
  while (R - L > eps) {
    double mid = (L + R) / 2;
    if (check(mid))  // mid 可行，答案比 mid 大
      L = mid;
    else  // mid 不可行，答案比 mid 小
      R = mid;
  }
  // 输出
  printf("%.6lf\n", L);
  return 0;
}


/*
有n个物品，每个物品有两个权值a和b。
选取k个物品p1,p2,...,pk 使得Σa(pi)/Σb(pi)最大
把第i个物品的权值设为ai-mid*bi,选最大k个
*/
inline bool cmp(double x, double y) { return x > y; }
inline bool check(double mid) {
  int s = 0;
  for (int i = 1; i <= n; ++i) c[i] = a[i] - mid * b[i];
  sort(c + 1, c + n + 1, cmp);
  for (int i = 1; i <= n - k + 1; ++i) s += c[i];
  return s > 0;
}


/*
洛谷 4377 Talent Show
有n个物品，每个物品有两个权值a和b  。
选任意多头牛 使得Σai/Σbi最大
要求Σbi>=w
可以考虑01背包。把bi作为第i个物品的重量， ai-mid*bi作为第i个物品的价值，然后问题就转化为背包了。
那么dp[n][w]就是最大值。
*/
double f[1010];
inline bool check(double mid) {
  for (int i = 1; i <= W; i++) f[i] = -1e9;
  for (int i = 1; i <= n; i++)
    for (int j = W; j >= 0; j--) {
      int k = min(W, j + b[i]);
      f[k] = max(f[k], f[j] + a[i] - mid * b[i]);
    }
  return f[W] > 0;
}
