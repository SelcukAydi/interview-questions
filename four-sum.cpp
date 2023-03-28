/**
 * Link: https://leetcode.com/problems/4sum/description/
*/

#include <iostream>
#include <vector>
#include <algorithm>

void printArr(const std::vector<std::vector<int>>& arr)
{
    for(int i = 0; i < arr.size(); ++i)
    {
        std::cout << "[[";

        for(const auto& j : arr[i])
        {
            std::cout << j << ',';
        }

        std::cout << "]]";
    }
}

typedef long long ll;

std::vector<std::vector<int>> findQuadSums(std::vector<int>& arr, int target)
{
    auto n = arr.size();
    std::vector<std::vector<int>> ans;
    std::sort(arr.begin(), arr.end());

    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            int sum = arr[i] + arr[j];
            int left = j + 1;
            int right = n - 1;
            int new_target = target - sum;

            while(left < right)
            {
                ll inner_sum = arr[left] + arr[right];
                
                if(inner_sum < new_target)
                    ++left;
                else if(inner_sum > new_target)
                    --right;
                else
                {
                    ans.push_back({arr[i], arr[j], arr[left], arr[right]});

                    while(left < right && arr[left] == ans.back()[2])
                        ++left;
                    while(left < right && arr[right] == ans.back()[3])
                        --right;
                }
            }

            while(j + 1 < n && arr[j] == arr[j + 1])
                ++j;
        }

        while(i + 1 < n && arr[i] == arr[i + 1])
            ++i;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<int> arr1{ -2, -1, 0, 0, 1, 2 };
    std::vector<int> arr2{ -1, -1, 1, 3, 5, 7 };
    std::vector<int> arr3{ 2, 2, 2, 2, 2 };
    std::vector<int> arr4{ 0, 0, 0, 0 };
    std::vector<int> arr5{ -2, -1, -1, 1, 1, 2, 2 };
    std::vector<int> arr6{ -3,-2,-1,0,0,1,2,3 };
    // solve(arr1, 0);
    // solve(arr2, 6);
    // printArr(solve(arr3, 8));
    // printArr(solve(arr4, 1));
    // printArr(solve(arr5, 0));
    printArr(findQuadSums(arr6, 0));

    return 0;
}
