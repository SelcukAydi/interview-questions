/**
 * Link => https://leetcode.com/problems/push-dominoes/
*/

#include <iostream>
#include <vector>
#include <chrono>

/**
 * @brief Finds and stores all the forces impacting to each domino then calculates
 * the final forces.
 * 
 * @param str Input dominoes.
 * @return std::string The final positions of each dominoes.
 */
std::string solution1(const std::string& str)
{
    std::vector<std::pair<int, int>> forces(str.size());
    std::string ans = str;

    int l = 0;
    int r = str.size();
    char latest_force = '.';
    int latest_force_index = -1;

    // Find the left forces.
    //
    for(int i = 0; i < str.size(); ++i)
    {
        if(str.at(i) != '.')
        {
            latest_force = str.at(i);
            latest_force_index = i;
        }
        else if(latest_force == 'R')
        {
            forces[i].first = i - latest_force_index;
        }
        else
        {
            forces[i].first = 100001;
        }
    }

    latest_force = '.';

    // Find the right forces.
    //
    for(int i = str.size() - 1; i >= 0; --i)
    {
        if(str.at(i) != '.')
        {
            latest_force = str.at(i);
            latest_force_index = i;
        }
        else if(latest_force == 'L')
        {
            forces[i].second = latest_force_index - i;
        }
        else
        {
            forces[i].second = 100001;
        }
    }

    // Calculate the final forces for each domino.
    //
    for(int i = 0; i < forces.size(); ++i)
    {
        if(forces[i].first > forces[i].second)
        {
            // Falling to the left side.
            //
            ans[i] = 'L';
        }
        else if(forces[i].first < forces[i].second)
        {
            // Fallig to the right side.
            //
            ans[i] = 'R';
        }
    }

    return ans;
}


/**
 * @brief Simulates the falling of dominoes based on initial forces.
 * 
 * This function takes a string representing a row of dominoes and simulates
 * how they fall over time based on the forces applied to them. The input string
 * contains the following characters:
 * - 'L': A domino that is pushed to the left.
 * - 'R': A domino that is pushed to the right.
 * - '.': A domino that is standing upright and has no force applied yet.
 * 
 * The function calculates the final state of the dominoes after all forces
 * have been resolved.
 * 
 * @param str A reference to the input string representing the initial state
 *            of the dominoes.
 * @return A string representing the final state of the dominoes after all
 *         forces have been applied.
 * 
 * @note The function assumes that the input string is non-empty.
 * @note There is another optimized solution at https://leetcode.com/problems/push-dominoes/submissions/1620295287/
 * 
 * @example
 * Input:  ".L.R...LR..L.."
 * Output: "LL.RR.LLRRLL.."
 * 
 * Input:  "RR.L"
 * Output: "RR.L"
 */
std::string solution2(std::string& str)
{
    std::string ans = str;
    std::size_t N = str.size();
    int last_right_force = -1;
    int last_left_force = 0;

    for(int i = 0; i < N; ++i)
    {
        if(str[i] == 'L')
        {
            if(last_right_force == -1)
            {
                // There is no any previous right force.
                // All the stones will fall to the left side.
                //
                for(int j = last_left_force; j < i; ++j)
                {
                    ans[j] = 'L';
                }
            }
            else
            {
                // In each iteration/second dominoes are falling
                // to the right and left between the latest right
                // and left forces.
                //
                for(int j = last_right_force + 1, k = i - 1; j < k; ++j, --k)
                {
                    ans[j] = 'R';
                    ans[k] = 'L';
                }

                // Reset the latest right force index.
                //
                last_right_force = -1;
            }

            last_left_force = i;
        }
        else if(str[i] == 'R')
        {
            if(last_right_force != -1)
            {
                // Not found any left force till this position and
                // we have right force previously then all the 
                // dominoes must fall to the right side.
                //
                for(int j = last_right_force + 1; j < i; ++j)
                {
                    ans[j] = 'R';
                }
            }

            // Update the latest right force's index.
            //
            last_right_force = i;
        }
    }

    // If there is a previous right force
    // and we never found any left force
    // till the end from the previous right
    // force then we must make all stones
    // falled to the right side.
    //
    if(last_right_force != -1)
    {
        for(int i = last_right_force + 1; i < N; ++i)
        {
            ans[i] = 'R';
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    std::string str1 = ".L.R...LR..L..";
    // std::cout << solution1(str1) << '\n';

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    solution1(str1);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    begin = std::chrono::steady_clock::now();
    solution2(str1);
    end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

    return 0;
}
