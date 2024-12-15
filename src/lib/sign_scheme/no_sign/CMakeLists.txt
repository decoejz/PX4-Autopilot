px4_add_library(no_sign
	key_gen.c
	read_key.c
	sign.c
	verify.c
	no_sign.h
)

target_link_libraries(no_sign PUBLIC)
