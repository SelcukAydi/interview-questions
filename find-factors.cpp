/**
 * Find the factors of the given integer n.
 * */

#include <iostream>
#include <vector>

std::vector<int> findFactors(int n)
{
    std::vector<int> ans;
    for(int i = 1; i*i <= n; ++i)
    {
	if(n % i == 0)
	{
	    ans.push_back(i);
	    if(i*i < n)
		ans.push_back(n / i);
	}
    }

    return ans;
}

void printVector(const std::vector<int>& v)
{
    std::size_t n = v.size();
    for(int i = 0; i < n; ++i)
    {
	std::cout << v[i] << ' ';
    }

    std::puts("");
}

int main(int argc, const char* argv[])
{
    printVector(findFactors(100));
}
