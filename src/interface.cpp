#include "binarysegmentation.h"
#include "dynamicsegmentation.h"
#include <R_ext/Rdynload.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

RcppExport SEXP dynamicSegmentation_interface(SEXP xSEXP) {
  // Convert SEXP to NumericVector
  NumericVector x(xSEXP);
  
  // Call the C++ function
  IntegerVector result = dynamicSegmentation(x);
  
  return result;
}

RcppExport SEXP binarySegmentation_interface(SEXP xSEXP) {
  // Convert SEXP to NumericVector
  NumericVector x(xSEXP);
  
  // Call the C++ function
  IntegerVector result = binarySegmentation(x);
  
  return result;
}

static const R_CallMethodDef CallEntries[] = {
  {"binarySegmentation_interface", (DL_FUNC) &binarySegmentation_interface, 1},
  {"dynamicSegmentation_interface", (DL_FUNC) &dynamicSegmentation_interface, 1},
  {NULL, NULL, 0}
};

RcppExport void R_init_RPackageCreationProject(DllInfo *dll) {
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}