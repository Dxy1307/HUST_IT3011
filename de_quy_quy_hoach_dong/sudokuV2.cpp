#include <iostream>
using namespace std;

const int N = 9;

// Hàm kiểm tra xem số num có thể điền vào ô (row, col) hay không
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Kiểm tra hàng và cột
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    
    // Kiểm tra ô 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    
    return true;
}

// Hàm đệ quy để đếm số lời giải
int countSolutions(int grid[N][N]) {
    int row, col;
    
    // Tìm ô trống
    bool found = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    
    // Nếu không còn ô trống, đã tìm thấy lời giải
    if (!found) {
        return 1;
    }
    
    int count = 0;
    // Thử các giá trị từ 1 đến 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            // Điền số num vào ô (row, col)
            grid[row][col] = num;
            // Đệ quy cho ô tiếp theo
            count += countSolutions(grid);
            // Đặt lại ô (row, col) về 0 để thử giá trị khác
            grid[row][col] = 0;
        }
    }
    
    return count;
}

int main() {
    int grid[N][N];
    cout << "Nhập Sudoku (sử dụng 0 cho ô trống):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    
    int solutions = countSolutions(grid);
    cout << "Số lời giải: " << solutions << endl;
    
    return 0;
}
