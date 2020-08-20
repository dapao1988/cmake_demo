PROJECT(curl-demo)
MESSAGE(STATUS "project_name: " ${PROJECT_NAME})
MESSAGE(STATUS "demo project_source_name: " ${PROJECT_SOURCE_DIR})
MESSAGE (STATUS "project binary dir: " ${PROJECT_BINARY_DIR})
MESSAGE (STATUS "project source dir: " ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS" cmake_current_binary_dir:${CMAKE_CURRENT_BINARY_DIR}")
MESSAGE(STATUS" cmake_current_source_dir:${CMAKE_CURRENT_SOURCE_DIR}")

#SET(src_list add1.cpp)
AUX_SOURCE_DIRECTORY(. src_list)
MESSAGE(STATUS "global collect files: " ${src_list})
ADD_DEFINITIONS(-DDEBUG)
MESSAGE (STATUS "CMAKE_C_FLAGS:  ${CMAKE_C_FLAGS}")
MESSAGE (STATUS "CMAKE_CXX_FLAGS:  ${CMAKE_CXX_FLAGS}")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g3")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")
IF(CMAKE_BUILD_TYPE STREQUAL "Release")
    MESSAGE (STATUS "CMAKE_BUILD_TYPE is Release, to strip file")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-s")
ENDIF()
MESSAGE (STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
OPTION(CMAKE_BUILD_TYPE "This is a option for release" "Release")
MESSAGE (STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")


#######################################start to find library####################################
####################################### one way ################################################
#INCLUDE_DIRECTORIES(/usr/include)
ADD_EXECUTABLE(${PROJECT_NAME} ${src_list})
#TARGET_LINK_LIBRARIES(${PROJECT_NAME} curl)
####################################### the other way ##########################################
FIND_PACKAGE(CURL)
IF(CURL_FOUND)
    INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CURL_LIBRARY})
ELSE(CURL_FOUND)
    MESSAGE(FATAL_ERROR ”CURL library not found”)
ENDIF(CURL_FOUND)

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION bin)


