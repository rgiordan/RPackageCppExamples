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


template <typename T> T TemplateFunctionForStruct(T x) {
  std::cout << "Now I'm in a struct shared template function: " << x << "\n";
  std::cout << "My type is " << typeid(x).name() << "\n";
  return 4 * x;
};

template <typename T> T TemplateFunctor::operator()(T y) {
  return TemplateFunctionForStruct(y) + x;
};

template int TemplateFunctor::operator()(int y);

template <class T> TemplateClass<T>::TemplateClass(T z) {
  x = z;
};

template <class T> TemplateClass<T>::TemplateClass() {
  x = 2;
};

template <class T> T TemplateClass<T>::Multiply(T z) {
  return z * x;
};

template class TemplateClass<double>;
