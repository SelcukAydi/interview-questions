/**
 * @file string-permutation.cpp
 * @author sia
 * @brief https://github.com/careercup/CtCI-6th-Edition-cpp/blob/a68ba3e1c630a4d218ff1294f3eaf5aeced449ec/Ch%201.Arrays%20And%20Strings/2.Check%20Permutation/1.Check_Permutation.cpp
 */

#include <iostream>
#include <stack>
#include <array>
#include <algorithm>

/**
 * @brief Checks if the given two strings are permutations of each other using stack.
 * 
 * @param s1 The first string.
 * @param s2 The second string.
 * @return true if the given two strings are permutation of each other otherwise false.
 */
bool solution1(const std::string& s1, const std::string& s2)
{
    if(s1.size() != s2.size()) return false;

    std::stack<char> checkStack;

    for(int i = 0; i < s1.size(); ++i)
    {
        checkStack.push(s1[i]);
    }

    for(int i = 0; i < s2.size(); ++i)
    {
        char c = checkStack.top();
        checkStack.pop();
        if(c != s2[i]) return false;
    }

    return true;
}

/**
 * @brief Checks if the given two strings are permutations of each other using sorting.
 * 
 * @param s1 The first string.
 * @param s2 The second string.
 * @return true if the given two strings are permutation of each other otherwise false.
 */
bool solution2(std::string& s1, std::string& s2)
{
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return std::equal(s1.begin(), s1.end(), s2.begin(), s2.end());
}


int main(int argc, char const *argv[])
{
    std::array<std::string, 2> arr1 = { "abc", "cba" };


    std::cout << std::boolalpha << solution1(arr1[0], arr1[1]) << '\n';
    std::cout << std::boolalpha << solution2(arr1[0], arr1[1]) << '\n';



    return 0;
}
