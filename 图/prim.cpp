#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
const int INF=0x3f3f3f3f;
int Edge[maxn][maxn];
int lowcost[maxn];
int nearvex[maxn];
int n,m;
void init()
{
    memset(Edge,0,sizeof(Edge));
}
void prim(int u)
{
    int sumweight=0;//生成树的权值
    for(int i=1;i<=n;i++)
    {
        lowcost[i]=Edge[u][i];
        nearvex[i]=u;
    }
    nearvex[u]=-1;
    for(int i=1;i<=n;i++)
    {
        int minx=INF;
        int v=-1;
        for(int j=1;j<=n;j++)
        {
            if(nearvex[j]!=-1&&lowcost[j]<minx)
            {
                v=j;
                minx=lowcost[j];
            }
        }
        if(v!=-1)//表示没找到权值最小的边
        {
            //printf("%d %d %d\n",nearvex[v],v,lowcost[v]);依次输出选择的边 边的顶点和权值
            nearvex[v]=-1;
            sumweight+=lowcost[v];
            for(int j=1;j<=n;j++)
            {
                if(nearvex[j]!=-1&&Edge[v][j]<lowcost[j])
                {
                    lowcost[j]=Edge[v][j];
                    nearvex[j]=v;
                }
            }
        }
    }
    //printf("sumweight %d\n",sumweight);
}
int main()
{
    scanf("%d %d",&n,&m);
    init();
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        Edge[u][v]=Edge[v][u]=w;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j) Edge[i][j]=0;
            else if(Edge[i][j]==0) Edge[i][j]=INF;
        }
    prim(1);
    return 0;
}
