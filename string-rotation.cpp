/**
 * @file string-rotation.cpp
 * @author sia
 * @brief https://github.com/careercup/CtCI-6th-Edition-cpp/blob/a68ba3e1c630a4d218ff1294f3eaf5aeced449ec/Ch%201.Arrays%20And%20Strings/9.String_rotation/9.string_rotation.cpp
 */

#include <iostream>
#include <string>
#include <chrono>

/**
 * @brief s1 might be rotated to left or right.
 * Firstly, the first case is checked then second one.
 * 
 * @param s1 
 * @param s2 
 * @return true if s1 is rotation of s2 otherwise false.
 */
bool solution1(const std::string& s1, const std::string& s2)
{
    if(s1.size() != s2.size()) return false;
    int n = s1.size();

    // Start from the left in s1 and right in s2
    //
    for(int i = 0, j = n - 1; i < n; ++i, --j)
    {
        std::string sub1 = s1.substr(i);
        std::string sub2 = s2.substr(0, j + 1);
        if(sub1 == sub2) return true;
    }

    // Start from the right in s1 and right in s2
    //
    for(int i = 0, j = n - 1; i < n; ++i, --j)
    {
        std::string sub1 = s1.substr(0, j + 1);
        std::string sub2 = s2.substr(i);
        if(sub1 == sub2) return true;
    }

    return false;
}

/**
 * @brief s1+s1 must contain s2 as a substring.
 * @param s1 
 * @param s2 
 * @return true if s1 is rotation of s2 otherwise false.
 */
bool solution2(std::string s1, std::string s2)
{
    size_t len1 = s1.length();
    size_t len2 = s2.length();

    if (len1 == 0 || len1 != len2)
    {
        return false;
    }

    std::string concatS1 = s1 + s1;

    if (concatS1.find(s2) != std::string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    std::string s1 = "waterbottle";
    std::string s2 = "erbottlewat";

    // std::string s1 = "abcedf";
    // std::string s2 = "abceef";

    auto begin1 = std::chrono::steady_clock::now();
    std::cout << std::boolalpha << solution1(s1, s2) << '\n';
    auto end1 = std::chrono::steady_clock::now();
    std::cout << "Elapsed time is " << 
        std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1).count() << '\n';
    

    auto begin2 = std::chrono::steady_clock::now();
    std::cout << std::boolalpha << solution2(s1, s2) << '\n';
    auto end2 = std::chrono::steady_clock::now();
    std::cout << "Elapsed time is " << 
        std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2).count() << '\n';


    return 0;
}
