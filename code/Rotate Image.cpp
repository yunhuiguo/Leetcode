#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int row = matrix.size();

        for(int i = 0; i <= row/2; i++) {
            for(int j = i; j < row-i-1; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[row-1-j][i];
                matrix[row-1-j][i] = matrix[row-i-1][row-1-j];
                matrix[row-i-1][row-j-1] = matrix[j][row-i-1];
                matrix[j][row-i-1] = tmp;
            }
        }
    }
};

int main() {
    vector<vector<int> > matrix;

    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    vector<int> v2;
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);

    vector<int> v3;
    v3.push_back(9);
    v3.push_back(10);
    v3.push_back(11);
    v3.push_back(12);

    vector<int> v4;
    v4.push_back(13);
    v4.push_back(14);
    v4.push_back(15);
    v4.push_back(16);

    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);

    for(int i = 0 ; i < matrix.size();i++) {
        for(int j = 0; j < matrix[i].size(); j++) 
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    Solution s;
    s.rotate(matrix);
    for(int i = 0 ; i < matrix.size();i++) {
        for(int j = 0; j < matrix[i].size(); j++) 
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}