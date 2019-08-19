#include<cstdio>
#include<cctype>
#include<set>
#include<vector>
#include<utility>
#include<algorithm>
#define IT set<node>::iterator

int Read()
{
    int x=0;char c=getchar();
    while(!isdigit(c))
    {
        c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+(c^48);
        c=getchar();
    }
    return x;
}

using std::set;
using std::vector;
using std::pair;

typedef long long LL;
const int MOD7 = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int imax_n = 1e5 + 7;

struct node
{
    int l,r;
    mutable bool v;
    node(int L, int R=-1, bool V=0):l(L), r(R), v(V) {}
    bool operator<(const node& o) const
    {
        return l < o.l;
    }
};

set<node> s;

//split(pos)操作是指将原来含有pos位置的节点分成两部分：[l,pos−1]和[pos,r]
IT split(int pos)
{
    IT it = s.lower_bound(node(pos));
    if (it != s.end() && it->l == pos) return it;
    --it;
    int L = it->l, R = it->r;
    bool V = it->v;
    s.erase(it);
    s.insert(node(L, pos-1, V));
    return s.insert(node(pos, R, V)).first;
    //这里利用了pair<iterator,bool> insert (const value_type& val)的返回值
}

//ass♂ign操作迅速减小set的规模
void assign_val(int l, int r, bool val)
{
    IT itr = split(r+1), itl = split(l);
    s.erase(itl, itr);
    //void erase (iterator first, iterator last)可删除[first,last)区间
    s.insert(node(l, r, val));
}

void add(int l, int r, LL val=1){
    IT itr = split(r+1),itl = split(l);
    for (; itl != itr; ++itl) itl->v += val;
}//区间加上某个值

LL rank(int l, int r, int k)
{
    vector<pair<LL, int> > vp;
    IT itr = split(r+1),itl = split(l);
    vp.clear();
    for (; itl != itr; ++itl)
        vp.push_back(pair<LL,int>(itl->v, itl->r - itl->l + 1));
    sort(vp.begin(), vp.end());
    for (vector<pair<LL,int> >::iterator it=vp.begin();it!=vp.end();++it)
    {
        k -= it->second;
        if (k <= 0) return it->first;
    }
    return -1LL;
}//区间第K小


int sum(int l, int r)
{
    IT itr = split(r+1),itl = split(l);
    int res = 0;
    for (; itl != itr; ++itl)
        res += itl->v ? itl->r - itl->l + 1 : 0;
    return res;
}//区间和

void rev(int l, int r)
{
    IT itr = split(r+1), itl = split(l);
    for(; itl != itr; ++itl)
    {
        itl->v ^= 1;
    }
}//区间抑或1

int conti(int l,int r){
    int res=0,temp=0;
    IT itr = split(r+1),itl = split(l);
    for(; itl != itr; ++itl)
    {
        if(itl->v == false)
        {
            res = std::max(res, temp);
            temp=0;
        }
        else
        {
            temp += itl->r - itl->l + 1;
        }
    }
    return std::max(res, temp);
} //区间连续1的最大数量
//https://www.luogu.org/blog/ACdreamer/chtholly-tree
