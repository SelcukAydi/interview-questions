/**
 * Link => https://leetcode.com/problems/reverse-integer/
 */

#include <iostream>

#define MAX_NUMBER 2147483647
#define MIN_NUMBER -2147483648

long long getReverse(int x)
{
    long long ans = 0;
    int tmp_x = std::abs(x);
    int digit_count = 0;

    for(int i = 0; i < 10; ++i)
    {
        int digit = tmp_x % 10;
        tmp_x /= 10;
        ans *= 10;
        ans += digit;
        if(!tmp_x) break;
        ++digit_count;
    }

    return x < 0 ? (-1 * ans) : ans;
}

int solution(int x)
{
    long long y = getReverse(x);
    if(x < 0 && y < MIN_NUMBER) return 0;
    if(x > 0 && y > MAX_NUMBER) return 0;
    return y;
}


int main(int argc, char const *argv[])
{
    std::cout << "Reverse is " << solution(-2147483641) << '\n';

    return 0;
}
