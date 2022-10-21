/**
 * Link: https://leetcode.com/problems/number-of-digit-one/
*/

#include <iostream>
#include <string>
#include <algorithm>

typedef long long ll;

ll solve(int n)
{
    ll ans = 0;

    for(ll i = 1; i <= n; i *= 10)
    {
        ll divisor = 10 * i;
        ans += (n / divisor) * i + std::min(std::max(n % divisor - i + 1, 0LL), i);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    
    std::cout << solve(1234) << '\n';

    return 0;
}
