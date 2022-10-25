/**
 * Link: https://leetcode.com/problems/count-good-numbers/
*/

#include <iostream>

#define MOD(x) x % (1000000000 + 7)
typedef long long ll;

const int primes = 4;
const int evens = 5;

ll power(ll x, ll y)
{
    if(y == 0) return 1;
    if(y == 1) return x;

    ll ans = 1;

    while(y > 0)
    {
        if(y & 1)
        {
            ans = MOD(ans * x);
        }

        x = MOD(x * x);
        y = y >> 1;
    }

    return ans;
}

ll solve(ll n)
{
    ll even_idx;
    ll odd_idx;
    odd_idx = n / 2;
    even_idx = n - odd_idx;
    // if(n & 1) odd_idx--;
    if(n < 2)
    {
        even_idx = 1;
        odd_idx = 0;
    }
    return MOD(MOD(power(evens, even_idx)) * MOD(power(primes, odd_idx)));
}

int main(int argc, char const *argv[])
{
    std::cout << solve(3) << '\n';


    return 0;
}
