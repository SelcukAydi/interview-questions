/**
 * Link => https://github.com/careercup/CtCI-6th-Edition-cpp/blob/a68ba3e1c630a4d218ff1294f3eaf5aeced449ec/Ch%201.Arrays%20And%20Strings/7.Rotate_matrix/7.rotate_matrix.cpp
 */

#include <iostream>
#include <vector>

void nullifyRow(std::vector<std::vector<int>>& matrix, int row)
{
    int N = matrix[0].size();

    for(int col = 0; col < N; ++col)
    {
        matrix[row][col] = 0;
    }
}

void nullifyColumn(std::vector<std::vector<int>>& matrix, int col)
{
    int M = matrix.size();

    for(int row = 0; row < M; ++row)
    {
        matrix[row][col] = 0;
    }
}

void nullifyMatrix(std::vector<std::vector<int>>& matrix)
{
    int M = matrix.size();
    int N = matrix[0].size();
    bool nullify_first_row = false;

    for(int col = 0; col < N; ++col)
    {
        if(matrix[0][col] == 0)
        {
            nullify_first_row = true;
        }
    }

    // Nullify the rows first.
    //
    for(int row = 1; row < M; ++row)
    {
        bool nullify_row = false;

        for(int col = 0; col < N; ++col)
        {
            if(matrix[row][col] == 0)
            {
                matrix[0][col] = 0;
                nullify_row = true;
            }
        }

        if(nullify_row)
        {
            nullifyRow(matrix, row);
        }
    }

    // Nullify the columns.
    //
    for(int col = 0; col < N; ++col)
    {
        if(matrix[0][col] == 0)
        {
            nullifyColumn(matrix, col);
        }
    }

    if(nullify_first_row)
    {
        nullifyRow(matrix, 0);
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix)
{
    int M = matrix.size();
    int N = matrix[0].size();

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
    std::vector<std::vector<int>> m1 = {
                                            { 1,2,3 },
                                            { 3,4,5 },
                                            { 6,0,7 },
                                            { 8,7,0 } 
                                       };

    std::cout << "Before the nullification\n";
    printMatrix(m1);
    std::cout << "After the nullification\n";
    nullifyMatrix(m1);
    printMatrix(m1);



    return 0;
}
