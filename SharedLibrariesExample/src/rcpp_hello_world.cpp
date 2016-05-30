
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


// [[Rcpp::export]]
double RunSharedIntTemplateFunction(int x) {
  Rcpp::Rcout << "Now I'm in R int template function.\n";

  // This would fail when installing the package because shared_function.cpp
  // does not have an integer version of the template function instantiated.
  //   return TemplateFunction(x);

  // This works because the function definition is in the header.
  return TemplateFunctionInHeader(x);
};


// If you uncomment this, linking will fail because TemplateFunctionInHeader
// will not have been instantiated.
// extern template double TemplateFunctionInHeader(double);

// [[Rcpp::export]]
double RunSharedDoubleTemplateFunction(double x) {
  Rcpp::Rcout << "Now I'm in R double template function.\n";
  return TemplateFunctionInHeader(x);
};
