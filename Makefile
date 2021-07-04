NAME1	=	push_swap

NAME2	=	checker

SRC		=	push_swap.c operations.c sorting_functions.c stack_instructions.c lst_instructions.c ft_strtrim.c ft_split.c ft_strlcpy.c

SRC_C	= 	operations_check.c stack_instructions_check.c lst_instructions_check.c checker.c ft_strtrim.c ft_split.c ft_strncmp.c ft_strlcpy.c get_next_line_utils.c

INC		=	-I includes -I libft

OBJDIR	=	objs

OBJS	=	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))

OBJS_C = 	$(addprefix $(OBJDIR)/,$(SRC_C:.c=.o))

# LFT		=	libft/libft.a

CFLAGS	=	-Werror -Wall -Wextra

all : $(OBJDIR) $(NAME1) $(NAME2)

$(OBJS): $(OBJDIR)/%.o: %.c
	gcc  -c $(CFLAGS) $< -o $@

$(OBJS_C): $(OBJDIR)/%.o: %.c
	gcc  -c $(CFLAGS) $< -o $@

$(OBJDIR):
	@mkdir -p $@

# $(LFT):
# 	make -C libft/

$(NAME1): $(OBJS)
	gcc -o push_swap $(CFLAGS) $^ -o $@ 

$(NAME2): $(OBJS_C)
	gcc -o checker $(CFLAGS) $^ -o $@ 
clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -rf $(NAME1) $(NAME2) 

re: fclean all