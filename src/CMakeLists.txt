include_directories(${CMAKE_SOURCE_DIR}/include)

ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

add_executable( ${PROJ_NAME} main.cpp )

set_target_properties( ${PROJ_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR} )

target_link_libraries( ${PROJ_NAME}
		       )
