//Lab 2:Hard Problem:Matrix Chain Multiplication

// matrix chain multiplication using recursion
#include <iostream>      
#include <vector>        // for vector
#include <algorithm>     // for min()
#include <climits>       // for INT_MAX
using namespace std;

// Matrix Ai has dimension arr[i-1] x arr[i]
// Returns the minimum number of multiplications needed
int minMultRec(vector<int> &arr, int i, int j)
{
    // Base case: only one matrix, no multiplication needed
    if (i + 1 == j)
        return 0;

    int res = INT_MAX;    // Start with the largest possible value

    // Try every possible split point between i and j
    for (int k = i + 1; k < j; k++)
    {
        // Calculate cost of splitting at k
        int curr = minMultRec(arr, i, k)     // Cost of left part
                 + minMultRec(arr, k, j)     // Cost of right part
                 + arr[i] * arr[k] * arr[j]; // Cost of multiplying the two parts

        res = min(curr, res);   // Keep the smaller cost
    }

    // Return the minimum cost found
    return res;
}

// Sets up and calls the recursive function
int matrixMultiplication(vector<int> &arr)
{
    int n = arr.size();                // Get total number of dimensions
    return minMultRec(arr, 0, n - 1);  // Solve for the full chain
}

int main()
{
    vector<int> arr = {2, 1, 3, 4};        // Dimensions of the matrix chain
    cout << matrixMultiplication(arr);     // Print the minimum multiplication cost
    return 0;                               
}