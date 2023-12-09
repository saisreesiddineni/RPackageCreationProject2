library(RPackageCreationProject2)
library(testthat)
context("dynamicsegmentation")

test_that("dynamicSegmentation_algo computes the same answer as R", {
  set.seed(123)
  data <- c(rnorm(50), rnorm(50, mean = 5))
  dynamicSegmentation <- dynamicSegmentation_algo(data)
  expect_equal(length(dynamicSegmentation), 100)
  
  data <- c(rnorm(500), rnorm(500, mean = 5))
  dynamicSegmentation <- dynamicSegmentation_algo(data)
  expect_equal(length(dynamicSegmentation), 1000)
  
})