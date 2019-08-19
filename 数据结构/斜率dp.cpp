#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int dp[500005];
int q[500005];
int sum[500005];
int head,tail,n,m;

int getDP(int i,int j){}
int getUP(int j,int k)  {}//yj-yk的部分
int getDOWN(int j,int k) {}//xj-xk的部分

for(i=1;i<=n;i++){
    while(head+1<tail && getUP(q[head+1],q[head])<=sum[i]*getDOWN(q[head+1],q[head]))
        head++;
    dp[i]=getDP(i,q[head]);
    while(head+1<tail && getUP(i,q[tail-1])*getDOWN(q[tail-1],q[tail-2])<=getUP(q[tail-1],q[tail-2])*getDOWN(i,q[tail-1]))
        tail--;         //Y(i,q[tail])*X(i,q[tail-1])<=Y(i,q[tail-1])*X(i,q[tail])
    q[tail++]=i;
}

ll d[MAX],b[MAX];
ll sum[MAX];
int q[MAX];
double K[MAX];//记录斜率
//int R=0; d[0]=0; q[0]=0;
ll Y(int x,int y){return d[x]+sum[x]*sum[x]-(d[y]+sum[y]*sum[y]);}//Y[x]-Y[y];
ll X(int x,int y){return 2*(sum[x]-sum[y]);}                      //X[x]-X[y];

for(int i=1;i<=n;i++){
        int index=lower_bound(K+1,K+R+1,(sum[i]-b[i])*1.0)-K-1;
        index=q[index];
        d[i]=d[index]+(sum[i]-b[i]-sum[index])*(sum[i]-b[i]-sum[index]);
        while(0<R&&Y(i,q[R])*X(i,q[R-1])<=Y(i,q[R-1])*X(i,q[R]))R--;
        if(X(i,q[R])==0)K[R+1]=1e18;
        else K[R+1]=1.0*Y(i,q[R])/X(i,q[R]);
        q[R+1]=i;
        R++;
}
