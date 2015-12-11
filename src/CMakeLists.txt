include_directories(${CMAKE_SOURCE_DIR}/include)

set(LIBRARY_NAME md5_library)

add_library( ${LIBRARY_NAME}
	     passwordsBreaker.cpp
	     dictionaryPasswordsSource.cpp
	     md5SumGenerator.cpp
	     passwordsMatcher.cpp
	     digitsPasswordsSource.cpp
	     lettersConverter.cpp
	     screenPrinter.cpp
	     mergingPasswordsGenerator.cpp
)

add_executable ( ${PROJ_NAME}
	       main.cpp )   

target_link_libraries( ${LIBRARY_NAME}
		       -lcrypto 
		       )
		       
target_link_libraries( ${PROJ_NAME}
		       ${LIBRARY_NAME}
		       )

set_target_properties( ${PROJ_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build )
