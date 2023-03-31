#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

// Lesson learned: If we need to query an information frequently and 
// if it is related to index, a number, range etc. then we can use
// prefi sum technique to accumalate the information.
//

int solve(std::vector<int>& arr, int target)
{
    int ans = 0;
    int MOD = 1e9 + 7;
    std:size_t n = arr.size();
    std::vector<int> pows(n, 1);

    // Accumulate the number of possible subsequences.
    for(int i = 1; i < n; ++i)
    {
        pows[i] = (pows[i - 1] * 2) % MOD;
    }

    // Sort the array.
    std::sort(arr.begin(), arr.end());
    
    // Two pointer to find the each subsequence possible.
    int left = 0;
    int right = n - 1;

    while(left <= right)
    {
        if(arr[left] + arr[right] > target)
            --right;
        else
            ans = (ans + pows[right - left++]) % MOD;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<int> arr1 { 3,5,6,7 };
    std::cout << solve(arr1, 9) << '\n';
    
    std::vector<int> arr2 { 3,3,6,8 };
    std::cout << solve(arr2, 10) << '\n';

    std::vector<int> arr3 { 2,3,3,4,6,7 };
    std::cout << solve(arr3, 12) << '\n';

    std::vector<int> arr4 { 6,10,12,3,29,21,12,25,17,19,16,
    1,2,24,9,17,25,22,12,22,26,24,24,11,3,7,24,
    5,15,30,23,5,20,10,19,20,9,27,11,4,23,4,4,
    12,22,27,16,11,26,10,23,26,16,21,24,21,17,13,21,9,16,17,27 };
    std::cout << solve(arr4, 26) << '\n';

    return 0;
}
