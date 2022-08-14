/**
 * Link => https://www.interviewbit.com/problems/matrix-median/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

int solution(const std::vector<std::vector<int>>& arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int begin = std::numeric_limits<int>::max();
    int end = std::numeric_limits<int>::min();

    // Find the min item in the while matrix.
    //
    for(int i = 0; i < arr.size(); ++i)
    {
        begin = std::min(begin, arr[i][0]);
    }

    // Find the max item in the while matrix.
    // 
    for(int i = 0; i < arr.size(); ++i)
    {
        end = std::max(end, arr[i][m-1]);
    }

    // Total items in the matrix.
    //
    int k = (begin * end) / 2;

    // Binary search between [min, max] to find the median.
    //
    while(begin < end)
    {
        // This is not the real candidate.
        // The real candidate is candidate + 1.
        //
        int candidate = (begin + end) / 2;

        // Total items on the left side of the candidate.
        //
        int leftCounter = 0;

        // Find the total left items of the candidate + 1.
        //
        for(int i = 0; i < n; ++i)
        {
            // The real candidate is plus 1 because upper_bound returns the first greater element
            // than the given argument. Here the argument is candidate.
            // More clearly, since the candidate is also counted by upper_bound method
            // we actaully test candidate + 1 -th item. Suppose you have
            // A = { 1,2,3,4,5 }. Here 3 is the median. The upper_bound
            // will return 3 if the candidate is 3 cause 3 <= 3 is true.
            // Upper bound will return the first item bigger than candidate.
            // So our answer potantial answer for this iteration is candidate + 1.
            // Moreover, this solution works for A = { 2,2,2,2,2,3,3,3,3 } and etc... as well.
            //
            leftCounter += std::upper_bound(arr[i].begin(), arr[i].end(), candidate) - arr[i].begin();
        }

        // If the total items on the left side are less than the expected value
        // then begin will start from the real candidate.
        //
        if(leftCounter <= k)
        {
            begin = candidate + 1;
        }

        // Otherwise narrow the end by the candidate.
        //
        else
        {
            end = candidate;
        }
    }

    return begin;
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> arr1 = { {1,3,5}, {2,6,9}, {3,6,9} };
    std::cout << solution(arr1) << '\n';

    return 0;
}
