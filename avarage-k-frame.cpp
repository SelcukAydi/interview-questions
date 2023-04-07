/**
 * Find the avarage of each k-length frame.
 * */

#include <iostream>
#include <vector>

std::vector<double> avarageFrameK(const std::vector<int>& v, int k)
{
    std::size_t n = v.size();
    std::vector<double> ans;
    double sum = 0;
    
    for(int i = 0; i < k; ++i)
    {
	    sum += v[i];
    }

    ans.push_back(sum / k);

    for(int i = k; i < n; ++i)
    {
        int new_add = -v[i - k] + v[i];
        sum += new_add;
        ans.push_back(sum / k);
    }

    return ans;
}

void printArr(const std::vector<double>& v)
{
    for(int i = 0; i < v.size(); ++i)
    {
	    std::cout << v[i] << ' ';
    }

    std::puts("");
}

int main(int argc, const char* argv[])
{
    std::vector<int> v1 = { 1,2,3,4,1,2,3,5,6,7,0 };
    printArr(avarageFrameK(v1, 3));
}
