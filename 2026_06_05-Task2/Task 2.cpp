//Lab 2:Medium Problem:Matrix Median

#include <algorithm>     //For the sort() function
#include <iostream>      
#include <vector>        //To use vectors (dynamic arrays)
using namespace std;     

//Function to take a 2D matrix and finds its median value
int median(vector<vector<int>> &mat) {
    
    // We can't find a median in a grid, so put everything into one list first
    vector<int> arr;                              // To collect all the numbers
    for (int i = 0; i < mat.size(); i++) {        // Go through each row of the matrix
        for (int j = 0; j < mat[0].size(); j++) { // Go through each column in that row
            arr.push_back(mat[i][j]);              // Put that number into list
        }
    }

    // Sort the flat list from smallest to biggest so we can find the middle
    sort(arr.begin(), arr.end());

    // The median sits right in the middle of the sorted list
    int mid = arr.size() / 2;   // Calculate which index is the middle position
    return arr[mid];            // Put back the value that at that middle spot
}

int main() {
    // Set up 3x3 matrix 
    vector<vector<int>> matrix = 
                        {{1, 3, 5},   // First row
                         {2, 6, 9},   // Second row
                         {3, 6, 9}};  // Third row

    cout << median(matrix) << endl;   // Print the meadian
    return 0;                        
}