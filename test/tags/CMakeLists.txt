project(mango-test-tags)

include_directories(${MANGO_INCLUDE_DIR})

add_executable(mango-test-tags  OrTagExprTest.cpp AndTagExprTest.cpp ../main.cpp)
target_link_libraries(mango-test-tags gtest ${MANGO_LIBRARIES})
