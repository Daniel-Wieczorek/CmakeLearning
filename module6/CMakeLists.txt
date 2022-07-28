
# ADD VARIABLE TO CPP CODE:
add_definitions(-Dsomevariablename="${CMAKE_SOURCE_DIR}")

# AND THEN:
std::cout<<somevariablename<<"\n";

#[[

1. You are making a project, which does not dependent on 
any external library. In this case, you can directly set 
a normal variable CMAKE_BUILD_TYPE to Debug or Release, 
while generating build system files. To do that, simply 
execute

    cmake -DCMAKE_BUILD_TYPE=Debug .. or
    cmake -DCMAKE_BUILD_TYPE=Release .. commands.

You will see that the release build is faster and also 
has less file size compared to the debug build. When 
you set the CMAKE_BUILD_TYPE variable, the compiler 
flags are automatically modified to offer you the 
desired optimization levels.

=========================================================
2. You want to use an external library in the 
Debug/Release mode.

2a. Firstly, you will download the external library's 
source codes and compile it in both debug and release 
modes. You MUST have separate folders containing the 
debug binaries and release binaries. Say the external 
debug library is in /some/path/foo/debug/libfoo.so and 
the release library is in /some/path/foo/release/libfoo.so .

2b. Say, the executable in your project is called 
my_app then you can use the following command in 
my_app project's CMakeLists.txt file, to link the 
external foo liibrary.

    target_link_libraries( my_app 
            debug  /some/path/foo/debug/libfoo.so 
            optimized  /some/path/foo/release/libfoo.so)

Now, when you will run

    cmake -DCMAKE_BUILD_TYPE=Debug ..

while generating the build files for my_app project ,  
/some/path/foo/debug/libfoo.so will be linked against my_app.

Similarly, when you will run

    cmake -DCMAKE_BUILD_TYPE=Release ..

/some/path/foo/release/libfoo.so will be linked against my_app.
Note here that, running the cmake.. command i.e. without 
any build type will throw an error.

]]