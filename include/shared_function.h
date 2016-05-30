# ifndef SHARED_FUNCTION_H
# define SHARED_FUNCTION_H

# include <iostream>
# include <typeinfo>

double SharedFunction(double);

template <typename T> T TemplateFunction(T x) {
  std::cout << "Now I'm in a shared template function: " << x << "\n";
  std::cout << "My type is " << typeid(x).name() << "\n";
  return 3 * x;
};


# endif
