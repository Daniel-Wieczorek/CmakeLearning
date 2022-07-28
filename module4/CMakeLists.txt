cmake_minimum_required(VERSION 3.0.0)

message("\nHello world from cmake\n")

# set variable string and print it

set(NAME Daniel)
set(AGE "23")

message("My name is ${NAME} and my age is ${AGE}\n")

set(Daniel Wieczorek)
message("1")
message(NAME ${NAME} ${${NAME}})
message("2")
message(NAME${NAME}${${NAME}})
message("3")
message("NAME ${NAME} ${${NAME}}")
message("\n")
# lists vs strings in cmake

#|-------------------------|--------------|-----------------|-------------------|
#| Set Commands            | Value of VAR | message(${VAR}) | message("${VAR}") |
#|-------------------------|--------------|-----------------|-------------------|
#|set (VAR aa bb cc)       | aa;bb;cc     | aabbcc          | aa;bb;cc          |
#|-------------------------|--------------|-----------------|-------------------|
#|set (VAR aa;bb;cc)       | aa;bb;cc     | aabbcc          | aa;bb;cc          |
#|-------------------------|--------------|-----------------|-------------------|
#|set (VAR "aa" "bb" "cc") | aa;bb;cc     | aabbcc          | aa;bb;cc          |
#|-------------------------|--------------|-----------------|-------------------|
#|set (VAR "aa bb cc")     | aa bb cc     | aa bb cc        | aa bb cc          |
#|-------------------------|--------------|-----------------|-------------------|
#|set (VAR "aa;bb;cc")     | aa;bb;cc     | aabbcc          | aa;bb;cc          |
#|-------------------------|--------------|-----------------|-------------------|
