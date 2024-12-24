find_package(OpenSSL REQUIRED)

px4_add_library(ecdsa
	key_gen.c
	read_key.c
	sign.c
	verify.c
	ecdsa.h
)

target_link_libraries(ecdsa PUBLIC OpenSSL::SSL OpenSSL::Crypto)
