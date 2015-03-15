project(calc)

include_directories(${MANGO_INCLUDE_DIR} src)

add_library(calc src/Calculator.cpp)

add_executable(calc_exec features/step_definitions/CalculatorSteps.cpp src/main.cpp)
target_link_libraries(calc_exec calc gtest ${MANGO_LIBRARIES})
