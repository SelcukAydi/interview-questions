/**
 * Link1: https://www.geeksforgeeks.org/longest-subarray-not-k-distinct-elements/
 * Link2: https://www.techiedelight.com/find-longest-substring-containing-k-distinct-characters/
*/

#include <iostream>
#include <array>
#include <vector>
#include <limits>
#include <unordered_map>

std::string solve(const std::string& arr, int k)
{
    std::size_t n = arr.size();
    std::array<int, 1000> freqs;
    freqs.fill(0);

    int current_distincts = 0;
    int left = 0, right = 0;
    int max_window = 0;
    int min_left = 0;

    while(right < n)
    {
        // Add the items to the window until we hit the k.
        //
        while(current_distincts <= k && right < n)
        {
            char c = arr[right];
            if(freqs[c]++ == 0)
                current_distincts++;
            
            // If the last item exceeds the k then revert it.
            //
            if(current_distincts > k)
            {
                --current_distincts;
                --freqs[c];
                break;
            }
            ++right;
        }

        // Get the longest subarray.
        //
        if(max_window <= right - left)
        {
            min_left = left;
            max_window = right - left;
        }

        // Narrow the window and adjust the number of unique items.
        //
        if(std::max(--freqs[arr[left++]], 0) == 0)
        {
            --current_distincts;
        }
    }

    return arr.substr(min_left, max_window);
}

std::string solveUsingHashMap(const std::string& str, int k)
{
    std::unordered_map<int, int> freqs;
    int left = 0, min_left = 0, count = 0, max_len = std::numeric_limits<int>::min();

    for(int i = 0; i < str.size(); ++i)
    {
        // Visit the current item and mark it blindly.
        //
        if(++freqs[str[i]] == 1)
            ++count;
        
        // Narrow the window the the current item exceeds k
        // the number of unique items in the window.
        //
        while(count > k)
        {
            if(--freqs[str[left++]] == 0)
                --count;
        }

        // Get the widest window possible.
        //
        if(max_len <= i - left + 1)
        {
            min_left = left;
            max_len = i - left + 1;
        }
    }

    return str.substr(min_left, max_len);
}

int main(int argc, char const *argv[])
{
    
    std::cout << solve("abcbdbdbbdcdabd", 2) << '\n';
    std::cout << solve("abcbdbdbbdcdabd", 3) << '\n';
    std::cout << solve("abcbdbdbbdcdabd", 5) << '\n';
    std::cout << solve("651232145", 3) << '\n';
    std::cout << solve("12345", 6) << '\n';
    
    std::puts("=====================================");

    std::cout << solveUsingHashMap("abcbdbdbbdcdabd", 2) << '\n';
    std::cout << solveUsingHashMap("abcbdbdbbdcdabd", 3) << '\n';
    std::cout << solveUsingHashMap("abcbdbdbbdcdabd", 5) << '\n';
    std::cout << solveUsingHashMap("651232145", 3) << '\n';
    std::cout << solveUsingHashMap("12345", 6) << '\n';


    return 0;
}
