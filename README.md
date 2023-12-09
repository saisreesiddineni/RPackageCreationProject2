# RPackageCreationProject2
# Binary and Dynamic Segmentation

This R package provides a demonstration of the Binary Segmentation and Dynamic Segmentation algorithms implemented in C++. Users can use this package to perform these algorithms on their data.

## Installation

To install this package from CRAN, you can use the following command:

```R
install.packages("RPackageCreationProject2")
##OR:
if (!requireNamespace("remotes")) install.packages("remotes")
remotes::install_github("saisreesiddineni/RPackageCreationProject2")

Examples:

Binary Segmentation:

set.seed(123)
data <- c(rnorm(50), rnorm(50, mean = 5))
binarySegmentation_algo(data)

Dynamic Segmentation:

set.seed(123)
data <- c(rnorm(50), rnorm(50, mean = 5))
dynamicSegmentation_algo(data)

<!-- badges: start -->
[![R-CMD-check](https://github.com/saisreesiddineni/RPackageCreationProject2/actions/workflows/R-CMD-check.yaml/badge.svg)](https://github.com/saisreesiddineni/RPackageCreationProject2/actions/workflows/R-CMD-check.yaml)
<!-- badges: end -->

