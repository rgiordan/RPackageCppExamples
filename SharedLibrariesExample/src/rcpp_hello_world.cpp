
#include <Rcpp.h>
#include "shared_function.h"

using namespace Rcpp;

// [[Rcpp::export]]
double RunSharedFunction(double x) {
  Rcpp::Rcout << "Now I'm in R.\n";
  return SharedFunction(x);
};


// [[Rcpp::export]]
double RunSharedTemplateFunction(double x) {
  Rcpp::Rcout << "Now I'm in R double template function.\n";
  return TemplateFunction(x);
};


// This would fail when installing the package because shared_function.cpp
// does not have an integer version of the template function instantiated.
// // [[Rcpp::export]]
// double RunSharedTemplateFunctionInt(int x) {
//   Rcpp::Rcout << "Now I'm in R int template function.\n";
//   return TemplateFunction(x);
// };
