PROJECT(add)
MESSAGE(STATUS "project_name: " ${PROJECT_NAME})

SET(src_list add.cpp)
ADD_LIBRARY(${PROJECT_NAME} SHARED ${src_list})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../add1 ${PROJECT_SOURCE_DIR}/../add2)
SET_TARGET_PROPERTIES(add PROPERTIES VERSION 1.0 SOVERSION 1)
#TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC add)

ADD_LIBRARY(add_static STATIC ${src_list})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../add1 ${PROJECT_SOURCE_DIR}/../add2)
SET_TARGET_PROPERTIES(add_static PROPERTIES OUTPUT_NAME "add")
#TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC add)

GET_TARGET_PROPERTY(OUTPUT_VALUE add_static OUTPUT_NAME) 
MESSAGE(STATUS "add_static OUTPUT_NAME: " ${OUTPUT_VALUE} "\n")

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION lib)
INSTALL(FILES add.h DESTINATION include)
