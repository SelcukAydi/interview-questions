#include <iostream>
#include <vector>
#include <queue>

#define NIL -1

void displayTree(const std::vector<int>& tree, bool zig_zag)
{
    zig_zag = !zig_zag;
    bool left = true;
    std::queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        std::size_t n = q.size();

        while(n-- > 0)
        {
            int current_idx = q.front();
            q.pop();

            std::cout << tree[current_idx] << ' ';

            if(left)
            {
                if(current_idx * 2 < tree.size() && tree[current_idx * 2] != NIL)
                {
                    q.push(current_idx * 2);
                }

                if(current_idx * 2 + 1 < tree.size() && tree[current_idx * 2 + 1] != NIL)
                {
                    q.push(current_idx * 2 + 1);
                }
            }
            else
            {
                if(current_idx * 2 + 1 < tree.size() && tree[current_idx * 2 + 1] != NIL)
                {
                    q.push(current_idx * 2 + 1);
                }

                if(current_idx * 2 < tree.size() && tree[current_idx * 2] != NIL)
                {
                    q.push(current_idx * 2);
                }
            }
        }

        left = !left ^ zig_zag;
    }
}


int main(int argc, char const *argv[])
{
    displayTree({0,3,9,20,NIL,NIL,15,7}, true);
    std::puts("");
    displayTree({0,100,50,200,25,75,350}, false);
    std::puts("");


    return 0;
}
