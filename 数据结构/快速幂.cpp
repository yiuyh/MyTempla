typedef long long ll;
const int mod = 1e+9;
ll pow(ll x, ll n){
    ll res = 1;
    while (n > 0) {
      if(n%2 == 1){
        res = res * x;
        res %= mod;
      }
      x *= x;
      x %= mod;
      n >>= 1;
    }
    return res;
}

public static BigInteger QuickPow02 (BigInteger n, BigInteger Mod)//循环版快速幂
    {
        BigInteger ans = BigInteger.valueOf(1);
        BigInteger base = BigInteger.valueOf(2);//底数
        BigInteger x =  BigInteger.valueOf(0);
        while(n.compare(x) > 0){
            if(n % 2 == 1)
                ans = ans.multiply(base).mod(Mod);//ans * base
            n /= 2;
            base = base.multiply(base).mod(Mod);//base * base
        }
        return ans;
}
