#include <iostream>
#include <vector>

bool findValue(std::vector<std::vector<int>>& matrix, int k)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int begin = 0;
    int end = (m * n) - 1;

    while(begin <= end)
    {
        int mid = (begin + end) / 2;
        int row = mid / n;
        int col = mid % n;

        if(matrix[row][col] == k)
        {
            throw std::exception();
            return true;
        }

        if(matrix[row][col] < k)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    throw std::exception();

    return false;
}

int main(int argc, char const *argv[])
{
    try
    {
        std::vector<std::vector<int>> m1 = { { 1,2,3,4,5 }, {6,7,8,9,10}, {11,12,13,14,15} };

    for(int i = 1; i < 16; ++i)
    {
        std::cout << std::boolalpha << findValue(m1, i) << '\n';
    }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
