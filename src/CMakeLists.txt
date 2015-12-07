include_directories(${CMAKE_SOURCE_DIR}/include)

add_library( md5_library
	     md5HashedPasswordsReader.cpp
	     md5SumGenerator.cpp
	     passwordBreaker.cpp
)

add_executable ( ${PROJ_NAME}
	       main.cpp )   

target_link_libraries( md5_library
		       -lcrypto 
		       )
		       
target_link_libraries( ${PROJ_NAME}
		       md5_library
		       )

set_target_properties( ${PROJ_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build )
