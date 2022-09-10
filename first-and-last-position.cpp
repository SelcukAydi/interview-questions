#include <iostream>
#include <vector>

int binarySearchFirstPosition(std::vector<int>& arr, int k)
{
    auto rs = std::make_pair<int, int>(-1, -1);

    int n = arr.size();
    int begin = 0;
    int end = n;

    while(begin <= end)
    {
        int mid = (begin + end) / 2;

        if(arr[mid] != k && arr[mid + 1] == k)
        {
            return mid + 1;
        }

        if(arr[mid] >= k)
        {
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
    }

    return -1;
}

int binarySearchLastPosition(std::vector<int>& arr, int k)
{
    auto rs = std::make_pair<int, int>(-1, -1);

    int n = arr.size();
    int begin = 0;
    int end = n;

    while(begin <= end)
    {
        int mid = (begin + end) / 2;

        if(arr[mid] != k && arr[mid - 1] == k)
        {
            return mid - 1;
        }

        if(arr[mid] <= k)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}


std::pair<int, int> solution(std::vector<int>& arr, int k)
{
    auto rs = std::make_pair<int, int>(-1, -1);
    rs.first = binarySearchFirstPosition(arr, k);
    rs.second = binarySearchLastPosition(arr, k);
    return rs;
}


int main(int argc, char const *argv[])
{
    std::vector<int> arr1 = { 1,2,2,2,2,3,4,5,6,7 };
    std::vector<int> arr2 = { -1,1,2,2,2,5,6,12,12 };
    std::vector<int> arr3 = { 21,32,51,70,71 };

    // std::cout << binarySearchFirstPosition(arr1, 2) << '\n';
    // std::cout << binarySearchLastPosition(arr1, 2) << '\n';

    auto rs = solution(arr3, 70);
    std::cout << "First occurence at: " << rs.first << '\n';
    std::cout << "Second occurence at : " << rs.second << '\n';




    return 0;
}
