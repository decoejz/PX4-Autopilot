# # Check if SIGN_TYPE environment variable is defined
# if(DEFINED ENV{SIGN_TYPE})
# 	if("$ENV{SIGN_TYPE}" STREQUAL "RSA")
# 		add_subdirectory(rsa)
# 	else()
# 		add_subdirectory(no_sign)
# 	endif()
# else()
# 	add_subdirectory(no_sign)
# endif()

add_subdirectory(no_sign)
add_subdirectory(rsa)
