NAME	:= Scop

CC := c++
CFLAGS :=  -std=c++98 -g -fsanitize=address
RM := rm -f
MKDIR := mkdir -m 777 -p

# ********************************* H E A D S *********************************

HFLAGS := -I include \
          -I minilibx-linux

# ********************************* M L X *********************************

MLX_DIR := minilibx-linux
MLX     := $(MLX_DIR)/libmlx.a
MLX_LNK := -L $(MLX_DIR) -lmlx -lXext -lX11 -lbsd -lm


# ********************************* S R C S *********************************

SRCS := $(wildcard src/**/*.cpp) $(wildcard src/*.cpp)
OBJS := $(patsubst src/%.cpp,bin/%.o,$(SRCS))
OBJ_DIRS := $(sort $(dir $(OBJS)))

all: $(NAME)

# --- Object compilation ---
bin/%.o: src/%.cpp | bin
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(HFLAGS) -c $< -o $@

bin:
	@$(MKDIR) $(OBJ_DIRS)

# --- Link ---
$(NAME): $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LNK) -o $@
	@echo "$(NAME): built successfully"

# Build MLX if needed
$(MLX):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@$(RM) $(OBJS)
	@echo "Objects deleted"

fclean: clean
	@$(RM) -r bin $(NAME)
	@echo "Executable deleted"

re: fclean all

.PHONY: all clean fclean re
