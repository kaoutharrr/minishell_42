NAME = minishell
Cflags = -Wall -Wextra -Werror 
Lflags = -lreadline -I/Users/kkouaz/Desktop/readline-8.2 -L /Users/kkouaz/Desktop/readline-8.2 -lcurses
Cfiles = execution/builtins.c execution/builtins_check.c execution/exec.c execution/export_tools.c execution/free.c \
		execution/heredoc_ex.c execution/norm.c execution/signals.c execution/tools2.c \
		execution/builtins2.c execution/cd.c execution/export.c execution/files.c execution/heredoc.c execution/lists.c \
		execution/process.c execution/tools.c execution/tools3.c \
 		libft/ft_lstadd_back.c \
		libft/ft_lstlast.c libft/ft_lstnew.c libft/ft_atoi.c libft/ft_putstr_fd.c \
		libft/ft_strjoin.c libft/ft_putchar_fd.c libft/ft_strlcpy.c  libft/ft_strlen.c  libft/ft_isalnum.c \
		libft/ft_strncmp.c libft/ft_isalpha.c libft/ft_split.c libft/ft_strdup.c libft/ft_strnstr.c \
		libft/ft_isdigit.c libft/ft_substr.c libft/ft_lstadd_back_env.c libft/ft_lstlast_env.c \
		libft/ft_lstnew_env.c \
		libft/ft_strjoin_char.c \
		libft/ft_str_env_cmp.c \
		libft/ft_itoa.c   \
		clear_expand2.c split_2dar.c syntax_tools.c fill_node.c \
		alloc_nodes_cmd_files.c clear_list.c expand.c ft_syntax.c split_2dar2.c syntax_tools1.c \
		clear_expand.c create_list.c expanding.c parssing.c split_mask.c execution/export3.c \
		execution/files_norm.c execution/tools4.c main.c

OBJ = ${Cfiles:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
		@$(CC) $(Cflags) $(Lflags)  $(OBJ) -o $(NAME)  

.c.o:
		@$(CC) $(Cflags) -c $< -o $@

clean :
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
