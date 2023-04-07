#include <iostream>
#include <cmath>

#define MOD(x) x % 1000000007
#define MOD1 1000000007
typedef std::uint64_t ll;

    ll power(ll x, ll y)
    {
        ll ans = 1;
        x = MOD(x);
        y = MOD(y);

        while(y > 0)
        {
            if(y & 1)
            {
                ans = MOD(ans * x);
                std::cout << "current abs " << ans << '\n';
            }

            x = MOD(x * x);
            y = y >> 1;
        }

        return MOD(ans);
    }

    long long expn(long long N, long long K){
        if(K==0) return 1;
        if(K==1) return N%MOD1;
        if(K%2 ==0){
            long long temp = expn(N,K/2);
            return (temp*temp)%MOD1;
        }else{
            long long temp = expn(N,K/2);
            temp = (temp*temp)%MOD1;
            return (temp*(N%MOD1))%MOD1;
        }
    }

    ll solve(ll p)
    {
        ll range = std::pow(2, p) - 1;
        return MOD(power(range - 1, range / 2) * MOD(range));
    }


int main(int argc, char const *argv[])
{
    std::cout << expn(8589934592 - 2, (8589934592 - 1) / 2) << '\n';
    std::cout << power(8589934592 - 2, (8589934592 - 1) / 2) << '\n';

    return 0;
}
