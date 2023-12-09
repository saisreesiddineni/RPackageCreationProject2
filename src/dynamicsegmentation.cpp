#include "dynamicsegmentation.h"

#include <Rcpp.h>
using namespace Rcpp;

// Function to perform dynamic segmentation
// Input: NumericVector x - input data vector
// Output: IntegerVector - vector of changepoint indices
IntegerVector dynamicSegmentation(NumericVector x) {
  int n = x.size();
  NumericVector cost(n + 1, INFINITY); // Vector to store the cumulative cost
  IntegerVector last_index(n + 1, 0);  // Vector to store the last index of each segment
  
  cost[0] = 0; // Cost for an empty segment is 0
  
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      // Calculate the cost of the current segment
      double currentCost = cost[j - 1] + sum(pow(x[seq(j - 1, i - 1)] - mean(x[seq(j - 1, i - 1)]), 2));
      
      // Update the cumulative cost if the current cost is smaller
      if (currentCost < cost[i]) {
        cost[i] = currentCost;
        last_index[i] = j - 1;
      }
    }
  }
  
  // Backtrack to find the changepoints
  IntegerVector changepoints;
  int i = n;
  while (i > 0) {
    changepoints.push_back(last_index[i]);
    i = last_index[i];
  }
  
  // Reverse the vector to get the changepoints in ascending order
  std::reverse(changepoints.begin(), changepoints.end());
  
  // Return the vector of changepoint indices
  return changepoints;
}
