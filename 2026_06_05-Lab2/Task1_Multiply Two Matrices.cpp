//Lab 2:Easy Problem:Multiply Two Matrices

#include <iostream>          
#include <vector>             // To use vectors (dynamic arrays)
using namespace std;         

// Function to takes two matrices and multiplies them, storing the result in "res"
void mulMat(vector<vector<int>>& m1, vector<vector<int>>& m2, 
            vector<vector<int>>& res) {
    int r1 = m1.size();          // How many rows does the first matrix have?
    int c1 = m1[0].size();       // How many columns does the first matrix have?
    int r2 = m2.size();          // How many rows does the second matrix have?
    int c2 = m2[0].size();       // How many columns does the second matrix have?

    if (c1 != r2) {                            // check if columns of m1 match rows of m2 for Matrix Multiplication
        cout << "Invalid Input" << endl;       
        exit(EXIT_FAILURE);                    
    }

    // Get the result matrix ready — it should be r1 rows by c2 columns, all zeros to start
    res.resize(r1, vector<int>(c2, 0)); 
  
    for (int i = 0; i < r1; i++) {              // Go through each row of the first matrix
        for (int j = 0; j < c2; j++) {          // Go through each column of the second matrix
            for (int k = 0; k < c1; k++) {      // Walk across the row/column and multiply 
                res[i][j] += m1[i][k] * m2[k][j];   // Add each little product into the total
            }
        }
    }
}


int main() {
    vector<vector<int>> m1 = { {1, 1}, {2, 2} };   // Set up our first 2x2 matrix
    vector<vector<int>> m2 = { {1, 1}, {2, 2} };   // Set up our second 2x2 matrix
    vector<vector<int>> res;                        // Empty matrix

    mulMat(m1, m2, res);         // Do the multiplication and fill "res"

    cout << "Multiplication of given two matrices is:\n";   
    for (const auto& row : res) {          // Loop through each row of the result
        for (int val : row) {              // Loop through each number in that row
            cout << val << "\t";           // Print the number followed by a tab for spacing
        }
        cout << endl;                      
    }

    return 0;       
}