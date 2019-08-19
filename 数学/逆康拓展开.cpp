//ans存的是比当前位数小的数有几位
//cnt里存逆序字符，
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fact[21];
int ans[21];
string cnt;
string ch;
void init()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=20;i++)
    {
        fact[i]=fact[i-1]*i;
    }
}
void reverse_cantor(int n,int m)//求第n位的串。串长为m;
{
    //cout << n << " " << m << endl;
    for(int i=m-1;i>=0;i--)
    {
        ans[i]=n/fact[i];
        n=n%fact[i];
        //cout << ans[i] << " " << i << endl;
    }
}
void decantor(int n)
{
    for(int i=n-1;i>=0;i--)
    {
        sort(ch.begin(), ch.end());
        for(int j=0;j<n;j++)
        {
            if(ch[j]!=0)
            {
                cnt[i]=ch[j+ans[i]];
                //cout << j+ans[i] << " " << j << " " << ans[i]  << endl;
                ch[j+ans[i]]=0;
                //cout << cnt[i] << " " << ans[i] << " " << i << endl;
                break;
            }
            //cout << flag << endl
        }
    }
}
int main()
{
    init();
    int n;
    cin >> n;
    cin >> ch;
    int len = ch.size();
    reverse_cantor(n,len);
    decantor(len);
    for(int i=len-1;i>=0;i--)
        cout << cnt[i] << endl;
    return 0;
}
