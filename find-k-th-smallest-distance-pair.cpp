/**
 * Link => https://leetcode.com/problems/find-k-th-smallest-pair-distance/
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool isValidDistance(std::vector<int>& arr, int d, int k)
{
    int total = 0;
    int j = 1;

    for(int i = 0; i < arr.size(); ++i)
    {
        while(j < arr.size() && (arr[j] - arr[i]) <= d) ++j;
        --j;
        total += (j - i);
    }

    return total >= k;
}

int findSmallestPair(std::vector<int>& arr, int k)
{
    std::sort(arr.begin(), arr.end());
    int begin = 0;
    int end = arr[arr.size() - 1] - arr[0];

    while(begin < end)
    {
        int mid = (begin + end) / 2;

        if(isValidDistance(arr, mid, k))
        {
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
    }

    return begin;
}

int findSmallestPairSlow(std::vector<int>& arr, int k)
{
    int freqs[1024] = { 0 };
    int min_heap[1024] = { 0 };

    std::sort(arr.begin(), arr.end());
    
    for(int i = 0; i < arr.size(); ++i)
    {
        freqs[arr[i]]++;
    }

    std::make_heap(std::begin(min_heap), std::end(min_heap), std::greater<>{});

    for(int i = 0; i < arr.size() - 1; ++i)
    {
        int diff = arr[i + 1] - arr[i];
        arr.push_back(diff);
        std::push_heap(std::begin(min_heap), std::end(min_heap), std::greater<>{});
    }

    int counter = 0;

    for(int i = 0; i < 1024; ++i)
    {
        if(!freqs[i]) continue;
        counter += (freqs[i] - 1) * freqs[i] / 2;
    }

    return counter;
}


int main(int argc, char const *argv[])
{
    std::vector<int> arr1 = {1,2,3,4,5};
    std::vector<int> arr2 = {1,3,1};
    std::vector<int> arr3 = {1,1,3,4,5,6,6,6,6,7,8};
    

    // std::cout << findSmallestPair(arr2, 2) << '\n';

    std::cout << findSmallestPairSlow(arr3, 5) << '\n';

    return 0;
}
