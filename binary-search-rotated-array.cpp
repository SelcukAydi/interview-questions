#include <iostream>
#include <vector>

// Finds the pivot using binary search.
// The pivot is the index that breaks the order.
//
int findPivotLinear(std::vector<int>& arr)
{
    int begin = 0;
    int end = arr.size() - 1;

    while(begin <= end)
    {
        int mid = (begin + end) / 2;

        // This breaks the order.
        //
        if(arr[mid] < arr[mid - 1])
        {
            return mid - 1;
        }

        // [begin, mid] is not sorted properly.
        //
        if(arr[begin] > arr[mid])
        {
            end = mid - 1;
        }
        // [mid, end] is not sorted properly.
        //
        else if(arr[mid] > arr[end])
        {
            begin = mid + 1;
        }
        // [begin, end] is sorted properly.
        //
        else return -1;
    }

    return -1;
}

int binarySearch(std::vector<int>& arr, int element, int begin, int end)
{
    int n = arr.size();

    while(begin <= end)
    {
        int mid = (begin + end) / 2;

        if(arr[mid] == element) return mid;

        if(arr[mid] < element)
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

int searchElement(std::vector<int>& arr, int element)
{
    int pivot_index = findPivotLinear(arr);

    // There is a pivot.
    //
    if(pivot_index != -1)
    {
        int begin = 0;
        int end = pivot_index;

        // Search in the range [begin, end] sorted.
        //
        int index = binarySearch(arr, element, begin, end);
        
        if(index != -1)
        {
            return index;
        }
        
        // Search in the range [end + 1, rest of the array].
        //
        return binarySearch(arr, element, end + 1, arr.size() - 1);
    }
    else
    {
        // Search in the whole array as the array is already sorted.
        //
        return binarySearch(arr, element, 0, arr.size() - 1);
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    std::vector<int> arr1{12,14,16,1,5,7,8,9};
    std::vector<int> arr2{1,2,3,4,5,6,7,8,9,10};
    std::vector<int> arr3{1,2,3,4,5,6,7,8,9,10};

    std::cout << "Element found at " << searchElement(arr1, 1) << '\n';

    return 0;
}
