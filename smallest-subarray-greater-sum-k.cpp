#include <iostream>
#include <vector>
#include <limits>

void solve(const std::vector<int>& arr, int k)
{
    int current_sum = 0;
    int left = 0;
    int min_left = 0;
    int min_len = std::numeric_limits<int>::max();

    for(int i = 0; i < arr.size(); ++i)
    {
        current_sum += arr[i];

        while (current_sum > k && left <= i)
        {
            if(min_len > i - left + 1)
            {
                min_len = i - left + 1;
                min_left = left;
            }

            current_sum -= arr[left];
            ++left;
        }
    }

    if(min_len == std::numeric_limits<int>::max())
    {
        std::cout << "No subarray exist\n";
        return;
    }

    for(int i = min_left; i < min_left + min_len; ++i)
    {
        std::cout << arr[i] << ' ';
    }

    std::puts("");
}



int main(int argc, char const *argv[])
{
    solve({1, 2, 3, 4, 5, 6, 7, 8}, 20);
    solve({1, 2, 3, 4, 5, 6, 7, 8}, 7);
    solve({1, 2, 3, 4, 5, 6, 7, 8}, 21);
    solve({1, 2, 3, 4, 5, 6, 7, 8}, 40);

    return 0;
}
