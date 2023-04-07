/**
 * Link: https://www.techiedelight.com/find-longest-substring-containing-k-distinct-characters/
 * Given a string and a positive number k, find the longest substring of the string containing k distinct characters. 
 * If k is more than the total number of distinct characters in the string, return the whole string.
*/

#include <iostream>
#include <array>
#include <limits>

void solve(const std::string& s)
{
    std::array<char, 128> pos;
    pos.fill(-1);
    int l = 0;
    int max_len = std::numeric_limits<int>::min();
    int min_l = 0;

    if(s.empty()) return;

    for(int i = 0; i < s.size(); ++i)
    {
        if(pos[s[i]] != -1)
        {
            if(max_len <= i - l)
            {
                max_len = i - l;
                min_l = l;
            }

            for(int j = l; j < pos[s[i]]; ++j)
                pos[s[j]] = -1;
            l = pos[s[i]] + 1;
            pos[s[i]] = i;
        }
        else
        {
            pos[s[i]] = i;
        }
    }

    std::cout << s.substr(min_l, max_len) << '\n';
}

int main(int argc, char const *argv[])
{
    solve("findlongestsubstring");
    solve("longestsubstr");
    solve("abbcdafeegh");
    solve("aaaaaa");
    solve("");

    return 0;
}
