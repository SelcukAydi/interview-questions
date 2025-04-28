/**
 * Link: https://www.techiedelight.com/find-index-0-replaced-get-maximum-length-sequence-of-continuous-ones/
 * Given a binary array, find the index of 0 to be replaced with 1 to get the maximum length sequence of continuous ones.
 * For example, consider the array { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 }. 
 * We need to replace index 7 to get the continuous sequence of length 6 containing all 1’s.
*/

#include <iostream>
#include <vector>
#include <cassert>

int solve1(const std::vector<int>& arr)
{
    std::size_t n = arr.size();
    int ans = -1;
    int left = 0;
    int max_len = 0;
    int last_zero = 0;
    int count = 0;

    for(int i = 0; i < n; ++i)
    {
        if(arr[i] == 0)
        {
            ++count;
            last_zero = i;
        }

        if(count == 2)
        {
            while(arr[left++]);
        }

        if(i - left + 1 > max_len)
        {
            max_len = i - left + 1;
            ans = last_zero;
        }
    }

    return ans;
}

int solve2(const std::vector<int>& arr)
{
    int ans = -1;
    int starting_zero_idx = 0;
    int max_len = 0;
    int count = 0;
    int left = 0;

    for(int i = 0; i < arr.size(); ++i)
    {
        if(arr[i] == 0)
        {
            ++count;
            starting_zero_idx = i;
        }

        if(count == 2)
        {
            left = starting_zero_idx + 1;
        }

        if(i - left + 1 > max_len)
        {
            max_len = i - left + 1;
            ans = starting_zero_idx;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    assert(solve1({1,1,0,1,1,1,1,0,1,1}) == 2);
    assert(solve1({0, 0, 1, 0, 1, 1, 1, 0, 1, 1}) == 7);

    assert(solve2({1,1,0,1,1,1,1,0,1,1}) == 2);
    assert(solve2({0, 0, 1, 0, 1, 1, 1, 0, 1, 1}) == 7);

    std::cout << "All Passed!\n";
    
    return 0;
}
