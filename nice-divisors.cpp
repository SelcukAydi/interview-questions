/**
 * Link: https://leetcode.com/problems/maximize-number-of-nice-divisors/
*/

#include <iostream>

#define MOD(x) x % 1000000007
typedef long long ll;

ll power(ll x, ll y)
{
    ll ans = 1;
    if(y == 0) return ans;

    while(y > 0)
    {
        if(y & 1 == 1) ans = MOD(ans * x);
        y = y >> 1;
        x = MOD(x * x);
    }

    return MOD(ans);
}

ll solve(ll num)
{
    if(num <= 3) return num;

    ll three_divisors = num / 3;
    ll three_mod = num % 3;
    if(three_mod == 1)
    {
        --three_divisors;
        three_mod = 4;
    }
    return MOD(power(3, three_divisors) * (three_mod == 0 ? 1 : three_mod));
}


int main(int argc, char const *argv[])
{
    std::cout << solve(8) << '\n';
    
    return 0;
}