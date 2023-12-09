library(RPackageCreationProject2)
library(testthat)
context("binarysegmentation")

test_that("binarySegmentation_algo computes the same answer as R", {
  set.seed(123)
  data <- c(rnorm(50), rnorm(50, mean = 5))
  binarySegmentation <- binarySegmentation_algo(data)
  expect_equal(binarySegmentation, 50)
  
  data <- c(rnorm(500), rnorm(500, mean = 5))
  binarySegmentation <- binarySegmentation_algo(data)
  expect_equal(binarySegmentation, 500)
  
})