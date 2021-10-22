/* COPYRIGHT
 * 
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>

const size_t top_value = 33;
const size_t top_count = 10000;


int main(void) {
    unsigned int gseed = time(nullptr);
    {
        // first solution
        int cnt = 0;
        std::vector<std::pair<int, int>> vec(top_value + 1);
        for (auto & [first, second] : vec) {
            first = cnt++;
            second = 0;
        }
        for (size_t cnt = 0; cnt < top_count; ++cnt) {
            int random_value = rand_r(&gseed) % (top_value + 1);
            vec.at(random_value).second++;
        }
        auto comp = [](
            const std::pair<int, int>&a, const std::pair<int, int> &b) {
            return a.second < b.second;
        };
        std::sort(begin(vec), end(vec), comp);
        for (const auto &[num, repeat] : vec) {
            // std::cout << repeat << ':' << num << '\n';
        }
    }

    // Second Solution
    {
        std::vector<int> vec2(top_value + 1, 0);
        for (size_t cnt = 0; cnt < top_count; ++cnt) {
            int random_value = rand_r(&gseed) % (top_value + 1);
            vec2.at(random_value)++;
        }
        std::multimap<int, int> mmap;
        for (int cnt = 0; cnt < top_value; ++cnt) {
            mmap.insert(std::pair<int, int>(vec2[cnt], cnt));
        }
        for (const auto& [first, second] : mmap) {
            std::cout << first << ':' << second << '\n';
        }
    }
    return 0;
}
