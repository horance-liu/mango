project(mango-test-std)

include_directories(${MANGO_INCLUDE_DIR})

add_executable(mango-test-std  AlgorithmTest.cpp ../main.cpp)
target_link_libraries(mango-test-std gtest ${MANGO_LIBRARIES})
