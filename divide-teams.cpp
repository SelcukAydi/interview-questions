/**
 * Link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/
*/

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int check(const std::vector<int>& arr, int target, ll& total_product)
{
    int ans = 0;
    std::size_t n = arr.size();
    int left = 0, right = n - 1;
    int sum = 0;
    total_product = 0;
    
    while(left < right)
    {
        total_product += arr[left] * arr[right];
        sum = arr[left++] + arr[right--];

        if(sum < target)
        {
            ans = -1;
            break;
        }
        else if(sum > target)
        {
            ans = 1;
            break;
        }
    }

    return ans;
}

int solve(std::vector<int>& arr)
{
    ll ans = -1;
    std::size_t n = arr.size();
    int start = 2, finish = 2000;
    std::sort(arr.begin(), arr.end());

    while(start <= finish)
    {
        ll total_product = 1;
        int mid = (start + finish) / 2;

        int c = check(arr, mid, total_product);

        if(c == 0)
        {
            ans = total_product;
            break;
        }

        if(c == -1)
        {
            finish = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int solveFaster(std::vector<int>& arr)
{
    ll ans = 0;
    std::size_t n = arr.size();
    std::vector<int> teams;

    std::sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;

    while(left < right)
    {
        teams.push_back(arr[left] + arr[right]);
        ans += arr[left++] * arr[right--];
    }

    for(int i = 0; i < teams.size() - 1; ++i)
    {
        if(teams[i] != teams[i + 1]) return -1;
    }

    return ans;
}

long long solveMuchFaster(std::vector<int>& skill)
{
    int n=skill.size();
    std::sort(skill.begin(), skill.end());
    long long ans=0;
    long long req=skill[0]+skill[n-1];
    
    for(int i=0;i<n/2;i++)
    {
        if((skill[i]+skill[n-i-1]) == req)
        {
            ans+=skill[i]*skill[n-i-1];
        }
        else
        {
            return -1;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<int> arr1 { 3,2,5,1,3,4 };
    std::cout << solve(arr1) << '\n';
    std::cout << solveFaster(arr1) << '\n';
    std::cout << solveMuchFaster(arr1) << '\n';

    std::vector<int> arr2 { 3,4 };
    std::cout << solve(arr2) << '\n';
    std::cout << solveFaster(arr2) << '\n';
    std::cout << solveMuchFaster(arr2) << '\n';
    
    std::vector<int> arr3 { 1,1,2,3 };
    std::cout << solve(arr3) << '\n';
    std::cout << solveFaster(arr3) << '\n';
    std::cout << solveMuchFaster(arr3) << '\n';

    return 0;
}
