#include <iostream>
#include <string>
class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows <= 1 || s.size() <= 1)
            return s;
        int j = 0;
        int len = s.size();     // number of characters in string s
        while (len > 0) {
            len -= numRows;
            j++;
            if (len > 0) {
                len -= numRows - 2;
                j += numRows - 2;   // number of columns for zigzag
            }
        }
        char **mat = new char*[numRows];
        for (int i = 0; i < numRows; i++) {
            mat[i] = new char[j];
        }
        for (int i = 0; i < numRows; i++) {
            for (int k = 0; k < j; k++) {
                mat[i][k] = '\0';       //null char for the whole matrix
            }
        }
        int row = 0, col = 0, letter = 0;
        while (letter < s.size()) {
            for (row = 0; row < numRows && letter < s.size(); row++ ) {
                mat[row][col] = s.at(letter);
                letter++;
            }
            col++;
            row -= 2;       //zigzag starting position
            for (; row > 0 && letter < s.size(); row--) {
                mat[row][col] = s.at(letter);
                letter++;
                col++;
            }
        }
        std::string result;
        for (int i = 0; i < numRows; i++) {
            for (int k = 0; k < j; k++) {
                if (mat[i][k] != '\0') {
                    result.push_back(mat[i][k]);
                }
            }
        }
        for (int i = 0; i < numRows; i++) {
            delete[] mat[i];
        }
        delete[] mat;
        return result;
    }
};
int main() {
    Solution x;
    std::string s = "PAYPALISHIRING";
    std::cout << x.convert(s,3) << std::endl;
    std::cout << x.convert(s,4) << std::endl;
    std::string d = "AB";
    std::cout << x.convert(d,1) << std::endl;
    return 0;
}