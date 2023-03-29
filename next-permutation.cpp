#include <iostream>
#include <vector>
#include <algorithm>

void solve(std::vector<int>& arr)
{
    std::size_t n = arr.size();
    int swap_index = -1;

    for(int i = n - 2; i >= 0; --i)
    {
        if(arr[i] < arr[i + 1])
        {
            swap_index = i;
            break;
        }
    }

    for(int i = n - 1; i > swap_index && swap_index != -1; --i)
    {
        if(arr[swap_index] < arr[i])
        {
            std::swap(arr[swap_index], arr[i]);
            break;
        }
    }

    std::reverse(arr.begin() + swap_index + 1, arr.end());
}

void printArr(const std::vector<int>& arr)
{
    for(const auto& i : arr)
    {
        std::cout << i << ' ';
    }

    std::puts("");
}


int main(int argc, char const *argv[])
{
    std::vector<int> arr1 { 1,2,3 };
    solve(arr1);
    printArr(arr1);

    return 0;
}
