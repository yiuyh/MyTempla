#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100010
#define lson x<<1
#define rson ((x<<1)|1)

using namespace std;
long long tree[maxn<<2];
long long lazy[maxn<<2];

void PushUp(int x){
    tree[x] = tree[lson] + tree[rson];
}

void  PushDown(int x){
    if(lazy[x] != 0){
        lazy[lson] += lazy[x];
        lazy[rson] += lazy[x];
        tree[lson] += lazy[x];
        tree[rson] += lazy[x];
        lazy[x] = 0;
    }
}


void build(int x, int l, int r){
    if(l == r){scanf("%lld", &tree[x]); return;}
    int mid = (l+r)>>1;
    build(lson, l, mid);
    build(rson, mid+1, r);
    PushUp(x);
}

int query(int ql, int qr, int x, int l, int r){
    if(ql <= l && r <= qr) return tree[x];
    int mid = (l+r)>>1;
    int ans = 0;
    PushDown(x, (mid-l+1), (r-mid));
    if(ql <= mid) ans += query(ql, qr, lson, l, mid);
    if(qr > mid) ans += query(ql, qr, rson, mid+1, r);
    return ans;
}

void update(int cl, int cr, int num, int x, int l, int r){
    if(cl <= l && r <= cr){
        lazy[x] += num;
        tree[x] += (r-l+1) * num;
        return;
    }
    int mid = l + (r-l)/2;
    PushDown(x);
    if(cl <= mid) update(cl, cr, num, lson, l, mid);
    if(cr > mid) update(cl, cr, num, rson, mid+1, r);
    PushUp(x);
}

int main(){
    return 0;
}
