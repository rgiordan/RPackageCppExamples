
# To install:
library(devtools)
library(Rcpp)
compileAttributes("SharedLibrariesExample")
install_local("SharedLibrariesExample")

# To use:
library(SharedLibrariesExample)
RunSharedFunction(5)
RunSharedTemplateFunction(5)
RunSharedIntTemplateFunction(5)
