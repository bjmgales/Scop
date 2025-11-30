NAME	:= Scop

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -g -O0 -fsanitize=address
AR := ar
RM := rm -f
MKDIR := mkdir -m 777 -p
ECHO := echo

# ********************************* H E A D S *********************************

HFLAGS				:=	-I include\
						-I ./minilibx-linux

# ********************************* F O N T S *********************************

EOC					:=	"\033[0m"
LIGHT				:=	"\033[1m"
DARK				:=	"\033[2m"

ITALIC				:=	"\033[3m"
UNDERLINE			:=	"\033[4m"

BLACK				:=	"\033[30m"
RED					:=	"\033[31m"
GREEN				:=	"\033[32m"
BLUE				:=	"\033[34m"
PURPLE				:=	"\033[35m"
CYAN				:=	"\033[36m"
WHITE				:=	"\033[37m"

# ********************************* L I B S *********************************

MLX_DIR := minilibx-linux
MLX     := $(MLX_DIR)/libmlx.a
MLX_LNK := -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

# ********************************* N A M E S *********************************

SRCS := $(wildcard src/**/*.cpp) $(wildcard src/*.cpp) 
OBJS := $(patsubst src/%.cpp,bin/%.o,$(SRCS))

OBJ_DIRS := $(sort $(dir $(OBJS)))

all: $(NAME)

bin/%.o: src/%.cpp | bin
	@echo \
	$(WHITE)$(ITALIC)"Compiling $<"$(EOC)
	@$(CC) $(HFLAGS) -c $< -o $@

bin:
	@$(MKDIR)  $(OBJ_DIRS)

$(NAME): $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $^ $(MLX_LNK) -o $@
	@$(ECHO)\
	 $(PURPLE)$(LIGHT)"$@"$(EOC)": "$(GREEN)$(ITALIC)"completed"$(EOC)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@$(RM) $(OBJS)
	@echo \
	$(RED)$(LIGHT)$(ITALIC)"Binary files deleted"$(EOC)

fclean: clean
	@$(RM) -r bin $(NAME)
	@echo \
	$(RED)$(LIGHT)$(ITALIC)"Executable deleted"$(EOC)

re: fclean all

.PHONY: all clean fclean re
