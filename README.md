```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // each index of these arrays represent one row or one coloumn and one square. 
        // I will use a single integer to keep track of each row, col and square;
        // like row[0] would keep track of the entire first row; 
        // I will check if a number already exists, by using & operator, like row[0] & 1 << (board[r][c] - '1');
        // if it returns 1 this means that I have already encountered this element and therefore 
        // I can return false, else I can put the number into the bitmap or mask, like this:
        // row[0] |= 1 << (board[r][c]- '0'), each one in each element of the row array will represent a number
        // being present in that row, ie. row[r], row[0] in this case;

        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                // if '.' is found, continue;
                if(board[r][c] == '.') continue;

                int val = board[r][c] - '1'; // will make the numbers from 0 to 8, I still dont know why it is done;

                if(rows[r] & 1 << val || cols[c] & 1 << val || squares[(r / 3) * 3 + c / 3] & 1 << val){
                    return false;
                }

                rows[r] |= (1 << val);
                cols[c] |= (1 << val);
                squares[(r / 3) * 3 + c / 3] |= (1 << val);

            }
        } 

        return true;
    }
};

```
```
```
