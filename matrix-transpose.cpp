#include <iostream>
#include <vector>

void transpose(std::vector<std::vector<int>>& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i <= n / 2; ++i)
    {
        for(int j = i + 1; j < m; ++j)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void printMatrix(std::vector<std::vector<int>>& matrix)
{
    int N = matrix.size();
    int M = matrix[0].size();

    for(int row = 0; row < M; ++row)
    {
        for(int col = 0; col < N; ++col)
        {
            std::cout << matrix[row][col] << ' ';
        }

        std::puts("");
    }

    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> arr1 = { { 1,2,3 }, {4,5,6}, {7,8,9} };

    std::cout << "Before the transpose\n";
    printMatrix(arr1);
    std::cout << "After the transpose\n";
    transpose(arr1);
    printMatrix(arr1);

    
    
    return 0;
}
