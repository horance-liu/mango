project(tags)

include_directories(${MANGO_INCLUDE_DIR})

add_executable(tags_exec features/step_definitions/TagSteps src/main.cpp)
target_link_libraries(tags_exec ${MANGO_LIBRARIES})
