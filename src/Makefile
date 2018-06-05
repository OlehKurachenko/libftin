BOLD_CYAN=\033[1;36m
BOLD_YELL=\033[1;33m
RESET_COLOR=\033[0;0m

unittest:
	@ make -C exports/ re
	gcc unittest_main.c exports/libftin.a -o f
	@ echo "${BOLD_YELL}Running unit test${RESET_COLOR}"
	@ echo "${BOLD_CYAN}\c"
	@ ./f
	@ echo "${RESET_COLOR}\c"
	rm f
