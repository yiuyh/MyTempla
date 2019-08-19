//Define
#define lson rt << 1        // 左儿子
#define rson rt << 1 | 1    // 右儿子
#define Lson l, m, lson     // 左子树
#define Rson m + 1, r, rson // 右子树
void PushUp(int rt);        // 用lson和rson更新rt
void PushDown(int rt[, int m]);                 // rt的标记下移，m为区间长度（若与标记有关）
void build(int l, int r, int rt);               // 以rt为根节点，对区间[l, r]建立线段树
void update([...,] int l, int r, int rt)        // rt[l, r]内寻找目标并更新
int query(int L, int R, int l, int r, int rt)   // rt[l, r]内查询[L, R]

//单点更新
const int maxn = "Edit";
int sum[maxn << 2]; // sum[rt]用于维护区间和
void PushUp(int rt) { sum[rt] = sum[lson] + sum[rson]; }
void build(int l, int r, int rt)
{
    if (l == r)
    {
        scanf("%d", &sum[rt]); // 建立的时候直接输入叶节点
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    PushUp(rt);
}
void update(int p, int add, int l, int r, int rt)
{
    if (l == r)
    {
        sum[rt] += add;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, add, Lson);
    else
        update(p, add, Rson);
    PushUp(rt);
}
int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return sum[rt];
    int m = (l + r) >> 1, s = 0;
    if (L <= m) s += query(L, R, Lson);
    if (m < R) s += query(L, R, Rson);
    return s;
}

//区间更新
const int maxn = "Edit";
int seg[maxn << 2], sum[maxn << 2]; // seg[rt]用于存放懒惰标记，注意PushDown时标记的传递
void PushUp(int rt) { sum[rt] = sum[lson] + sum[rson]; }
void PushDown(int rt, int m)
{
    if (seg[rt] == 0) return;
    seg[lson] += seg[rt];
    seg[rson] += seg[rt];
    sum[lson] += seg[rt] * (m - (m >> 1));
    sum[rson] += seg[rt] * (m >> 1);
    seg[rt] = 0;
}
void build(int l, int r, int rt)
{
    seg[rt] = 0;
    if (l == r)
    {
        scanf("%lld", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    PushUp(rt);
}
void update(int L, int R, int add, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        seg[rt] += add;
        sum[rt] += add * (r - l + 1);
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, add, Lson);
    if (m < R) update(L, R, add, Rson);
    PushUp(rt);
}
int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return sum[rt];
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1, ret = 0;
    if (L <= m) ret += query(L, R, Lson);
    if (m < R) ret += query(L, R, Rson);
    return ret;
}
