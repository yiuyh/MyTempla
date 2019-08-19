//求最近距离
#include<bits/stdc++.h>
using namespace std;

void chmin(int &x,int y)
{
    if(x>y)x=y;
}
void chmax(int &x,int y)
{
    if(x<y)x=y;
}

const int N=500005,T=N*2,inf=1000000001;
struct point
{
    int x,y,id;
}p[T];int pn;
int rt;
int dy[N];
int qx[N],qy[N];
bool type[N];//0=add 1=ask

bool x_xiao(const point &p1,const point &p2)
{
    return p1.x<p2.x||(p1.x==p2.x&&p1.y<p2.y);
}
bool y_xiao(const point &p1,const point &p2)
{
    return p1.y<p2.y||(p1.y==p2.y&&p1.x<p2.x);
}
int f[T],c[T][2];
int mx_x[T],mn_x[T],mx_y[T],mn_y[T];
struct state
{
  int f1,f2,f3,f4;
  void init(int x,int y)
  {
       f1=-x+y;f2=x+y;
       f3=-x-y;f4=x-y;
  }
  friend void up(state &x,const state &y)
  {
        chmin(x.f1,y.f1);
        chmin(x.f2,y.f2);
        chmin(x.f3,y.f3);
        chmin(x.f4,y.f4);
  }
}s[T];
void sc(int y,int x,bool d)//建立 y是x的爸爸 的关系
{
    f[x]=y;c[y][d]=x;
    up(s[y],s[x]);
    chmax(mx_x[y],mx_x[x]);chmax(mx_y[y],mx_y[x]);
    chmin(mn_x[y],mn_x[x]);chmin(mn_y[y],mn_y[x]);
}
int build(int l,int r,bool d)
{
    int rt=l+r>>1;
    if(!d) nth_element(p+l,p+rt,p+r+1,x_xiao);
    else nth_element(p+l,p+rt,p+r+1,y_xiao);

    if(p[rt].id==N) s[rt].init(mx_x[rt]=mn_x[rt]=p[rt].x,mx_y[rt]=mn_y[rt]=p[rt].y);
    else
    {
        dy[p[rt].id]=rt;
        s[rt]=(state){inf,inf,inf,inf};
        mx_x[rt]=mx_y[rt]=-inf;mn_x[rt]=mn_y[rt]=inf;
    }

    if(rt!=l)sc(rt,build(l,rt-1,!d),0);
    if(rt!=r)sc(rt,build(rt+1,r,!d),1);

    return rt;
}

int x,y,a1,a2,a3,a4,ans;
int get_dis(int k)//估价
{
    if(!k)return inf;
    int ans=0;
    if(x>mx_x[k])ans+=x-mx_x[k]; else
    if(x<mn_x[k])ans+=mn_x[k]-x;
    if(y>mx_y[k])ans+=y-mx_y[k]; else
    if(y<mn_y[k])ans+=mn_y[k]-y;
    return ans;
}
void qiu(int k)
{
    //如果在四个矩形中的一个，则直接更新答案并返回
    if(mx_y[k]<=y)//under
    {
        if(mx_x[k]<=x) {chmin(ans,a3+s[k].f3);return ;}//left
        if(mn_x[k]>=x) {chmin(ans,a4+s[k].f4);return ;}//right
    }
    else
    if(mn_y[k]>=y)//above
    {
        if(mx_x[k]<=x) {chmin(ans,a1+s[k].f1);return ;}
        if(mn_x[k]>=x) {chmin(ans,a2+s[k].f2);return ;}
    }
    if(p[k].id==N)chmin(ans,abs(x-p[k].x)+abs(y-p[k].y));

    int cl=c[k][0],cr=c[k][1];
    int dl=get_dis(cl),dr=get_dis(cr);
    if(dl<dr)
    {
        if(dl>=ans)return ;
        qiu(cl);
        if(dr>=ans)return ;
        qiu(cr);
    }
    else
    {
        if(dr>=ans)return ;
        qiu(cr);
        if(dl>=ans)return ;
        qiu(cl);
    }
}

void up_to_rt(int k)//插入
{
    p[k].id=N;
    state now;int x,y;
    now.init(x=p[k].x,y=p[k].y);
    for(;k;k=f[k])
    {
        up(s[k],now);
         chmax(mx_x[k],x);chmin(mn_x[k],x);
         chmax(mx_y[k],y);chmin(mn_y[k],y);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].id=N;
    }
    pn=n;
    for(int i=1;i<=m;++i)
    {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if(t==1)
        {
            p[++pn]=(point){x,y,i};
        }
        else
        {
            type[i]=1;
            qx[i]=x;qy[i]=y;
        }
    }
    rt=build(1,pn,0);
    for(int i=1;i<=m;++i)
    if(type[i])
    {
        x=qx[i];y=qy[i];ans=inf;a1=x-y;a2=-x-y;a3=x+y;a4=y-x;
        qiu(rt);
        printf("%d\n",ans);
    }
    else up_to_rt(dy[i]);
}
