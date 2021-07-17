valgrind \
	--track-fds=yes \
	--leak-check=full \
	--show-reachable=yes \
	--error-exitcode=1 \
	--track-origins=yes \
	./test_bin