#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

using ll = std::uint64_t;

bool checkPath(const std::vector<ll>& stones, ll dist)
{
    bool ans{false};
    std::set<ll> visited;
    ll max_jump_allowed = stones[0] + dist;

    auto itr = stones.cbegin();

    while (itr != stones.cend())
    {
        // TODO: Finding the upper bound can be done with binary search.
        //
        itr = std::upper_bound(itr, stones.cend(), max_jump_allowed);

        if (itr != stones.end())
        {
            if (visited.count(*(--itr)) > 0)
            {
                break;
            }

            max_jump_allowed = (*(itr) + dist);
            visited.insert(*itr);
        }
        else if (max_jump_allowed >= *stones.rbegin())
        {
            ans = true;
        }
        else
        {
            ans = false;
        }
    }

    if (!ans)
    {
        return ans;
    }

    visited.erase(*stones.cbegin());
    visited.erase(*stones.crbegin());

    ll current_stone = stones[0];
    ll last_possible_stone = current_stone;
    for (ll i = 1; i < stones.size(); ++i)
    {
        if (visited.count(stones[i]) > 0)
        {
            continue;
        }

        if (stones[i] <= (last_possible_stone + dist))
        {
            last_possible_stone = stones[i];
        }
        else
        {
            current_stone = last_possible_stone;
        }
    }

    return last_possible_stone == *stones.crbegin();
}

ll maxJump(const std::vector<ll>& stones)
{
    ll ans{std::numeric_limits<ll>::max()};
    ll left{}, right = *stones.rbegin();

    while (left <= right)
    {
        ll mid = (left + right) / 2;

        if (checkPath(stones, mid))
        {
            ans = std::min(mid, ans);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

int main()
{
    {
        std::vector<ll> stones{0, 2, 5, 6, 7};
        std::cout << maxJump(stones) << '\n';
    }

    {
        std::vector<ll> stones{0, 3, 9};
        std::cout << maxJump(stones) << '\n';
    }

    {
        std::vector<ll> stones{0, 5, 13, 14};
        std::cout << maxJump(stones) << '\n';
    }

    return 0;
}