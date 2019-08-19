#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 810;
const int INF = 0x3f3f3f3f;
int n, xl, xr, yl, yr;
int maxv, minv, ans;
int grid[maxn][maxn];
struct IntevalTree{
    int max1[maxn<<3][maxn<<3];
    int min1[maxn<<3][maxn<<3];
    void pushup(int xo, int o){
        max1[xo][o] = max(max1[xo][o<<1], max1[xo][o<<1|1]);
        min1[xo][o] = min(min1[xo][o<<1], min1[xo][o<<1|1]);
    }
    void buildy(int xo, int o, int l, int r, int x){
        if(l == r){
            if(x != -1){
                max1[xo][o] = min1[xo][o] = grid[x][l];
            }else{
                max1[xo][o] = max(max1[xo<<1][o], max1[xo<<1|1][o]);
                min1[xo][o] = min(min1[xo<<1][o], min1[xo<<1|1][o]);
            }
            return;
        }
        int mid = (l+r)>>1;
        buildy(xo, o<<1, l, mid, x);
        buildy(xo, o<<1|1, mid+1, r, x);
        pushup(xo, o);
    }
    void buildx(int o, int l, int r){
        if(l == r){
            buildy(o, 1, 1, n, l);
            return;
        }
        int mid = (l+r)>>1;
        buildx(o<<1,l, mid);
        buildx((o<<1)+1, mid+1, r);
        buildy(o, 1, 1, n, -1);
    }
    void queryy(int xo, int o, int l, int r){
        if(yl<=l&&r<=yr){
            maxv = max(maxv, max1[xo][o]);
            minv = min(minv, min1[xo][o]);
            return;
        }
        int mid = (l+r)>>1;
        if(yl<=mid) queryy(xo, o<<1,l, mid);
        if(yr>mid) queryy(xo, (o<<1)+1, mid+1, r);
    }
    void queryx(int o, int l, int r){
        if(xl<=l && r<=xr){
            queryy(o, 1, 1, n);
            return;
        }
        int mid = (l+r)>>1;
        if(xl<=mid) queryx(o<<1,l, mid);
        if(xr>mid) queryx((o<<1)+1, mid+1, r);
    }
    void updatey(int xo, int o, int l, int r, int x){
        if(l==r){
            if(x!=-1){max1[xo][o]=min1[xo][o]=ans;}
            else{
                max1[xo][o]=max(max1[xo<<1][o],max1[xo<<1|1][o]);
                min1[xo][o]=min(min1[xo<<1][o],min1[xo<<1|1][o]);
            }
            return;
        }
        int mid=(l+r)/2;
        if(yl<=mid) updatey(xo,o*2,l,mid,x);
        else updatey(xo,o*2+1,mid+1,r,x);
        pushup(xo,o);

    }
    void updatex(int o, int l, int r){
        if(l == r){
            updatey(o, 1, 1, n, l);
            return;
        }
        int mid=(l+r)>>1;
        if(xl<=mid)updatex(o<<1, l, mid);
        else updatex(o<<1|1, mid+1, r);
        updatey(o, 1, 1, n, -1);
    }
}tree;

int main(){
    int t, cas = 1, q;
    int x, y, len;
    cin >> t;
    while(t--){
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) scanf("%d", &grid[i][j]);
            tree.buildx(1, 1, n);
            scanf("%d", &q);
            printf("Case #%d:\n",cas++);
            while(q--){
                scanf("%d%d%d", &x, &y, &len);
                len = (len+1)/2;
                xl = max(1, x-len+1); xr = min(n, x+len-1);
                yl = max(1, y-len+1); yr = min(n, y+len-1);
                maxv = -INF;minv = INF;
                tree.queryx(1, 1, n);
                ans = (maxv+minv)/2;
                printf("%d\n", ans);
                xl = x, yl = y;
                tree.updatex(1, 1, n);
            }
        }
    return 0;

}
