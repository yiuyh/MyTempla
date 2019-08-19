#include<iostream>
#include<cstdio>

using namespace std;

const int maxn = 100010;

struct node{
    int val;
    int to;
    int next;
};

node edge[maxn];
int cnt = 1;
int head[maxn];
int dfn[maxn], low[maxn], Stack[maxn], color[maxn];
int dfs_num = 0, top = 0, col_num = 0;
bool vis[maxn];

void Tarjan (int x) {
         dfn[ x ] = ++dfs_num ;
         low[ x ] = dfs_num ;
         vis [ x ] = true ;//是否在栈中
         Stack[ ++top ] = x ;
         for ( int i= head[x] ; i!=0 ; i=edge[i].next ){
                  int temp = edge[i].to ;
                  if ( !dfn[temp] ){
                           Tarjan (temp) ;
                           low[x] = min( low[x] , low[temp] ) ;
                 }
                 else if ( vis[ temp ])low[ x ] = min( low[ x ] , dfn[ temp ] ) ;
         }
         if ( dfn[x]==low[x] ) {//构成强连通分量
                  vis[x] = false ;
                  color[x] = ++col_num ;//染色
                  while ( Stack[ top ] != x ) {//清空
                           color [Stack[top]] = col_num ;
                           vis [ Stack[top--] ] = false ;
                 }
                 top -- ;
         }
}

void add(int u, int v, int val){
    edge[cnt].val = val;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v, 0);
    }
    for(int i = 1; i <= n; i++) if(!dfn[i]) Tarjan(i);
    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
         for(int j = head[i]; j; j = edge[j].next) cout << j << "(" << i << "to" << edge[j].to << ")" << " ";
         cout << endl;
    }
    cout << col_num << endl;
    return 0;
}

//tarjan+缩点

#include<bits/stdc++.h>
using namespace std;

const int N=10000+5;
vector<int>lk[N];//用vector存一个点的出边
int dfn[N],low[N],tot;
int st[N],top;bool in_st[N];
int belong_scc[N],scc_cnt;//scc=strongly connected component=强连通分量
int scc_out_degree[N];//出度

void dfs(int x)
{
    dfn[x]=low[x]=++tot;
    st[++top]=x;
    in_st[x]=1;

    for(int i=0;i<lk[x].size();++i)
    {
        int y=lk[x][i];
        if(!dfn[y])
        {
            dfs(y);
            if(low[x]>low[y])low[x]=low[y];
        }
        else
        {
            if(in_st[y])
            if(low[x]>low[y])low[x]=low[y];
            //注意这里的实现和上面说的稍有不同，即用了low[y]而非dfn[y]来更新low[x]，这两种写法都是对的。
        }
    }

    if(low[x]==dfn[x])
    {
        ++scc_cnt;
        while(1)
        {
            int y=st[top--];
            in_st[y]=0;
            belong_scc[y]=scc_cnt;
            if(y==x)break;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        lk[x].push_back(y);
    }

    for(int i=1;i<=n;++i)
    if(!dfn[i])
        dfs(i);

    for(int x=1;x<=n;++x)
    for(int i=0;i<lk[x].size();++i)
    {
        int y=lk[x][i];
        if(belong_scc[x]!=belong_scc[y])
            ++scc_out_degree[belong_scc[x]];
    }
    int x0=0;
    for(int x=1;x<=scc_cnt;++x)
    if(scc_out_degree[x]==0)
    {
        if(x0)//超过一个点度为0
        {
            puts("0");
            exit(0);
        }
        x0=x;
    }
    int ans=0;
    for(int x=1;x<=n;++x)
    if(belong_scc[x]==x0)
        ++ans;
    cout<<ans;
}
