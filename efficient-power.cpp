#include <iostream>

#define MOD(x) x % ((int)(1e9 + 7))
typedef long long ll;

ll power_iterative(ll x, ll y)
{
    ll ans = 1;
    x = MOD(x);
    if(x == 0) return 0;
    while(y > 0)
    {
        if(y & 1) ans = MOD(ans * x);
        x = MOD(x * x);
        y = y >> 1;
    }

    return MOD(ans);
}

ll power_recursive(ll x, ll y)
{
    if(y == 0 || x == 1) return 1;
    if(x == 0) return 0;
    if(y & 1) return MOD(x * power_recursive(MOD(x * x), y >> 1));
    return MOD(power_recursive(MOD(x * x), y >> 1));
}

int main(int argc, const char* argv[])
{
    std::cout << power_iterative(250, 25) << '\n';
    std::cout << power_recursive(250, 25) << '\n';

    return 0;
}
