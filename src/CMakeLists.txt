FILE(GLOB_RECURSE all_files
*.cpp
*.cc
*.cxx
*.c
*.C)

sort_files(all_files)

add_library(mango STATIC ${all_files})
