/**
 * Link: https://leetcode.com/problems/heaters/description/
*/

#include <iostream>
#include <vector>
#include <array>
#include <limits>
#include <cassert>
#include <algorithm>

int findClosestHeater(const std::vector<int>& heaters, int house)
{
    int ans = std::numeric_limits<int>::max();
    int start = 0;
    int finish = heaters.size() - 1;

    while(start <= finish)
    {
        int mid = (start + finish) / 2;
        int diff = std::abs(heaters[mid] - house);
        ans = std::min(ans, diff);

        if(heaters[mid] == house) return 0;
        else if(heaters[mid] < house) start = mid + 1;
        else finish = mid - 1;
    }

    return ans;
}

int solve(std::vector<int>& houses, std::vector<int>& heaters)
{
    int ans = std::numeric_limits<int>::min();

    std::sort(heaters.begin(), heaters.end());

    for(int i = 0; i < houses.size(); ++i)
    {
        ans = std::max(findClosestHeater(heaters, houses[i]), ans);
    }
    
    return ans;
}

int solveFaster(std::vector<int>& houses, std::vector<int>& heaters)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = houses.size(), m = heaters.size(), ans = 0;

    std::sort(houses.begin(), houses.end());
    std::sort(heaters.begin(), heaters.end());

    int i = 0, j = 0, k = i == m - 1 ? INT_MAX : (heaters[i] + heaters[i + 1]) / 2;
    
    while(j < n)
    {
        if(houses[j] <= k)
            ans = std::max(std::abs(houses[j++] - heaters[i]), ans);
        else
            k = ++i == m - 1 ? INT_MAX : (heaters[i] + heaters[i + 1]) / 2;
    }

    return ans;
}

int findRadius(std::vector<int>& houses, std::vector<int>& heaters)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n=houses.size(), m=heaters.size(), ans=0;
    std::sort(houses.begin(), houses.end());
    std::sort(heaters.begin(), heaters.end());

    for(int i=0, j=0, k = i == m-1 ? INT_MAX : heaters[i]+(heaters[i+1]-heaters[i])/2; j<n; ) {    
        if(houses[j]<=k) {
            ans = std::max(ans, std::abs(heaters[i]-houses[j++]));
        } else {
            k=++i==m-1? INT_MAX : (heaters[i+1]+heaters[i])/2;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    std::vector<int> house1 {1,2,3,4};
    std::vector<int> heater1 { 1,4 };
    assert(solve(house1, heater1) == 1);
    assert(solveFaster(house1, heater1) == 1);

    std::vector<int> house2 {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> heater2 { 2,6 };
    assert(solve(house2, heater2) == 4);
    assert(solveFaster(house2, heater2) == 4);

    std::vector<int> house3 {1,2,3,4};
    std::vector<int> heater3 { 1,2,3,4 };
    assert(solve(house3, heater3) == 0);
    assert(solveFaster(house3, heater3) == 0);

    std::vector<int> house4 { 1,2,3 };
    std::vector<int> heater4 { 2 };
    assert(solve(house4, heater4) == 1);
    assert(solveFaster(house4, heater4) == 1);

    std::vector<int> house5 { 1,5 };
    std::vector<int> heater5 { 2 };
    assert(solve(house5, heater5) == 3);
    assert(solveFaster(house5, heater5) == 3);

    std::vector<int> house6 { 282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923 };
    std::vector<int> heater6 { 16531729, 74243042, 114807987, 115438165, 137522503, 143542612, 441282327, 784484492, 823378840, 823564440 };
    assert(solve(house6, heater6) == 161834419);
    assert(solveFaster(house6, heater6) == 161834419);

    return 0;
}
