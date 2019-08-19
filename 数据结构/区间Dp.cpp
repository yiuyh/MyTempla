//四边形优化  s(i, j) <= s(i, j+1) <= s(i+1, j+1)

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

for(int len=2;len<=n;len++) //枚举长度
      for(int i=1;i<=n;i++)
      {
          int j=i+len-1;
          if(j>n) continue;
          for(int k=s[i][j-1];k<=s[i+1][j];k++)
          {
              if(dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]<dp[i][j])
              {
                  dp[i][j]=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
                  s[i][j]=k;
              }
          }
      }

//  最优二叉搜索树  m(i, j) = min{min(i, k-1) + w(i, k-1) + m(k+1, j) + w(k+1, j)}, i < j
//  回文子序列个数  dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]; if(ch[i] == ch[j]) dp[i][j] += dp[i+1][j-1];
// 最长回文子序列  if (s[l]==s[r])  f[l][r]=f[l+1][r-1]+2; else f[l][r]=max(f[l+1][r],f[l][r-1]);
//修改两串相同最小操作次数  { f[l][r]=f[l+1][r]+1； f[l][r]=min（f[l][r],f[l][k]+f[k+1][r]）} {if(a[i]==b[i]) ans[i]=ans[i-1];else ans[i]=min(ans[i],ans[j]+f[j+1][i]); }
