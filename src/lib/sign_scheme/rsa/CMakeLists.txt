find_package(OpenSSL REQUIRED)

px4_add_library(rsa
	key_gen.c
	read_key.c
	sign.c
	verify.c
	rsa.h
)

target_link_libraries(rsa PUBLIC OpenSSL::SSL OpenSSL::Crypto)
