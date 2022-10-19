/**
 * Link: https://leetcode.com/problems/decode-string/
*/

#include <iostream>
#include <cctype>

std::string createString(const std::string& s, int k)
{
    std::string ans;
    while(k > 0)
    {
        ans += s;
        --k;
    }

    return ans;
}

std::string solve(const std::string s, int& i)
{
    std::size_t n = s.size();
    std::string sub_str;
    std::string ans;
    int k = -1;
    
    while(i < n)
    {
        if(std::isdigit(s[i]))
        {
            int num = int(s[i] - '0');
            if(k == -1)
            {
                k = num;
                ++i;
                continue;;
            }
            k *= 10;
            k += num;
        }
        else if(s[i] != '[' && s[i] != ']')
        {
            ans += s[i];
        }
        else if(s[i] == '[')
        {
            ++i;
            sub_str = solve(s, i);
            ans += createString(sub_str, k == -1 ? 1 : k);
            sub_str.clear();
            k = -1;
            continue;
        }
        else
        {
            ++i;
            return ans;
        }

        ++i;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::string s1 = "abc3[z2[c]]wty2[oo]";
    std::string s2 = "abc3[c]";
    std::string s3 = "3[a]2[bc]";
    int i = 0;
    std::cout << solve(s3, i) << '\n';
    
    return 0;
}
