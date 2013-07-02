cmake_minimum_required (VERSION 2.6)

# Projektname
project(Collections3)

# Füge Source-Files hinzu
set(SOURCE
  program.cpp
  duck.cpp
)

set(HEADERS
  collection.hpp
  arraylist.hpp
  duck.hpp
)

# Erzeuge Binary
add_executable(Collection3Test ${SOURCE} ${HEADERS})