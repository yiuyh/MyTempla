#include<iostream>

using namespace std;

const int maxn = 100010;

struct node{
    int val;
    int e;
    int next;
};

node edge[maxn];
int cnt = 1;
int head[maxn];

void add(int u, int v, int val){
    edge[cnt].val = val;
    edge[cnt].e = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

int main(){

    return 0;
}
