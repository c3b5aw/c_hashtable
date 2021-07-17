NAME		= lib_hashtable.a
NAME_TEST	= test_bin

CC		= clang
LINKER	= ar -rcs

SRCS_DIR	 = srcs
OBJS_DIR	 = objs
INCLUDES_DIR = includes

CFLAGS		= -Wall -Wextra -Werror -O3
CSANITIZE	= -g -fsanitize=address
RM			= /bin/rm -f
PRINTER		= printf

SRCS = __private_methods.c hash.c item.c methods.c table.c
OBJS = $(addprefix objs/, $(SRCS:.c=.o))

PREFIX_MSG = "[LIB-HASHTABLE]"
CMP_MSG		= "$(PREFIX_MSG)[\\033[33m\+\\033[37m]"
INF_MSG		= "$(PREFIX_MSG)[\\033[37mINF\\033[0m]"
SCS_MSG		= "$(PREFIX_MSG)[\\033[32mSUC\\033[0m]"

objs/%.o	: srcs/%.c
			@	mkdir -p $(dir $@)
			@	$(PRINTER) "$(CMP_MSG) Compiling $<\n"
			@	$(CC) $(CFLAGS) -c $< -o $@
all		:	$(NAME)
$(NAME)	: 	$(OBJS)
		@	$(LINKER) $@ $^
		@	$(PRINTER) "$(SCS_MSG) $(NAME) @ built !\n"

re		:	fclean all
fclean	:	clean
		@	$(RM) $(NAME)
clean	:
		@	$(PRINTER) "$(INF_MSG) Deleting assets...\n"
		@	$(RM) -r $(OBJS_DIR)

tests:	re
		@	$(CC) $(CFLAGS) tests/main.c tests/basic_tests.c tests/utils.c -I includes $(NAME) -o $(NAME_TEST)
		@	./tests/tester.sh

.PHONY	:	fclean clean re all