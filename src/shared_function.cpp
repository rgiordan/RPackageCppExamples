# include <iostream>
# include <shared_function.h>

double SharedFunction(double x) {
  std::cout << "Now I'm in a shared library:" << x << "\n";
  return 2 * x;
}

double TemplateFunction(double);
