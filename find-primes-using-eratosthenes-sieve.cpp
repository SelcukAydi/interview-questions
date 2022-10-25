#include <iostream>
#include <cstring>

int solve(int n)
{
    int ans = 0;
    bool primes[n + 1];
    std::memset(primes, true, sizeof(primes));

    for(int i = 2; i * i <= n; ++i)
    {
        if(primes[i])
        {
            for(int j = i * i; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; ++i)
    {
        if(primes[i]) ++ans;
    }

    return ans;
}


int main(int argc, char const *argv[])
{
    std::cout << solve(5) << '\n';

    return 0;
}
