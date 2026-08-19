#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Function: coinChange
 * Purpose : Computes minimum coins required and prints the exact coins used.
 * Algorithm: Bottom-Up Dynamic Programming (Tabulation)
 */
void coinChange(const vector<int>& coins, int amount)
{
    // dp[i] stores the minimum number of coins required for amount i
    // Initialize with amount + 1 (representing infinity/unreachable)
    vector<int> dp(amount + 1, amount + 1);

    // coinUsed[i] stores the coin value used to reach the optimal solution for amount i
    vector<int> coinUsed(amount + 1, -1);

    // Base Case: 0 coins needed to make amount 0
    dp[0] = 0;

    // Fill the DP table for all sub-amounts from 1 to amount
    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i)
            {
                if (dp[i - coin] + 1 < dp[i])
                {
                    dp[i] = dp[i - coin] + 1;
                    coinUsed[i] = coin; // Track coin used for backtracking
                }
            }
        }
    }

    // Output Header
    cout << "\n----------------------------------------" << endl;
    cout << "            PRACTICAL RESULT            " << endl;
    cout << "----------------------------------------" << endl;

    // If amount cannot be formed
    if (dp[amount] > amount)
    {
        cout << "Result: Change cannot be made with given coins." << endl;
        cout << "----------------------------------------\n" << endl;
        return;
    }

    cout << "Minimum number of coins: " << dp[amount] << endl;
    cout << "Coins used             : ";

    // Backtrack using coinUsed vector to print the chosen coins
    int currentAmount = amount;
    while (currentAmount > 0)
    {
        int coin = coinUsed[currentAmount];
        cout << coin << " ";
        currentAmount -= coin;
    }

    cout << "\n----------------------------------------\n" << endl;
}

int main()
{
    int n, amount;

    cout << "========================================" << endl;
    cout << "  DYNAMIC PROGRAMMING: COIN CHANGE PROBLEM  " << endl;
    cout << "========================================" << endl;

    cout << "Enter number of coin types: ";
    if (!(cin >> n) || n <= 0)
    {
        cout << "Invalid number of coins!" << endl;
        return 1;
    }

    vector<int> coins(n);
    cout << "Enter coin values (space-separated): ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter target amount: ";
    if (!(cin >> amount) || amount < 0)
    {
        cout << "Invalid target amount!" << endl;
        return 1;
    }

    // Execute Coin Change algorithm
    coinChange(coins, amount);

    return 0;
}