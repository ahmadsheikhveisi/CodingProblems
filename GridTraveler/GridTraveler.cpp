/* COPYRIGHT
 * how many ways you can travel from 
 * top left to the bottom right using
 * only right and down moves.
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

// for classical approach the time complexity is O(2^(rows+columns))
// space complexity is O(rows+columns)

// limit of constexpr is 14
constexpr int gridTraveler_classic(int rows, int columns) {
    if (rows == 0 || columns == 0) {
        return 0;
    }
    if (rows == 1 && columns == 1) {
        return 1;
    }
    return gridTraveler_classic(rows - 1, columns) +
           gridTraveler_classic(rows , columns - 1);
}

// for hash table approach the time complexity is O(rows*columns)
// space complexity is O(rows+columns)


int gridTraveler_hash(int rows, int columns,
        std::unordered_map<int, std::unordered_map<int, int>>* hashTable) {
    if (rows == 0 || columns == 0) {
        return 0;
    }
    if (rows == 1 && columns == 1) {
        return 1;
    }
    int indx = std::min(rows, columns);
    int indx2 = rows + columns - indx;
    if ((*hashTable).find(indx) != (*hashTable).end()) {
        if ((*hashTable)[indx].find(indx2) != (*hashTable)[indx].end()) {
            return (*hashTable)[indx][indx2];
        }
    }
    int res = gridTraveler_hash(rows - 1, columns, hashTable) +
           gridTraveler_hash(rows , columns - 1, hashTable);
    (*hashTable)[indx][indx2] = res;
    return res;
}

// time complexity is rows * columns
// space complexity is rows * columns
int gridTraveler_table(int rows, int columns) {
    if (rows == 0 || columns == 0) {
        return 0;
    }
    if (rows == 1 && columns >= 1) {
        return 1;
    }
    std::vector<std::vector<int>> table(rows,
               std::vector<int>(columns));

    table[0][1] = 1;  // right move
    table[1][0] = 1;  // down move

    for (int cnt = 0; cnt < (rows) * (columns); ++cnt) {
        int t_row = cnt / (columns);
        int t_column = cnt % (columns);
        // right move
        if (t_column + 1 < columns) {
            table[t_row][t_column + 1] += table[t_row][t_column];
        }
        // down move
        if (t_row + 1 < rows) {
            table[t_row + 1][t_column] += table[t_row][t_column];
        }
    }
    return table[rows - 1][columns - 1];
}

int gridTraveler(int rows, int columns) {
    // std::unordered_map<int, std::unordered_map<int, int>> hashTable;
    // return gridTraveler_hash(rows, columns, &hashTable);
    return gridTraveler_table(rows, columns);
}

int main() {
    std::cout << gridTraveler(1, 1) << '\n';  // 1
    std::cout << gridTraveler(2, 3) << '\n';  // 3
    std::cout << gridTraveler(3, 2) << '\n';  // 3
    std::cout << gridTraveler(3, 3) << '\n';  // 6
    std::cout << gridTraveler(15, 15) << '\n';  // 40116600
    return 0;
}
