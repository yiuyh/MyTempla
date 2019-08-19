#include<bits/stdc++.h>
#define maxn 100010

using namespace std;
int arr[maxn], dp[maxn];

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;

        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int len = 1;
        dp[0] = arr[0];
        for(int i = 1; i < n; i++){
            if(arr[i] > dp[len-1]){
                dp[len++] = arr[i];
            }else{
                int pos = lower_bound(dp, dp+len, arr[i]) - dp;
                dp[pos] = arr[i];
            }
        }
        printf("%d\n", len);
    }
    return 0;
}
