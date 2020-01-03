# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE.txt
#---------------------------------------------------------------------------//

FIND_PACKAGE(Python3 COMPONENTS Development NumPy)
if (${Python3_FOUND})
    message(STATUS "PYTHON3 FOUND")
    message(STATUS "Python3 include dir: " ${Python3_INCLUDE_DIRS})
    message(STATUS "Python3 libraries: " ${Python3_LIBRARIES})
    message(STATUS "Python3 NumPy include dir: " ${Python3_NumPy_INCLUDE_DIRS})
else ()
    message(FATAL_ERROR "PYTHON3 NOT FOUND")
endif ()