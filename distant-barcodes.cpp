/**
 * Link: https://leetcode.com/problems/distant-barcodes/
 */

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

void printVector(const std::vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << ' ';
    }

    std::puts("");
}

/**
 * @brief Rearranges the array on O(n). It first puts the most frequency barcode.
 * The remaining barcodes can be put in any order.
 * @param barcodes The array to work on.
 * @returns The rearranged array.
 */
std::vector<int> solve(std::vector<int>& barcodes)
{
    int n = barcodes.size();
    std::array<int, 10001> freqs{0};
    int max_barcode = 0, max_freq = 0;

    // We need the barcode having the most frequency.
    //
    for (int i = 0; i < n; ++i)
    {
        max_freq = std::max(++freqs[barcodes[i]], max_freq);
        max_barcode = freqs[barcodes[i]] == max_freq ? barcodes[i] : max_barcode;
    }

    int pos = 0;

    // Let's put the most frequency barcode first.
    //
    while (freqs[max_barcode]-- > 0)
    {
        barcodes[pos] = max_barcode;
        pos += 2;
    }

    // If the pos is at the end of the array
    // then start from 1.
    // Note that if the below line executed
    // then the line inside the while loop checking
    // the pos bounday will never set pos to 1 again.
    //
    pos = pos < n ? pos : 1;

    // Put the other barcodes till their frequency goes to zero.
    //
    for (int i = 1; i < freqs.size(); ++i)
    {
        while (freqs[i]-- > 0)
        {
            barcodes[pos] = i;
            pos = pos + 2 < n ? pos + 2 : 1;
        }
    }

    return barcodes;
}

/**
 * @brief Rearranges the array on O(logn). It first puts the most frequency barcode and then the second one.
 * @param barcodes The array to work on.
 * @returns The rearranged array.
 */
std::vector<int> solve_with_map(const std::vector<int>& barcodes)
{
    std::priority_queue<std::pair<int, int>> pq;
    std::unordered_map<int, int> map;
    std::size_t n = barcodes.size();
    std::vector<int> ans;

    if (n <= 1)
        return barcodes;

    for (int i = 0; i < n; ++i)
    {
        map[barcodes[i]]++;
    }

    for (auto itr = map.begin(); itr != map.end(); ++itr)
    {
        pq.push({itr->second, itr->first});
    }

    while (pq.top().first > 0)
    {
        auto p1 = pq.top();
        pq.pop();
        ans.push_back(p1.second);
        p1.first--;

        if (ans.size() == n)
            break;

        auto p2 = pq.top();
        pq.pop();
        ans.push_back(p2.second);
        p2.first--;

        pq.push(p1);
        pq.push(p2);
    }

    return ans;
}

int main(int argc, char const* argv[])
{
    std::vector<int> v1 = {1, 1, 1, 1, 2, 2, 3, 3};
    auto ans1 = solve(v1);
    printVector(ans1);

    std::vector<int> v2 = {1, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5};
    auto ans2 = solve(v2);
    printVector(ans2);

    std::vector<int> v3 = {1, 1, 1, 2, 2, 2};
    auto ans3 = solve_with_map(v3);
    printVector(ans3);

    std::vector<int> v4 = {1};
    auto ans4 = solve_with_map(v4);
    printVector(ans4);

    return 0;
}
