/**
 * Link: https://leetcode.com/problems/product-of-array-except-self/description/
*/

#include <iostream>
#include <vector>
#include <array>

int findDivisor(int num, int dem)
{
    if(num == 0 || dem == 0) return 0;

    int left = 1;
    int right = num;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(mid * dem == num)
        {
            return mid;
        }

        if(mid * dem > num)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return 0;
}

std::vector<int> solveSlower(const std::vector<int>& arr)
{
    std::vector<int> ans(arr.size(), 0);
    int arr_product = 1;
    int total_zeros = 0;

    for(int i = 0; i < arr.size(); ++i)
    {
        if(arr[i] == 0)
        {
            ++total_zeros;
            continue;
        }

        arr_product *= arr[i];
    }

    for(int i = 0; i < arr.size(); ++i)
    {
        if(arr[i] == 0 && total_zeros == 1)
        {
            ans[i] = arr_product;
        }
        else if(total_zeros > 0)
        {
            ans[i] = findDivisor(0, std::abs(arr[i]));
        }
        else
        {
            ans[i] = findDivisor(std::abs(arr_product), std::abs(arr[i]));
        }

        if(arr_product < 0)
        {
            if(arr[i] > 0)
                ans[i] = -ans[i];
        }
        else
        {
            if(arr[i] < 0)
                ans[i] = -ans[i];
        }
    }

    return ans;
}

std::vector<int> solveFaster(const std::vector<int>& arr)
{
    std::size_t n = arr.size();
    std::vector<int> ans(n, 0);

    int product = 1;

    // Left pass. Accumulating the left prefix products.
    //
    for(int i = 0; i < n; ++i)
    {
        ans[i] = product;
        product *= arr[i];
    }

    product = 1;

    // Right pass. Accumulating the right prefix products.
    //
    for(int i = n - 1; i >= 0; --i)
    {
        ans[i] = product * ans[i];
        product *= arr[i];
    }

    return ans;
}

void printArr(const std::vector<int>& arr)
{
    for(const auto num : arr)
    {
        std::cout << num << ' ';
    }

    std::puts("");
}

int main(int argc, char const *argv[])
{
    // printArr(solve({-1,2,3,4}));
    // printArr(solve({-1,1,0,-3,3}));
    // printArr(solve({1,2,3}));
    // printArr(solve({4,3,2,1,2}));
    // std::cout << findDivisor(48, 1) << '\n';
    // printArr(solve1({1,2,3,4}));

    printArr(solveFaster({1,2,3,4}));

    return 0;
}