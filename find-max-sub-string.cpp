#include <iostream>
#include <string>

std::string findMaxSubString(const std::string& s1, const std::string& s2)
{
    std::size_t n = s1.size();
    std::size_t m = s2.size();

    for(int i = m; i >= 0; --i)
    {
	if(s1.find(s2.substr(0, i), 0) != std::string::npos)
	{
	    return s2.substr(0, i);
	}
    }

    return "";
}

int main(int argc, const char* argv[])
{
    std::string s1 = "abcabcdg";
    std::string s2 = "abcdfe";
    std::cout << findMaxSubString(s1, s2) << '\n';
}
