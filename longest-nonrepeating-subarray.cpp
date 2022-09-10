#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define MAX_LENGTH 600

int solution(std::vector<char>& arr)
{
    int ans = 1;
    int tmp_ans = 0;
    int current_candidate = 0;
    std::array<std::array<int, 1000>,600> indexes;

    for(int i = 1; i < arr.size(); ++i)
    {
        // Could be zero as well. Fix it.
        int idx = indexes[current_candidate][(int)arr[i]];

        if(idx)
        {
            ans = std::max(ans, tmp_ans);
            ans = std::max(ans, i - idx);
            tmp_ans = i - idx - 1;
            if(!tmp_ans) ++current_candidate;
        }

        indexes[current_candidate][(int)arr[i]] = i;
        ++tmp_ans;
    }

    return std::max(ans, tmp_ans);
}


int main(int argc, char const *argv[])
{
    std::vector<char> arr1 = { ' ','a','b','c','d','d','f','g','a','b','c','k','1' };
    std::vector<char> arr2 = { ' ','a','a','b','c','b' };
    std::vector<char> arr3 = { ' ','a','a','b','b','b' };
    std::vector<char> arr4 = { ' ','p','w','w','k','e','w' };
    std::vector<char> arr5 = { ' ','b','b','b','b','b' };

    std::cout << solution(arr5) << '\n';


    return 0;
}
