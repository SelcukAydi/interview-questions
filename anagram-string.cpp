/**
 * Link: https://www.techiedelight.com/find-substrings-string-permutation-given-string/
 * Find all substrings of a string that contains all characters of another string. 
 * In other words, find all substrings of the first string that are anagrams of the second string.
*/

#include <iostream>
#include <set>

void findAnagrams(const std::string& s1, const std::string& s2)
{
    std::size_t n = s1.size();
    std::size_t m = s2.size();

    if(n < m) return;

    std::multiset<char> window;
    std::multiset<char> second_str_set;

    for(int i = 0; i < m; ++i)
        second_str_set.insert(s2[i]);
    
    for(int i = 0; i < n; ++i)
    {
        // Populate the initial window first.
        //
        if(i < m)
        {
            window.insert(s1[i]);
            continue;
        }
        
        // If the current window fits.
        //
        if(window == second_str_set)
        {
            std::cout << s1.substr(i - m, m) << '\n';
        }
        
        // Shift the window to the right.
        //
        auto itr = window.find(s1[i - m]);
        if(itr != window.end())
            window.erase(itr);
        window.insert(s1[i]);
    }

    // If the last window fits.
    //
    if(window == second_str_set)
    {
        std::cout << s1.substr(n - m) << '\n';
    }
}

int main(int argc, char const *argv[])
{
    findAnagrams("XYYZXZYZXXYZ", "XYZ");


    return 0;
}
