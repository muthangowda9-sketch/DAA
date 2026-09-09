#include <iostream>
#include <chrono>
using namespace std;

int matrixChainMultiplication(int p[], int n)
{
    int dp[n + 1][n + 1];

    // Cost of multiplying one matrix is 0
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    // length = number of matrices in the chain
    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;

            dp[i][j] = 999999999;

            // Try every possible split
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n];
}

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n + 1];

    cout << "Enter dimensions: ";
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    // Start timer
    auto start = chrono::high_resolution_clock::now();

    // Run Matrix Chain Multiplication
    int result = matrixChainMultiplication(p, n);

    // End timer
    auto end = chrono::high_resolution_clock::now();

    // Calculate execution time
    auto time = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "\nMinimum number of multiplications = "
         << result << endl;

    cout << "Execution Time = "
         << time.count() << " ns" << endl;

    return 0;
}
