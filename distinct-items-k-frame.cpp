/**
 * @file distinct-items-k-frame.cpp
 * @author sia
 * @brief Find the count of distinct items in k-length frame.
 * 
 */

#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>

void printDistinctItemsInFrame(const std::vector<int>& arr, int k)
{
    int n = arr.size();
    
    std::array<int, 10000> freqs;
    std::unordered_set<int> uniques;

    // Initialize the uniques and freqs.
    //
    for(int i = 0; i < k; ++i)
    {
        freqs[arr[i]]++;

        if(freqs[arr[i]] == 1)
        {
            uniques.insert(arr[i]);
        }
        else if(freqs[arr[i]] > 1)
        {
            uniques.erase(arr[i]);
        }
    }

    std::cout << uniques.size() << ' ';

    int last_item = arr[0];

    // Shifting the frame to the left.
    //
    for(int i = k; i < n; ++i)
    {
        // Remove the last item from the frame.
        //
        if(freqs[last_item] != 0) freqs[last_item]--;
        if(freqs[last_item] == 1)
        {
            uniques.insert(last_item);
        }
        else
        {
            uniques.erase(last_item);
        }

        // Insert the new item.
        //
        freqs[arr[i]]++;
        if(freqs[arr[i]] == 1)
        {
            uniques.insert(arr[i]);
        }
        else if(freqs[arr[i]] > 1)
        {
            uniques.erase(arr[i]);
        }

        last_item = arr[i - k + 1];

        std::cout << uniques.size() << ' ';
    }

    std::puts("");
}


int main(int argc, char const *argv[])
{
    std::vector<int> arr1 = { 1,2,3,4,4,5,6,7,3,4,4,2,1 };

    printDistinctItemsInFrame(arr1, 4);



    return 0;
}
