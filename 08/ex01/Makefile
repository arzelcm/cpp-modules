NAME = ex01

#----COLORS----#
DEF_COLOR = \033[0m
WHITE_BOLD = \033[1;39m
BLACK = \033[1;30m
RED = \033[1;31m
RED_REGULAR = \033[0;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PINK = \033[1;35m
CYAN = \033[1;36m


#----COMPILER----#
CC = c++
CCFLAGS += -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g


#----DIRS----#
BIN_DIR = bin/
SRC = src/
INCLUDES = -I./
EXPORTS = exports/

vpath %.cpp Span

#----SHARED----#
SRCS = main.cpp Span.cpp

OBJS = $(SRCS:%.cpp=$(BIN_DIR)%.o)
DEPS = $(OBJS:%.o=%.d)


#----- R U L E S -----#

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(BLUE)Linking objects and creating program...$(DEF_COLOR)\n"
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT_LIB) $(LIBRARIES) $(LIBRARIES_DEPS) -o $(NAME)
	@echo "$(GREEN)[✓] $(PINK)$(NAME)$(GREEN) created!!!$(DEF_COLOR)"

$(BIN_DIR)%.o: %.cpp Makefile
	@printf "$(CYAN)Compiling: $(PINK)$(notdir $<)...$(DEF_COLOR)\n"
	@mkdir -p $(BIN_DIR)
	$(CC) $(CCFLAGS) $(INCLUDES) -MMD -c $< -o $@

clean:
	@rm -rf $(BIN_DIR)
	@echo "$(RED)Binaries deleted$(DEF_COLOR)\n"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Executable deleted$(DEF_COLOR)\n"

re: fclean all


.PHONY: all \
		clean \
		fclean \
		re \

-include $(DEPS)

.SILENT: