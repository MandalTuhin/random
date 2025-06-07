#include <climits>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumArea(vector<vector<int>> &grid) {
    int least_row_index = INT_MAX, least_col_index = INT_MAX,
        greatest_row_index = INT_MIN, greatest_col_index = INT_MIN;
    vector<int> row_indicies;
    vector<int> coloumn_indicies;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == 1) {
          row_indicies.push_back(i);
          coloumn_indicies.push_back(j);
        }
      }
    }

    for (int elem : row_indicies) {
      cout << elem << " ";
    }
    cout << "\n";

    for (int elem : coloumn_indicies) {
      cout << elem << " ";
    }
    cout << "\n";

    for (int row_index : row_indicies) {
      if (row_index < least_row_index)
        least_row_index = row_index;
      if (row_index > greatest_row_index)
        greatest_row_index = row_index;
    }
    for (int col_index : coloumn_indicies) {
      if (col_index < least_col_index)
        least_col_index = col_index;
      if (col_index > greatest_col_index)
        greatest_col_index = col_index;
    }

    cout << greatest_col_index << ", " << least_col_index << "\n";
    cout << greatest_row_index << ", " << least_row_index << "\n";

    greatest_col_index++;
    greatest_row_index++;
    int area = ((greatest_col_index - least_col_index)) *
               ((greatest_row_index - least_row_index));
    return area;
  }
};

int main() {
  vector<vector<int>> grid = {{0, 1, 0}, {1, 0, 1}};
  Solution solution;
  cout << solution.minimumArea(grid);
  return 0;
}
