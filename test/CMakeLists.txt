enable_testing()

find_package(GTest REQUIRED)

set( PROJ_TEST_NAME      "runUnitTests" )

include_directories( ${CMAKE_SOURCE_DIR}/src
		     ${CMAKE_SOURCE_DIR}/include
		     ${GTEST_INCLUDE_DIR}
		    )

add_executable( ${PROJ_TEST_NAME}
		md5SumGeneratorTest.cpp
		main.cpp
)

target_link_libraries( ${PROJ_TEST_NAME}
		       md5_library
		       -lgtest
		       -lcrypto
		       -lpthread
)

set_target_properties( ${PROJ_TEST_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build )

add_test(${PROJ_TEST_NAME} ${PROJ_TEST_NAME})
