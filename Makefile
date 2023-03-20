NAME		= minirt

OS			= $(shell uname)

CC			= gcc
CFLAGS		:= -Wall -Werror -Wextra -g

SRC_FOLD	= src/
LIB_FOLD	= libs/
OBJ_FOLD	= bin/

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
scene2/file_op.c scene2/scene_parser.c scene2/scene.c scene2/utils.c scene2/edit_line_utils.c scene2/data_placement.c scene2/object.c
APP_OBJ		= $(APP_SRC:.c=.o)

SOURCES		= $(addprefix $(SRC_FOLD), $(APP_SRC))
OBJECTS		= $(addprefix $(OBJ_FOLD), $(APP_OBJ))


# LINKER FLAGS: FLAGS TO DEFINE LINKINGS
LFLAGS		:= $(addprefix -I,$(dir $(DEPENDENTS))) $(addprefix -I,$(SRC_FOLD))

FLAG_LINUX	= -lXext -lX11 -lm -lz

FLAG_MACOS	= -framework OpenGL -framework AppKit

$(NAME): $(DEPENDENTS) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(DEPENDENTS) $(FLAG_MACOS) -o $(NAME)

all: $(NAME)

$(OBJ_FOLD)%.o : $(SRC_FOLD)%.c
	@echo generating object: $@	
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	@$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@ 

$(LIB_FOLD)% :
	@echo making dependent lib: $@
	@make -C $(dir $@)


clean:
	@echo removing objects
	@rm -rf $(OBJ_FOLD)

fclean: clean
	@echo removing executable
	@rm -f $(NAME)
	@echo removing libraries
	@for lib in $(DEPENDENTS) ; do \
		make -C  $$(dirname $$lib) clean fclean ; \
	done

.PHONY: all clean fclean