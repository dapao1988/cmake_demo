PROJECT(add1)
MESSAGE(STATUS "project_name: " ${PROJECT_NAME})

SET(src_list add1.cpp)
ADD_LIBRARY(${PROJECT_NAME} SHARED ${src_list})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../add2)
FIND_PATH(add2_header_path add2.h)
MESSAGE(STATUS ${add2_header_path})
IF(add2_header_path)
    MESSAGE(STATUS "add2_header_path:" ${add2_header_path})
INCLUDE_DIRECTORIES(${add2_header_path})
ENDIF(add2_header_path)
SET_TARGET_PROPERTIES(add1 PROPERTIES VERSION 1.0 SOVERSION 1)
MESSAGE(STATUS "add1 include folder: "${PROJECT_SOURCE_DIR}/../add2)
#TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC add1)

ADD_LIBRARY(add1_static STATIC ${src_list})
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../add2)
SET_TARGET_PROPERTIES(add1_static PROPERTIES OUTPUT_NAME "add1")
#TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC add1)

GET_TARGET_PROPERTY(OUTPUT_VALUE add1_static OUTPUT_NAME) 
MESSAGE(STATUS "add1_static OUTPUT_NAME: " ${OUTPUT_VALUE} "\n")

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION lib)
INSTALL(FILES add1.h DESTINATION include)
