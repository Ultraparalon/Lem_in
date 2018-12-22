# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/28 16:58:58 by iseletsk          #+#    #+#              #
#    Updated: 2018/05/12 15:23:01 by vkaidans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
VIS	 = visual

SRC_DIR :=		./sources/
OBJ_DIR :=		./objects/
INC_DIR :=		./includes/
LIB_DIR :=		./libraries/

SRC :=		main.c ft_wizard.c ft_checker.c\
			ft_read_input.c ft_get_coords.c ft_get_pipes.c\
			ft_find_way.c ft_get_ways.c ft_true_path.c\
			ft_output.c ft_process_unit.c\
			ft_list_crd.c ft_list_path.c ft_list_pipe.c

OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

VSRC :=		visual.c \
			vs_get_crds.c vs_get_pipes.c \
			vs_input.c vs_input_mouse.c\
			vs_draw.c vs_get_basic.c vs_render.c vs_vector.c\
			vs_anim.c vs_next_step.c vs_list.c\
			vs_status.c vs_textures.c vs_rainbow.c vs_contrast.c

VOBJ =		$(addprefix $(OBJ_DIR), $(VSRC:.c=.o))

LIBFT =			$(LIBFT_DIR)libft.a
LIBFT_DIR :=	$(LIB_DIR)libft/
LIBFT_INC :=	$(LIBFT_DIR)includes/
LIBFT_FLAGS :=	-lft -L $(LIBFT_DIR)

CC_FLAGS :=		-Wall -Wextra -Werror

LINK_FLAGS :=	$(LIBFT_FLAGS)

HEADER_FLAGS :=	-I $(INC_DIR) -I $(LIBFT_INC)

CC :=		gcc

.SILENT:

all: $(NAME) $(VIS)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CC_FLAGS)  $(OBJ) $(LINK_FLAGS) -lmlx  -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created lem-in"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(VIS): $(LIBFT) $(VOBJ)
	$(CC) $(CC_FLAGS) $(VOBJ) $(LINK_FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(VIS)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created visualization"

$(VOBJ): | $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ) $(VOBJ)
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned lem-in"

fclean: clean
	rm -f $(NAME) $(VIS)
	make fclean -C $(LIBFT_DIR)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned lem-in"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
