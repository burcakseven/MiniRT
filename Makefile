NAME		= minirt

OS			= $(shell uname)

OS_LINUX	= Linux
OS_MAC		= Darwin

CC			= gcc
CFLAGS		+= -g #-Wall -Werror -Wextra -g

SRC_FOLD	= src/
LIB_FOLD	= libs/
OBJ_FOLD	= bin/

MAIN_DIR	= sec/
TEST_DIR	= test/

DEP_LIBS	= libft/libft.a

LINUX_DEPS	= minilibx_linux/libmlx.a

MACOS_DEPS	= minilibx_opengl/libmlx.a

ifeq ($(OS), $(OS_LINUX))
	DEP_LIBS += $(LINUX_DEPS)
endif

ifeq ($(OS), $(OS_MAC))
	DEP_LIBS += $(MACOS_DEPS)
endif

DEPENDENTS	= $(addprefix $(LIB_FOLD), $(DEP_LIBS))

APP_SRC		= main.c \
				gc/gc.c \
				get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				matrix/matrix.c \
				objects/sphere.c \
				parser/utils.c parser/create_scene.c parser/data_placement.c \
					parser/objects.c parser/read_scene_data.c\
					parser/edit_line_utils.c \
				ray/ray.c \
				render/get_canvas.c render/render.c render/init_mlx.c \
					render/make_virtural_canvas.c render/get_point_at.c \
					render/render_scene.c \
				scene/scene.c \
				utils/utils.c \
				vec3/vec3.c \
				light/light.c

APP_OBJ		= $(APP_SRC:.c=.o)

SOURCES		= $(addprefix $(SRC_FOLD), $(addprefix $(MAIN_DIR), $(APP_SRC)))
OBJECTS		= $(addprefix $(OBJ_FOLD), $(addprefix $(MAIN_DIR), $(APP_OBJ)))


# LINKER FLAGS: FLAGS TO DEFINE LINKINGS
LFLAGS		:= $(addprefix -I,$(dir $(DEPENDENTS))) $(addprefix -I,$(addsuffix src, $(dir $(DEPENDENTS)))) $(addprefix -I,$(addprefix $(SRC_FOLD), $(MAIN_DIR)))

ifeq ($(OS), Linux)
	OSFLAG = -lXext -lX11 -lz -lm 
endif

ifeq ($(OS), Darwin)
	OSFLAG = -framework OpenGL -framework AppKit
endif

$(NAME): $(DEPENDENTS) $(OBJECTS)
	$(CC) $(OSFLAG) $(OBJECTS) $(DEPENDENTS) -o $(NAME)

all: $(NAME)


test:
	make re CFLAGS="-DTEST"
	clear ; ./minirt

$(OBJ_FOLD)%.o : $(SRC_FOLD)%.c
	@echo generating object: $@	 from: $<
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@ 

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