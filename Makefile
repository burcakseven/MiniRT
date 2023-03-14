NAME		= minirt

CC			= gcc
CFLAGS		:= -Wall -Werror -Wextra

SRC_FOLD	= src/
LIB_FOLD	= libs/
OBJ_FOLD	= bin/

DEP_LIBS	= minilibx_opengl/libmlx.a

DEPENDENTS	= $(addprefix $(LIB_FOLD), $(DEP_LIBS))

APP_SRC		= main.c frame/frame.c frame/ex.c
APP_OBJ		= $(APP_SRC:.c=.o)

SOURCES		= $(addprefix $(SRC_FOLD), $(APP_SRC))
OBJECTS		= $(addprefix $(OBJ_FOLD), $(APP_OBJ))


# LINKER FLAGS: FLAGS TO DEFINE LINKINGS
LFLAGS		:= $(addprefix -I,$(dir $(DEPENDENTS))) $(addprefix -I,$(SRC_FOLD))

all: $(NAME)

$(NAME): $(DEPENDENTS) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(DEPENDENTS) -o $(NAME)


$(OBJ_FOLD)%.o : $(SRC_FOLD)%.c $(OBJ_FOLD)
	@echo flagler  $(CFLAGS)
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@ 

$(LIB_FOLD)% :
	@echo making dependent lib: $@
	@make -C $(dir $@)

$(OBJ_FOLD):
	mkdir -p $@

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