cmake_minimum_required(VERSION 3.0.0)

set(VAR YES)

# ========================================================

if(VAR)
    message("If block number one")
else()
    message("Else block executed")
endif()

# ========================================================

set(Name ALice)

if(DEFINED Name)
    message("Name definied")
else()
    message("Name not definied")
endif()

# ========================================================
if(COMMAND target_link_library)
    message("Command definied")
else()
    message("Command not definied")
endif()


if(COMMAND target_link_libraries)
    message("Command definied")
else()
    message("Command not definied")
endif()

# ========================================================
if (EXISTS /home/daniel/_workareas/general-playground/cmake/module5/CMakeLists.txt)
    message("File definied")
else()
    message("File not definied")
endif()

# ========================================================
set(Name1 Alice)
set(Name2 bb)

if(Name1 STRLESS Name2 OR Name1 STRGREATER Name2)
    message("${Name1} is less or bigger than ${Name2}")
elseif(Name1 STREQUAL Name2)
    message("${Name1} is the same as ${Name2}")
endif()

# ========================= WHILE ===============================
set(VAR a)

while(NOT VAR STREQUAL "aaaaaaaaa")
    set(VAR ${VAR}a)
    message(${VAR})
endwhile()

# ========================= FOR EACH ===============================
foreach(Person Alice;Bob;Charlie)
    message(${Person})
endforeach()

foreach(x RANGE 100 105)
    message("Person_${x}")
endforeach()


set(VALUE1 0;1)
set(VALUE2 2 3)
set(VALUE3 "4;6")

foreach(x IN LISTS VALUE1;VALUE2;VALUE3)
    message("x = ${x}")
endforeach()

# ALL FUNCTIONS INTRODUCE INSIDE LOCAL SCOPE SO VARIABLES ARE MODIFIED
# INSIDE FUNCTION AND NOT AFFECT PARAMERERS IN THE GLOBAL SCOPE
# ========================= FUNCTIONS ===============================

function(print_detail1 variable1)
    message("1 My name is ${variable1}")
endfunction()

set(functionNAME Charile)
print_detail1("${functionNAME}")

# OR we can also:

function(print_detail2 variable1)
    message("2 My name is ${${variable1}}")
endfunction()

set(functionNAME Charile)
print_detail2(functionNAME)

function(print_detail2 variable1)
    message("3 My name is ${${variable1}}")
endfunction()

set(functionNAME Tomas)
_print_detail2(functionNAME) # Jak zawolac przeslanieta funkcje - trzeba dodac podkreslenie -> _

# ========================= FUNCTION ARGUMENTS ===============================

function(printing_detail1 variable1)
    message("2 My name is ${${variable1}}")
    if(DEFINED ARGV1)
        message("More than 1 argument passed: ${ARGV1}")
    endif()
endfunction()

set(functionNAME Charile)
printing_detail1(functionNAME, Bartosz)

# MORE ARGUMENTS
function(printing_detail2 variable1)
    message("List of all arguments: ${ARGV}")
    message("Total count of arguments: ${ARGC}")
    message("List of optional arguments: ${ARGN}")
endfunction()

set(functionNAME Charile)
printing_detail2(functionNAME Bartosz)

# ========================= MACRO ===============================
# WITH MACRO YOU WORK WITH ORIGINAL SCOPE - IN FUNCTIONS YOU HAVE NEW SCOPE 
message("*****************  MACRO  *****************")
macro(printing_macro variable1)
    message("My name is: ${variable1}") # PRINT Charile
    set(variable1 abc)
    message("My name is: ${variable1}") # PRINT Charile -> no new scope, still global scope
endmacro()

printing_macro(Charile)

# ========================= EXTERNAL MODULE ===============================
message("*****************  EXTERNAL MODULE  *****************")
include(ProcessorCount)
ProcessorCount(VAR)
message("Number of processors are: ${VAR}")

# ========================= VARIABLES ===============================
message("*****************  VARIABLES LOCAL AND CACHE *****************")
set(A "000")
set(A "123", CACHE STRING "A is a Cache variable") # CACHE VARIABLE
message($CACHE{A})

set(ENV Beta "000") # GLOBAL (envorimoent) VARIABLE
message($ENV{A})

# ========================= -D FLAG ===============================

# In the CmakeCache.txt cache variables are stored. To chage value of
# these variables you have to pass -DvariableName to change value of
# the variabble. Otherwise it will be not changed.

# ========================= COMMENT ===============================

#[[
So far, we have been writing our CMake codes in CMakelists.txt files. 
These files are collectively called the ListFiles.

Apart from the listfiles, we also have the concept of modules, where 
the CMake codes are written. These modules have .cmake extension.


CMake provides some standard modules containing the CMake codes so 
that we can directly use those in any project. You can find those 
in the /usr/local/share/CMake-3.16/Modules directory.

These modules can be used with the include() command. If you want 
to use this module, you need to write these 2 lines of code and 
then the variable VAR will contain the number of processors.

include(ProcessorCount)
ProcessorCount(VAR)
message("Number of processors are: ${VAR}")


You can use this VAR variable in your project if you want to 
run parallel jobs of any process.

Apart from the standard modules, you can also make your own 
module.Let us see an example.

We can create this directory structure with 2 files 
CMakeLists.txt and my_module.cmake

+module7
   -CMakeLists.txt
   -my_module.cmake
   +build
The CMakeLists.txt file will contain the following lines:

cmake_minimum_required(VERSION 3.0.0)
project(Calculator_Project VERSION 1.0.0)
include(my_module)
and the my_module.cmake file will contain just the following line:

message("Hello from the my_module.cmake file!")
At this time running the CMake command will give an error, because we also need to specify the path 
which contains the my_module.cmake file. To specify that path, we have a variable called CMAKE_MODULE_PATH 
which contains the lists of paths to search the module. This variable is a cache variable and you will learn 
about the cache variable in the next module. For now, we will modify this list inside the CMakeLists.txt 
file to suit our needs. The final CMakeLists.txt file will contain the following lines:

cmake_minimum_required(VERSION 3.0.0)
project(Calculator_Project VERSION 1.0.0)
list(APPEND  CMAKE_MODULE_PATH  <path-to-module5-directory>)
include(my_module)


Now you can run the cmake .. command from the build directory and 
the output will be:

Hello from the my_module.cmake file!


Now you might think that this command is similar to add_subdirectory() 
command, but it's not! When we use the include() command, we do not 
introduce a new scope. This means that if we set or modify a variable 
inside the my_module.cmake file, that modification is going to reflect 
inside the CMakeLists.txt file.



The modules are often used if we want to have reusable code in our project. 
Also if your CMakeLists.txt file is too long, some part of it can be written 
inside another .cmake file; to improve the readability of the code.
]]

