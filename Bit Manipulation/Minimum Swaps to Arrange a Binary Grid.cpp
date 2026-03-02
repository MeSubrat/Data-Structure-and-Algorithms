class Solution
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> endZeros(n, 0); // Store #0s present in that row from the end.
        for (int i = 0; i < n; i++)
        {
            int j = n - 1; // Start from right side to traverse
            int countZero = 0;
            while (j >= 0 && grid[i][j] == 0)
            {
                countZero++;
                j--;
            }
            endZeros[i] = countZero;
        }

        int steps = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            int need = n - i - 1; // No of zeros required for the particular row
            while (j < n && endZeros[j] < need)
            {
                j++;
            }
            if (j == n)
                return -1;    // If no rows has #0s greater than need then we'll return -1
            steps += (j - i); // Else we'll calculate no of swaps required.

            // After swapping modify the endZeros[] , similaryly as bubble sort,
            while (j > i)
            {
                swap(endZeros[j], endZeros[j - 1]); // Swap with adjacent rows
                j--;
            }
        }
        return steps;
    }
};