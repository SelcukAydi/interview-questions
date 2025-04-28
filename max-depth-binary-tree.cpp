#include <iostream>
#include <vector>
#include <queue>

int findDepth(const std::vector<int>& arr)
{
    int ans = 0;
    std::queue<int> q;

    if(arr.empty())
        return 0;

    if(arr.size() == 1)
        return 1;

    q.push(1);

    while(!q.empty())
    {
        std::size_t n = q.size();

        while(n-- > 0)
        {
            int s = q.front();
            q.pop();
            int left = s * 2;
            int right = s * 2 + 1;

            if(left < arr.size() + 1 && arr[left - 1] != 0)
            {
                q.push(left);
            }

            if(right < arr.size() + 1 && arr[right - 1] != 0)
            {
                q.push(right);
            }
        }

        ++ans;
    }

    return ans;
}


int main(int argc, char const *argv[])
{
    std::cout << findDepth({3,9,20,0,0,15,7}) << '\n';


    return 0;
}
