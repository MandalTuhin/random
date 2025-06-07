#include <iostream>
#include <vector>

using namespace std;

void chessBoard() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      (i + j) % 2 ? cout << " " : cout << "#";
    }
    cout << "\n";
  }
}

int main() {
  chessBoard();
  return 0;
}
