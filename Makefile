NAME		= minirt

OS			= $(shell uname)

CC			= gcc
CFLAGS		+= #-Wall -Werror -Wextra -g

SRC_FOLD	= src/
LIB_FOLD	= libs/
OBJ_FOLD	= bin/

MAIN_DIR	= main/
TEST_DIR	= test/

DEP_LIBS	= libft/libft.a

LINUX_DEPS	= minilibx_linux/libmlx.a

MACOS_DEPS	= minilibx_opengl/libmlx.a

ifeq ($(OS), Linux)
	DEP_LIBS += $(LINUX_DEPS)
endif

ifeq ($(OS), Darwin)
	DEP_LIBS += $(MACOS_DEPS)
endif

DEPENDENTS	= $(addprefix $(LIB_FOLD), $(DEP_LIBS))

APP_SRC		= main.c frame/frame.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c  \
				file_op.c scene_parser.c scene.c utils.c edit_line_utils.c \
				data_placement.c objects.c gc/gc.c frame/r_vec3.c frame/ray.c frame/hit_objects.c
APP_OBJ		= $(APP_SRC:.c=.o)

SOURCES		= $(addprefix $(SRC_FOLD), $(addprefix $(MAIN_DIR), $(APP_SRC)))
OBJECTS		= $(addprefix $(OBJ_FOLD), $(addprefix $(MAIN_DIR), $(APP_OBJ)))


# LINKER FLAGS: FLAGS TO DEFINE LINKINGS
LFLAGS		:= $(addprefix -I,$(dir $(DEPENDENTS))) $(addprefix -I,$(addsuffix src, $(dir $(DEPENDENTS)))) $(addprefix -I,$(addprefix $(SRC_FOLD), $(MAIN_DIR)))

FLAG_LINUX	= -lXext -lX11 -lm -lz

FLAG_MACOS	= -framework OpenGL -framework AppKit

$(NAME): $(DEPENDENTS) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(DEPENDENTS) $(FLAG_MACOS) -o $(NAME)

all: $(NAME)


test:
	make re CFLAGS="-DTEST"
	clear ; ./minirt

$(OBJ_FOLD)%.o : $(SRC_FOLD)%.c
	@echo generating object: $@	
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	@$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@ 

$(LIB_FOLD)% :
	@echo making dependent lib: $@
	@make -C $(dir $@)


re: fclean all

clean:
	@echo removing objects
	@rm -rf $(OBJ_FOLD)

fclean: clean
	@echo removing executable
	@rm -f $(NAME)
	@echo removing libraries
	@for lib in $(DEPENDENTS) ; do \
		make -C  $$(dirname $$lib) clean; \
	done

.PHONY: test all clean fclean re