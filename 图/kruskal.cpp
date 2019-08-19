#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 10000+10

using namespace std;
typedef long long ll;
struct node{
  int u, v, w;
  bool operator <(const node b) const{
      return w > b.w;
  }
};
node edge[maxn];
int fa[maxn];

int Find(int x){
    if(x == fa[x]) return x;
    fa[x] = Find(fa[x]);
    return fa[x];
}

int main(){
    int n, m;
    while(~scanf("%d%d", n, m) && n){
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", edge[i].u, edge[i].v, edge[i].w);
        }
        sort(edge, edge+n);
        ll sum = 0;
        int total = 0;
        for(int i = 0; i < n; i++){
            int fx = Find(edge[i].u);
            int fy = Find(edge[i].v);
            if(fx != fy){
                fa[fx] = fy;
                sum += edge[i].w;
                total++;
            }
            if(total == m-1) printf("%lld\n", sum);
            else printf("?\n");
        }
    }
    return 0;
}
