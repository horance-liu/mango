cmake_minimum_required(VERSION 2.8)

project(mango)

set(MANGO_DISABLE_GTEST OFF CACHE BOOL "Disable Google Test framework")
set(MANGO_ENABLE_EXAMPLES OFF CACHE BOOL "Enable the examples")

#
# File Filter
#

MACRO(sort_files source_files)
  SET(sgbd_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
  FOREACH(sgbd_file ${${source_files}})
    STRING(REGEX REPLACE ${sgbd_cur_dir}/\(.*\) \\1 sgbd_fpath ${sgbd_file})
    STRING(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
    STRING(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
    IF(MSVC)
      string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
    ENDIF(MSVC)
    IF(sgbd_nogroup)
      SET(sgbd_group_name "\\")
    ENDIF(sgbd_nogroup)
    SOURCE_GROUP(${sgbd_group_name} FILES ${sgbd_file})
  ENDFOREACH(sgbd_file)
ENDMACRO(sort_files)

#
# Generic Compiler Flags
#

if(UNIX)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Weffc++")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
elseif(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /vmg")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNOMINMAX")
endif()


#
# Boost
#

set(MANGO_CORE_BOOST_LIBS thread system regex)

set(MANGO_DYNAMIC_BOOST_LIBS ${MANGO_CORE_BOOST_LIBS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBOOST_ALL_DYN_LINK")

if(MANGO_DYNAMIC_BOOST_LIBS)
    find_package(Boost ${BOOST_MIN_VERSION} COMPONENTS ${MANGO_DYNAMIC_BOOST_LIBS})
endif()

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    set(MANGO_EXTRA_LIBRARIES ${MANGO_EXTRA_LIBRARIES} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_REGEX_LIBRARY} ${Boost_DATE_TIME_LIBRARY})
endif()

#
# Mango 
#

set(MANGO_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${MANGO_INCLUDE_DIR})

set(MANGO_LIBRARIES mango jsoncpp ${MANGO_EXTRA_LIBRARIES})

install(DIRECTORY include/mango DESTINATION include)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(examples)
