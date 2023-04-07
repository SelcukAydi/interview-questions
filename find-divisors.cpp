#include <iostream>
#include <vector>

void printVector(const std::vector<int>& v)
{
    for(int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << ' ';
    }

    std::puts("");
}

std::vector<int> findDivisors(int n)
{
    std::vector<int> ans;
    
    for(int i = 1; i * i <= n; ++i)
    {
        if(n % i != 0) continue;
        ans.push_back(i);
        int a = n / i;
        if(a != i) ans.push_back(a);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    auto v1 = findDivisors(27);
    printVector(v1);

    return 0;
}
