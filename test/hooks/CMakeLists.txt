project(mango-test-hooks)

include_directories(${MANGO_INCLUDE_DIR})

add_executable(mango-test-hooks  HookTest.cpp ../main.cpp)
target_link_libraries(mango-test-hooks gtest ${MANGO_LIBRARIES})
