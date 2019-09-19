cmake_minimum_required(VERSION 3.14)

#SET (SRC_LIST helloworld.c)
MESSAGE (STATUS "cmake major version:  ${CMAKE_MAJOR_VERSION}")
MESSAGE (STATUS "cmake minor version:  ${CMAKE_MINOR_VERSION}")
MESSAGE (STATUS "cmake patch version:  ${CMAKE_PATCH_VERSION}")
MESSAGE (STATUS "cmake system:  ${CMAKE_SYSTEM}")
MESSAGE (STATUS "cmake system name:  ${CMAKE_SYSTEM_NAME}")
MESSAGE (STATUS "cmake system version:  ${CMAKE_SYSTEM_VERSION}")
MESSAGE (STATUS "cmake system processor:  ${CMAKE_SYSTEM_PROCESSOR}")
MESSAGE (STATUS "unix:  ${UNIX}")
MESSAGE (STATUS "win32:  ${WIN32}")
MESSAGE (STATUS "BUILD_SHARED_LIBS:  ${BUILD_SHARED_LIBS}")
MESSAGE (STATUS "CMAKE_C_FLAGS:  ${CMAKE_C_FLAGS}")
MESSAGE (STATUS "CMAKE_CXX_FLAGS:  ${CMAKE_CXX_FLAGS}")
MESSAGE (STATUS "cmake_prefix_path: " ${CMAKE_PREFIX_PATH})
MESSAGE (STATUS "cmake_include_path: " ${CMAKE_INCLUDE_PATH})
MESSAGE (STATUS "cmake_framework_path: " ${CMAKE_FRAMEWORK_PATH})
MESSAGE (STATUS "cmake_prefix_path: " ${CMAKE_PREFIX_PATH})
MESSAGE (STATUS "cmake_system_library_path: " ${CMAKE_SYSTEM_LIBRARY_PATH})
MESSAGE (STATUS "cmake_system_framework_path: " ${CMAKE_SYSTEM_FRAMEWORK_PATH})
MESSAGE (STATUS "cmake_find_root_path: " ${CMAKE_FIND_ROOT_PATH})
MESSAGE (STATUS "cmake_find_root_path_mode_library: " ${CMAKE_FIND_ROOT_PATH_MODE_LIBRARY})
#ADD_EXECUTABLE(hello ${SRC_LIST})
MESSAGE (STATUS "executable output path: " ${EXECUTABLE_OUTPUT_PATH})
MESSAGE (STATUS "library output path: " ${LIBRARY_OUTPUT_PATH})
MESSAGE(STATUS" cmake_current_list_file:"${CMAKE_CURRENT_LIST_FILE})
MESSAGE(STATUS" cmake_current_list_line:"${CMAKE_CURRENT_LIST_LINE})
MESSAGE (STATUS "project binary dir: " ${PROJECT_BINARY_DIR})
MESSAGE (STATUS "project source dir: " ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS" cmake_current_binary_dir:${CMAKE_CURRENT_BINARY_DIR}")
MESSAGE(STATUS" cmake_current_source_dir:${CMAKE_CURRENT_SOURCE_DIR}")
MESSAGE(STATUS" cmake_module_path:"${CMAKE_MODULE_PATH})
MESSAGE(STATUS" cmake_module_path: ${CMAKE_MODULE_PATH}")
MESSAGE(STATUS" JAVA_HOME:$ENV{JAVA_HOME}")

MESSAGE(STATUS "Arch platform:")
SET(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)
IF(WIN32)
    MESSAGE(STATUS "WIN32")
ELSEIF(UNIX)
    MESSAGE(STATUS "UNIX")
ELSEIF(APPLE)
    MESSAGE(STATUS "APPLE")
ENDIF(WIN32)
#SET(ENV{变量名} 值)
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/test/bin)
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/test/lib)
ADD_SUBDIRECTORY(add2 add2)
ADD_SUBDIRECTORY(add1 add1)
ADD_SUBDIRECTORY(add add)
ADD_SUBDIRECTORY(demo demo)
ADD_SUBDIRECTORY(curl-example curl-example)

#INSTALL(TARGETS add2 add1
#    RUNTIME DESTINATION bin
#    LIBRARY DESTINATION lib
#    ARCHIVE DESTINATION libstatic
#    )
INSTALL(DIRECTORY doc DESTINATION share
    PATTERN "private"   EXCLUDE
    PERMISSIONS OWNER_WRITE OWNER_READ
                GROUP_WRITE GROUP_READ)
#INSTALL(DIRECTORY doc DESTINATION share/hello)
INSTALL(FILES README COPYRIGHT DESTINATION ${CMAKE_INSTALL_PREFIX})
    #    RENAME  readme COPYRIGHT)

##################################define macro for ctest#########################################
macro(do_test ARG1 ARG2 RESULT)
    ADD_TEST(NAME test_add_${ARG1}_${ARG2} COMMAND ${PROJECT_BINARY_DIR}/demo/main ${ARG1} ${ARG2})
    SET_TESTS_PROPERTIES(test_add_${ARG1}_${ARG2}
        PROPERTIES PASS_REGULAR_EXPRESSION ${RESULT})
endmacro(do_test)
##################################define macro for ctest#########################################

#ENABLE_TESTING()
add_test(test_example_no_args ${PROJECT_BINARY_DIR}/demo/main)
SET_TESTS_PROPERTIES(test_example_no_args
    PROPERTIES PASS_REGULAR_EXPRESSION "3")

do_test(5 6 11)
do_test(6 6 12)
do_test(16 16 32)
do_test(26 26 52)
do_test(36 36 72)
do_test(46 46 92)
enable_testing()




################################test exec_program################################################
# ./shell.sh | sed 's/^\s[0-9]*/hello /g' | sed 's/[0-9]*$/world!/g' #
MESSAGE(STATUS "start to execute command!!!!!!!!!!!!!")
MESSAGE(STATUS "current folder path: ${CMAKE_CURRENT_SOURCE_DIR}")
EXECUTE_PROCESS(COMMAND sh ../shell.sh
    #COMMAND sed 's/^ [0-9]*/hello /g'
    #COMMAND sed 's/[0-9]*$/world!/g'
    OUTPUT_VARIABLE log_output
    ERROR_VARIABLE error_output)
MESSAGE(STATUS "content: ${log_output}")
MESSAGE(STATUS "error_output: ${error_output}")

FOREACH(ITEM ${log_output})
    MESSAGE(STATUS "item: ${ITEM}")
ENDFOREACH(ITEM)
################################test exec_program################################################
