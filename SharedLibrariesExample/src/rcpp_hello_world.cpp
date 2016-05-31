
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


// [[Rcpp::export]]
double RunSharedFunctor(double x) {
  Rcpp::Rcout << "Now I'm in R double functor function.\n";
  TemplateFunctor func(x);
  int y = 3;
  Rcpp::Rcout << func(y);

  // This will fail.
  // Note that TemplateFunctionForStruct<int> was not instantiated even
  // though it had to be compiled in order to use the TemplateFunctor operator.
  // int z = TemplateFunctionForStruct(y);

  // This will fail because the functor's operator hasn't been instantiated
  // for double types.
  // double z = 3.2;
  // Rcpp::Rcout << func(z);

  return 0;
};


// [[Rcpp::export]]
double RunSharedTemplateClass(double x) {
  Rcpp::Rcout << "Now I'm in R double class function.\n";
  TemplateClass<double> temp_class(x);
  double y = 3;
  return temp_class.Multiply(y);
}
