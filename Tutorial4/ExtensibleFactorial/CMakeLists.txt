add_library(ExtensibleFactorial myFactorial.cpp)

install(TARGETS ExtensibleFactorial DESTINATION lib)
install(FILES myFactorial.h DESTINATION include)