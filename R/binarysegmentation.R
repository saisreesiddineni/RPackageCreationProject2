#' Binary Segmentation Algorithm
#'
#' This function performs binary segmentation on the input data.
#' @name binarySegmentation_interface
#' @param data The input numeric vector.
#'
#' @return An integer vector of changepoint indices.
#'
#' @export
#'
#' @examples
#' data <- c(1.0, 2.0, 3.0, 4.0, 5.0)
#' binarySegmentation_algo(data)
binarySegmentation_algo <- function(data) {
  result.vec <- .Call("binarySegmentation_interface", data)
  result.vec
}
