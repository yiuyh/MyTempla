//区间修改区间查询
void Update( int h , int x )  //单点更新
 {
    for(int i = h; i <= n; i += i & -i)
    {
        sum1[i] += x ;
        sum2[i] += x * h;
    }
}

void Range_Update(int l, int r, int val)  //区间更新
{
    Update(l, val) ;
    Update(r + 1, -val);
}

int Query(int h)  //单点前缀查询
{
    int res = 0;
    for(int i = h ; i ; i -= i & -i)
        res += (h + 1) * sum1[i] - sum2[i];
    return res;
}

int Range_Query(int l, int r) //区间查询
{
    return Query(r) - Query(l - 1);
}
