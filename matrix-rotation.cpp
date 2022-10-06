/**
 * Link => https://github.com/careercup/CtCI-6th-Edition-cpp/blob/a68ba3e1c630a4d218ff1294f3eaf5aeced449ec/Ch%201.Arrays%20And%20Strings/7.Rotate_matrix/7.rotate_matrix.cpp
 */

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

void reverse_row(std::vector<std::vector<int>>& matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m / 2; ++j)
		{
			std::swap(matrix[i][j], matrix[i][m - j - 1]);
		}
	}
}

void reverse_column(std::vector<std::vector<int>>& matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n / 2; ++j)
		{
			std::swap(matrix[j][i], matrix[n - j - 1][i]);
		}
	}
}

void clockWiseRotate(std::vector<std::vector<int>>& matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();

	transpose(matrix);
	reverse_row(matrix);
}

void counterClockWiseRotate(std::vector<std::vector<int>>& matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();

	transpose(matrix);
	reverse_column(matrix);
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

	printMatrix(arr1);
	clockWiseRotate(arr1);
	printMatrix(arr1);
	counterClockWiseRotate(arr1);
	printMatrix(arr1);

	
	return 0;
}
