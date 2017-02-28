cmake_minimum_required(VERSION 3.6)
project(CMSC330_Project2)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES module3.cpp expression.h literal.h operand.cpp parse.h parse.cpp plus.h subexpression.cpp subexpression.h symboltable.cpp symboltable.h variable.h variable.cpp minus.h times.h divide.h eq.h ge.h le.h geq.h leq.h not.h and.h or.h tern.h)
add_executable(CMSC330_Project2 ${SOURCE_FILES} times.h divide.h le.h geq.h leq.h not.h and.h or.h tern.h)