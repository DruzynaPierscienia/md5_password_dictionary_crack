enable_testing()

find_package (GTest REQUIRED)

set( PROJ_TEST_NAME      "runUnitTests" )

include_directories( ${CMAKE_SOURCE_DIR}/src
		     ${CMAKE_SOURCE_DIR}/include
		     ${GTEST_INCLUDE_DIR}
		    )

add_executable( ${PROJ_TEST_NAME}
    main.cpp
)

target_link_libraries( ${PROJ_TEST_NAME}
		       ${LIB_NAME}
		       ${GTEST_LIBRARIES}
		       -lsqlite3
)

add_test(${PROJ_TEST_NAME} ${PROJ_TEST_NAME})
