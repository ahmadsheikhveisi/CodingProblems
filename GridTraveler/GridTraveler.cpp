/* COPYRIGHT
 * how many ways you can travel from 
 * top left to the bottom right using
 * only right and down moves.
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>

// for classical approach the time complexity is O(2^(rows+columns))
// space complexity is O(rows+columns)

// limit of constexpr is 14
constexpr int gridTraveler(int rows, int columns) {
    if (rows == 0 || columns == 0) {
        return 0;
    }
    if (rows == 1 && columns == 1) {
        return 1;
    }
    return gridTraveler(rows - 1, columns) +
           gridTraveler(rows , columns - 1);
}

// for hash table approach the time complexity is O(rows*columns)
// space complexity is O(rows+columns)

std::unordered_map<int, std::unordered_map<int, int>> hashTable;
int gridTraveler_hash(int rows, int columns) {
    if (rows == 0 || columns == 0) {
        return 0;
    }
    if (rows == 1 && columns == 1) {
        return 1;
    }
    int indx = std::min(rows, columns);
    int indx2 = rows + columns - indx;
    if (hashTable.find(indx) != hashTable.end()) {
        if (hashTable[indx].find(indx2) != hashTable[indx].end()) {
            return hashTable[indx][indx2];
        }
    }
    int res = gridTraveler_hash(rows - 1, columns) +
           gridTraveler_hash(rows , columns - 1);
    hashTable[indx][indx2] = res;
    return res;
}


int main() {
    std::cout << gridTraveler_hash(1, 1) << '\n';
    std::cout << gridTraveler_hash(2, 3) << '\n';
    std::cout << gridTraveler_hash(3, 2) << '\n';
    std::cout << gridTraveler_hash(3, 3) << '\n';
    std::cout << gridTraveler_hash(15, 15) << '\n';
    return 0;
}
