/**
 * Link => https://github.com/careercup/CtCI-6th-Edition-cpp/blob/a68ba3e1c630a4d218ff1294f3eaf5aeced449ec/Ch%201.Arrays%20And%20Strings/5.One_Away/5-one-edit-away.cpp
 */

#include <iostream>
#include <string>

std::uint8_t findNumberOfSameChars(const std::string& s1, const std::string& s2)
{
    std::uint8_t count = 0;

    for(int i = 0; i < s1.size(); ++i)
    {
        if(s1[i] == s2[i]) ++count;
    }

    return count;
}

bool solution(const std::string& s1, const std::string& s2)
{
    std::size_t s1_size = s1.size();
    std::size_t s2_size = s2.size();

    // Insert case.
    if(s1_size < s2_size)
    {
        if(s2.substr(0, s2_size - 1) == s1) return true;
    }
    // Remove case.
    else if(s1_size > s2_size)
    {
        if(s1.substr(0, s1_size - 1) == s2) return true;
    }
    // Replace case.
    else
    {
        if(s1 == s2) return true;
        if(findNumberOfSameChars(s1, s2) == s1_size - 1) return true;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    std::string s1 = "abfd";
    std::string s2 = "abc";

    std::cout << std::boolalpha << solution(s1, s2) << '\n';

    return 0;
}
