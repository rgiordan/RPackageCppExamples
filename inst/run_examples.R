
if (FALSE) {
  # To install:
  library(devtools)
  library(Rcpp)
  compileAttributes("SharedLibrariesExample")
  install_local("SharedLibrariesExample")
}

# To use:
library(SharedLibrariesExample)
RunSharedFunction(5)
RunSharedTemplateFunction(5)
RunSharedIntTemplateFunction(5)
RunSharedFunctor(5)
RunSharedTemplateClass(5)
