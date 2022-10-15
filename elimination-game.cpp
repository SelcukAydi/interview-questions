/**
 * Link: https://leetcode.com/problems/elimination-game/
*/

#include <iostream>

int solve(int n)
{
    int min = 1;
    int max = n;
    int current_dist = 1;
    bool left = true;

    while(min < max)
    {
        if(n & 1)
        {
            min = min + current_dist;
            max = max - current_dist;
        }
        else
        {
            if(left)
            {
                min = min + current_dist;
            }
            else
            {
                max = max - current_dist;
            }
        }

        n = n >> 1;
        left = !left;
        current_dist = current_dist << 1;
    }
    
    return min;
}

int main(int argc, char const *argv[])
{
    std::cout << solve(1) << '\n';
    
    return 0;
}
