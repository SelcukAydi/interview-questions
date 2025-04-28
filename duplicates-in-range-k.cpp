#include <iostream>
#include <vector>
#include <unordered_map>

void solve1(const std::vector<int>& arr, int k)
{
    std::unordered_map<int, int> m;
    bool found = false;

    for(int i = 0; i < arr.size(); ++i)
    {
        if(m.count(arr[i]) > 0)
        {
            if(std::abs(m[arr[i]] - i) <= k)
            {
                std::cout << arr[i] << ' ';
                found = true;   
            }
        }
        else
        {
            m.insert({arr[i], i});
        }
    }

    if(!found)
    {
        std::cout << "No duplicates found!\n";
    }
    else
    {
        std::puts("");
    }
}

int main(int argc, char const *argv[])
{
    solve1({1,2,3,2,1}, 3);
    solve1({1,2,3,2,1}, 7);
    solve1({5,6,8,2,4,6,9}, 7);
    solve1({5,6,8,2,4,6,9}, 2); 
    
    return 0;
}
