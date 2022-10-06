/**
 * Link => https://github.com/careercup/CtCI-6th-Edition-cpp/blob/a68ba3e1c630a4d218ff1294f3eaf5aeced449ec/Ch%201.Arrays%20And%20Strings/6.String_Compression/6.string_compression.cpp
 * 
 */

#include <iostream>

std::string compressString(const std::string& s)
{
    std::string ans;
    int i = 0;

    while(i < s.size())
    {
        char c = s.at(i);
        int count = 1;
        while(++i < s.size() && s.at(i) == c) ++count;
        ans += c + std::to_string(count);
    }

    return ans.size() < s.size() ? ans : s;
}


int main(int argc, char const *argv[])
{
    std::string s1 = "aabbbcccc";
    std::cout << compressString(s1) << '\n';

    std::string s2 = "abcd";
    std::cout << compressString(s2) << '\n';

    return 0;
}
