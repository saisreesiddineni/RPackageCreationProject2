#include "binarysegmentation.h"

#include <Rcpp.h>
using namespace Rcpp;

// Function to perform binary segmentation
// Input: NumericVector x - input data vector
// Output: IntegerVector - vector of changepoint indices
IntegerVector binarySegmentation(NumericVector x) {
  int n = x.size();
  int bestIndex = -1; // Index of the best changepoint
  double bestCost = INFINITY; // Cost of the best segmentation

  for (int i = 1; i < n; ++i) {
    // Split the vector into two segments
    NumericVector segment1 = x[seq(0, i - 1)];
    NumericVector segment2 = x[seq(i, n - 1)];

    // Calculate the sum of squared differences for each segment
    double cost1 = sum(pow(segment1 - mean(segment1), 2));
    double cost2 = sum(pow(segment2 - mean(segment2), 2));

    // Total cost is the sum of costs for the two segments
    double totalCost = cost1 + cost2;

    // Check if the total cost is better than the current best
    if (totalCost < bestCost) {
      bestCost = totalCost;
      bestIndex = i;
    }
  }

  // Return the vector of changepoint indices
  return IntegerVector::create(bestIndex);
}

