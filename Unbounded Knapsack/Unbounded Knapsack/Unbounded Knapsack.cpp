#include <iostream>
#include <vector>
#include <algorithm>

// Returns the maximum value with an unbounded knapsack of capacity W
int unboundedKnapsack(int W, const std::vector<int>& wt, const std::vector<int>& val, int n) {
    std::vector<int> dp(W + 1, 0);

    // Fill dp[] using the unbounded knapsack property
    for (int w = 0; w <= W; w++) {
        for (int i = 0; i < n; i++) {
            if (wt[i] <= w) {
                dp[w] = std::max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
    }

    return dp[W];
}

int main() {
    int W = 100; // Weight capacity of the knapsack
    std::vector<int> wt = { 5, 10, 15 }; // Weights of the items
    std::vector<int> val = { 10, 30, 20 }; // Values of the items
    int n = wt.size(); // Number of items

    std::cout << "Maximum value in unbounded knapsack = " << unboundedKnapsack(W, wt, val, n) << std::endl;

    return 0;
}
