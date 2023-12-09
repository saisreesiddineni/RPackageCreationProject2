#' Dynamic Segmentation Algorithm
#'
#' This function performs dynamic segmentation on the input data.
#' @name dynamicSegmentation_interface
#' @param data The input numeric vector.
#'
#' @return An integer vector of changepoint indices.
#'
#' @export
#'
#' @examples
#' data <- c(1.0, 2.0, 3.0, 4.0, 5.0)
#' dynamicSegmentation_algo(data)
dynamicSegmentation_algo <- function(data) {
  result.vec <- .Call("dynamicSegmentation_interface", data)
  result.vec
}
