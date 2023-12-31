% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/binarysegmentation.R
\name{binarySegmentation_interface}
\alias{binarySegmentation_interface}
\alias{binarySegmentation_algo}
\title{Binary Segmentation Algorithm}
\usage{
binarySegmentation_algo(data)
}
\arguments{
\item{data}{The input numeric vector.}
}
\value{
An integer vector of changepoint indices.
}
\description{
This function performs binary segmentation on the input data.
}
\examples{
data <- c(1.0, 2.0, 3.0, 4.0, 5.0)
binarySegmentation_algo(data)
}
