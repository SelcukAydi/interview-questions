/**

Question
Assume there is a neighborhood with districts each having various houses with different numbers labeled. Shuffle this
distrcits so that each district will have unique houses. Some house labels may be repeting at the start step. After
shuffle, there should be no repeat.
*/

#include <algorithm>
#include <cassert>
#include <random>
#include <unordered_set>
#include <vector>
#include <iostream>

/**
 * @brief Redistributes houses among districts in a shuffled and balanced manner.
 *
 * This function takes a 2D vector representing districts and their associated houses,
 * shuffles all the houses, and redistributes them back into the districts using a
 * round-robin approach. The redistribution ensures that no duplicate houses exist
 * within the same district.
 *
 * @param districts A reference to a 2D vector where each inner vector represents
 *                  a district and contains integers representing houses.
 *
 * @details
 * - The function first collects all houses from the input districts into a single
 *   vector and clears the original districts.
 * - It then shuffles the collected houses using a random number generator.
 * - Finally, it redistributes the shuffled houses back into the districts using
 *   a round-robin assignment strategy, ensuring no duplicate houses are assigned
 *   to the same district.
 *
 * @note The function modifies the input `districts` in place.
 */
void redistributeHouses(std::vector<std::vector<int>>& districts)
{
    std::size_t num_of_districts = districts.size();
    std::vector<int> houses;
    std::for_each (districts.begin(), districts.end(),
                   [&houses](const std::vector<int>& district) -> void
                   { houses.insert(houses.end(), district.cbegin(), district.cend()); });

    std::for_each (districts.begin(), districts.end(), [](std::vector<int>& district) -> void { district.clear(); });

    // Shuffle here.
    //
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(houses.begin(), houses.end(), g);

    std::vector<std::unordered_set<int>> district_set{num_of_districts};
    std::size_t last_district_assigned = 0;

    for (const auto house : houses)
    {
        // Try to assign this house to a district.
        // Here, each house is being assined by round-robin approach.
        //
        for (std::size_t d = 0; d < num_of_districts; ++d)
        {
            // Round robin next index.
            //
            std::size_t next_district_idx = (last_district_assigned + d) % num_of_districts;

            if (district_set[next_district_idx].find(house) != district_set[next_district_idx].end())
                continue;

            district_set[next_district_idx].insert(house);
            districts[next_district_idx].push_back(house);
            ++last_district_assigned;
            break;
        }
    }
}

void printDistricts(const std::vector<std::vector<int>>& districts)
{
    for (const auto& district : districts)
    {
        for (auto house : district)
        {
            std::cout << house << " ";
        }

        std::puts("");
    }
}

/**
 * @brief Validates whether the given districts are valid.
 * 
 * This function checks if each district in the input contains unique house identifiers.
 * A district is considered invalid if it contains duplicate house identifiers.
 * 
 * @param districts A 2D vector where each inner vector represents a district and contains
 *                  integers representing house identifiers.
 * @return true If all districts are valid (no duplicates within any district).
 * @return false If any district contains duplicate house identifiers.
 */
bool areDistrictsValid(const std::vector<std::vector<int>>& districts)
{
    for (const auto& district : districts)
    {
        std::unordered_set<int> seen;
        for (int house : district)
        {
            if (seen.find(house) != seen.end())
            {
                return false;  // Duplicate found in the same district
            }
            seen.insert(house);
        }
    }
    return true;
}

// Test case 1: Basic test with duplicates
void testBasic()
{
    std::vector<std::vector<int>> districts = {{101, 102, 103, 101}, {102, 104, 105}, {106, 107, 106}};
    redistributeHouses(districts);
    assert(areDistrictsValid(districts));
    std::cout << "Test case 1 passed.\n";
}

// Test case 2: No duplicates in input
void testNoDuplicates()
{
    std::vector<std::vector<int>> districts = {{101, 102}, {103, 104}, {105, 106}};
    redistributeHouses(districts);
    assert(areDistrictsValid(districts));
    std::cout << "Test case 2 passed.\n";
}

// Test case 3: All houses are the same
void testAllSameHouses()
{
    std::vector<std::vector<int>> districts = {{101, 101}, {101, 101}, {101, 101}};
    redistributeHouses(districts);
    assert(areDistrictsValid(districts));
    std::cout << "Test case 3 passed.\n";
}

// Test case 4: Empty districts
void testEmptyDistricts()
{
    std::vector<std::vector<int>> districts = {{}, {}, {}};
    redistributeHouses(districts);
    assert(areDistrictsValid(districts));
    std::cout << "Test case 4 passed.\n";
}

// Test case 5: Single district with duplicates
void testSingleDistrict()
{
    std::vector<std::vector<int>> districts = {{101, 102, 103, 101, 102}};
    redistributeHouses(districts);
    assert(areDistrictsValid(districts));
    std::cout << "Test case 5 passed.\n";
}

// Test case 6: Large number of houses and districts
void testLargeInput()
{
    std::vector<std::vector<int>> districts(
        10, std::vector<int>(100, 101));  // 10 districts, each with 100 houses labeled 101
    redistributeHouses(districts);
    assert(areDistrictsValid(districts));
    std::cout << "Test case 6 passed.\n";
}

int main()
{
    // Main test case.
    {
        std::vector<std::vector<int>> districts = {{101, 102, 103, 101}, {102, 104, 105}, {106, 107, 106}};
        std::puts("Before shuffle");
        printDistricts(districts);

        redistributeHouses(districts);

        std::puts("After shuffle");
        printDistricts(districts);
    }

    // Run test cases.
    testBasic();
    testNoDuplicates();
    testAllSameHouses();
    testEmptyDistricts();
    testSingleDistrict();
    testLargeInput();

    return 0;
}