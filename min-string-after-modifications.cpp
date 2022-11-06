/**
 * Link: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
*/

#include <iostream>

int minimumLength(std::string s)
{
    std::size_t n = s.size();
    int left = -1, right = n;
    int ans = n;
    if(n < 2) return n;

    while(++left <= --right)
    {
        if(s[left] == s[right])
        {
            char c = s[left];
            while(s[left + 1] == c && left <= right) ++left;
            while(s[right - 1] == c && left <= right) --right;
            ans = (right - left) + 1;
        }
        else
        {
            ans = (right - left) + 1;
            break;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{

    std::string s1 = "aabccabba";
    std::cout << minimumLength(s1);
    
    return 0;
}
