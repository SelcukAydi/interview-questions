#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int findSecondAndThird(std::vector<int>& arr, int target, int first)
{
    int left = first + 1;
    int right = arr.size() - 1;
    int min_dist = std::numeric_limits<int>::max();
    int ans = 0;

    while(left < right)
    {
        int sum = arr[first] + arr[left] + arr[right];
        if(sum == target) return sum;
        int dist = std::abs(sum - target);

        if(dist < min_dist)
        {
            min_dist = dist;
            ans = sum;
        }

        if(sum < target)
        {
            ++left;
        }
        else
        {
            --right;
        }
    }

    return ans;
}

int solution(std::vector<int>& arr, int target)
{
    std::sort(arr.begin(), arr.end());

    long long ans = std::numeric_limits<int>::max();

    for(int first = 0; first < arr.size() - 2; ++first)
    {
        if(first != 0 && arr[first] == arr[first - 1]) continue;
        long long tmp = findSecondAndThird(arr, target, first);
        ans = std::abs(ans - target) < std::abs(tmp - target) ? ans : tmp;
    }

    return ans;
}


int main(int argc, char const *argv[])
{
    std::vector<int> arr1 = { -1,2,1,-4 };

    std::cout << solution(arr1, 1) << '\n';
    
    return 0;
}
