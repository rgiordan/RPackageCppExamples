# ifndef SHARED_FUNCTION_H
# define SHARED_FUNCTION_H

# include <iostream>
# include <typeinfo>

double SharedFunction(double);


template <typename T> T TemplateFunction(T x);


template <typename T> T TemplateFunctionInHeader(T x) {
  std::cout << "Now I'm in a shared template function defined in the header: "
    << x << "\n";
  std::cout << "My type is " << typeid(x).name() << "\n";
  return 4 * x;
};

template <typename T> T TemplateFunctionForStruct(T x);

struct TemplateFunctor {
  double x;
  TemplateFunctor(double x): x(x) {};
  template <typename T> T operator()(T);
};


template <class T> class TemplateClass {
public:
  T x;
  T Multiply(T);
  TemplateClass(T);
  TemplateClass();
};

# endif
