/* COPYRIGHT
 * 
*/

#include <iostream>
#include <cstdlib>
#include <set>

const size_t top_count = 1024;


int main(void) {
    unsigned int gseed = time(nullptr);
    std::multiset<int> mset;
    for (size_t cnt = 0; cnt < top_count; ++cnt) {
        mset.insert(rand_r(&gseed));
    }
    int new_rand = rand_r(&gseed);
    std::cout << "new random number " << new_rand << " is between "
        << *--mset.lower_bound(new_rand) << " and " <<
        *mset.upper_bound(new_rand) << '\n';
    return 0;
}
