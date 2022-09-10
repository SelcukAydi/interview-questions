/**
 * @file is-string-unique.cpp
 * @author sia
 * @brief https://github.com/careercup/CtCI-6th-Edition-cpp/blob/a68ba3e1c630a4d218ff1294f3eaf5aeced449ec/Ch%201.Arrays%20And%20Strings/1.Is%20Unique/1.%20Is_unique.cpp
 */

#include <iostream>
#include <bitset>
#include <algorithm>

#define MAX_CHAR_ASCII 256

/**
 * @brief Solves only if the string consists of chars in range [a-z].
 * 
 * @param s The charset to work on.
 * @return true if the given s has unique elements. Otherwise returns false.
 */
bool isUnique1(const std::string& s)
{
    int checker = 0;

    for(int i = 0; i < s.size(); ++i)
    {
        int val = s[i] - 'a';
        if((checker & (1 << val)) > 0)
        {
            return false;
        }
        checker |= (1 << val);
    }

    return true;
}

/**
 * @brief Solves any given string in ASCII encoded.
 * 
 * @param s The charset to work on.
 * @return true if the given s has unique elements. Otherwise returns false. 
 */
bool isUnique2(const std::string& s)
{
    bool checker[MAX_CHAR_ASCII];

    for(int i = 0; i < MAX_CHAR_ASCII; ++i)
        checker[i] = false;

    for(int i = 0; i < s.size(); ++i)
    {
        if(checker[(int)(s[i])]) return false;
        checker[(int)(s[i])] = true;
    }

    return true;
}

/**
 * @brief Solves any given string in ASCII encoded using bitset.
 * 
 * @param s The charset to work on.
 * @return true if the given s has unique elements. Otherwise returns false. 
 */
bool isUnique3(const std::string& s)
{
    std::bitset<MAX_CHAR_ASCII> checker(0);

    for(int i = 0; i < s.size(); ++i)
    {
        int val = s[i];
        if(checker[val]) return false;
        checker.set(val);
    }

    return true;
}

/**
 * @brief Solves any given string in ASCII encoded using sorting.
 * 
 * @param s The charset to work on.
 * @return true if the given s has unique elements. Otherwise returns false. 
 */
bool isUnique4(std::string& s)
{
    std::sort(s.begin(), s.end());

    for(int i = 0; i < s.size() - 1; ++i)
    {
        if(s[i] == s[i + 1]) return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    std::string s1 = "bcdfcd";
    std::string s2 = "bcdfABZc";
    std::string s3 = "abcdFsGetHSZHJs";
    std::string s4 = "cabfCf";
    
    std::cout << std::boolalpha << isUnique1(s1) << '\n';
    std::cout << std::boolalpha << isUnique2(s2) << '\n';
    std::cout << std::boolalpha << isUnique3(s3) << '\n';
    std::cout << std::boolalpha << isUnique4(s4) << '\n';
    
    return 0;
}
