BOLD_CYAN=\033[1;36m
BOLD_LCYAN=\033[1;96m
NBLD_LCYAN=\033[0;96m
BOLD_YELL=\033[1;33m
NBLD_YELL=\033[0;33m
RESET_COLOR=\033[0;0m



unittest_buffered_fd_reader:
	@ echo "${BOLD_YELL}Rebuilding lib${NBLD_YELL}"
	make -C ../exports/ shortre
	@ echo "${BOLD_LCYAN}Building unittest${NBLD_LCYAN}"
	gcc buffered_fd_reader_unittest.c ../exports/libftin.a -o f
	@ echo "${BOLD_YELL}Running..."
	@ ./f
	@ rm -f f
	@ echo "${RESET_COLOR}"