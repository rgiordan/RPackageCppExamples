# include <iostream>
# include <shared_function.h>

double SharedFunction(double x) {
  std::cout << "Now I'm in a shared library:" << x << "\n";
  return 2 * x;
}

template <typename T> T TemplateFunction(T x) {
  std::cout << "Now I'm in a shared template function: " << x << "\n";
  std::cout << "My type is " << typeid(x).name() << "\n";
  return 3 * x;
};

// Any template not explicitly instantiated will cause a linking error with R.
template double TemplateFunction(double);
