NAME				= minishell
CC					= cc
CFLAGS				= -I . -Iincludes -MMD -g -o -Werror -Wall -Wextra
LDFLAGS				= -lreadline

BUILD_FOLDER		= ./build
SRC_FILES			= src/main.c \
						utils/ft_strlen.c \
						utils/ft_split.c \
						utils/ft_calloc.c \
						utils/ft_memset.c \
						utils/ft_strdup.c \
						builtins/echo.c \



OBJ_FILES			= $(SRC_FILES:.c=.o)
BUILD_FILES			= $(addprefix $(BUILD_FOLDER)/, $(OBJ_FILES))

all : $(NAME)

$(NAME) : $(BUILD_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(LDFLAGS) $(BUILD_FILES)

bonus:
	@echo "Bonus are not implemented yet."

$(BUILD_FOLDER)/%.o : %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(BUILD_FILES) $(BUILD_FOLDER)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
