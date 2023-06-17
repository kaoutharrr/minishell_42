/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:45:57 by adadoun           #+#    #+#             */
/*   Updated: 2023/06/17 04:10:23 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <termios.h>
# include <unistd.h>

typedef struct t_norm
{
	int				flag;
}					t_norm;

typedef struct t_list
{
	char			*content;
	struct t_list	*next;
}					t_list;

typedef struct t_global
{
	t_list			*global;
	int				status;
	int				is_signled;
}					t_global;

t_global			g_llobal;

typedef struct t_files
{
	char			*file;
	int				type;
	int				fd;
}					t_files;

typedef struct t_cmd
{
	int				index;
	char			**command;
	struct t_files	*files;
	struct t_cmd	*next;
}					t_cmd;

typedef struct t_args
{
	int				cmd_index;
}					t_args;

typedef struct t_vars
{
	int				word;
	char			*mask;
	char			**ar_2d;
	int				i_2d;
	int				i_file;
	int				i_cmd;
	t_list			*myenv;
	char			*str_exp;
	int				i_xp;
	int				i_er;
	int				no_quotes;
	char			*str_err;
	char			*str_quotes;
	char			*var_nw;
	int				n_cmd;
	char			*str_her;
	int				i_her;
	char			*str_amb;
	int				i_amb;
}					t_vars;
/**/
typedef struct t_ex
{
	int				in;
	int				out;
	int				ka;
	int				ji;
	int				*pid;
	int				*fds;
}					t_ex;

typedef struct t_print
{
	int				flag;
	int				j;
	char			*s;
	char			**split;
	char			*join;
	char			*str1;
	char			*str0;
	char			*s2;
}					t_print;

void				ft_free_lst(t_cmd **lst);
char				*parssing(t_cmd **lst, t_vars *vars, char *input);
char				*empty_cmd(char *input);
int					ft_lst_size(t_cmd *lst);
void				ft_free_allocation2(t_cmd **lst, t_vars *vars);
void				ft_free_allocation(t_cmd **lst, t_vars *vars, char *input);
char				*exit_status(t_vars *vars);
int					exit_child_process(char **command);
void				builtins_child(char **command, int fd);
char				*rm_quotes(char *input, int i, char *str, char *temp);
int					ambigious2(char *file, int j, int k);
void				infinite_export(t_print *print, char *str);
void				no_equal(char *command, char *s, int flag);
void				free_export(char *s, char **arr, char *var);
char				*heredoc_norm(char *file, char *line);
void				clear_list(t_cmd **lst, t_vars *vars);
char				*get_env_value_her(char *str);
void				detect_variable_her(t_vars *vars, char *input);
char				*expand_her(char *input);
char				*split_2dar(t_vars *vars, int n, int i, int j);
int					ft_error(char *input, char *str, int status);
/**/
char				**clear_expand2(t_vars *vars);
int					calculate_cmd(t_vars *vars);
int					calculate_cmd_nopipe(t_vars *vars);
void				free_2d(t_vars *vars);
/**/
int					redirection_before(t_vars *vars);
char				*clear_expand(t_vars *vars);
int					nword(const char *s, char c);
int					calculate_str(char **str, int i, int n);
char				*creat_mask_n(char *str, char *mask);
/**/
int					ft_synstax(char *input, t_vars *vars);
char				*check_right_redirection(t_vars *vars, char *input);
char				*check_left_redirection(t_vars *vars, char *input);
char				next_char(t_vars *vars, char *input);
/**/
char				*single_dollar(t_vars *vars);
char				*detect_variable(t_vars *vars, char *variable, char *value,
						char *temp);
char				*no_quotes(t_vars *vars);
char				*double_quotes(t_vars *vars);
char				*single_quotes(t_vars *vars);
/**/
t_list				*my_env(char **env);
char				*expand(t_vars *vars, char *temp, int ok);
char				*get_env_value(char *str);
int					special_char(char c);
/**/
void				ft_input_redirection(t_cmd **lst, t_vars *vars);
void				ft_output_redirection(t_cmd **lst, t_vars *vars);
void				ft_herdoc(t_cmd **lst, t_vars *vars);
void				ft_append(t_cmd **lst, t_vars *vars);
void				ft_command(t_cmd **lst, t_vars *vars);
/**/
void				aloc_nodes(t_cmd **lst, t_args *args, t_vars *vars);
void				alloc_cmd(t_cmd **lst, t_vars *vars);
void				alloc_files(t_cmd **lst, t_vars *vars);
/**/
char				*create_list(t_cmd **lst, t_vars *vars);
char				*create_2d_array(t_vars *vars, char *str);
/**/
void				ft_free_2d_array(char **str);
/**/
void				ft_lstadd_back_env(t_list **lst, t_list *new);
t_list				*ft_lstlast_env(t_list *lst);
t_list				*ft_lstnew_env(char *str);
t_cmd				*ft_lstnew_1(int i);
t_cmd				*ft_lstlast_1(t_cmd *lst);
void				ft_lstadd_back_1(t_cmd **lst, t_cmd *new);

int					before_exec(t_cmd *cmd);
int					is_builtin_child(char **cmd);
int					find_first_equal(char *str, char c);
int					should_expand(char *name);
int					ft_parse2(char **var, int flag, char *str, int i);
void				execute_cmd(char **paths, char **command, char **arr);
void				protections(char **command, char **arr);
void				ft_close(int fd1, int fd2, int ex);
void				last_cmd(int in, int out);
void				middle_cmd(int in, int out, int fd);
void				heredoc_fork(t_cmd *cmd, int **ends);
int					error_cd(char *s1, char *s2, int status);
void				fill_end(t_cmd *cmd, int **end);
int					close_heredoc(int **ends, int a, char **command);
int					*files_norm(t_files *files, int i, int *fd);
int					in_open(t_files *files, int i, int fd);
int					open_out(t_files *files, int i, int fd);
int					append(t_files *files, int i, int fd);
char				*old_var(char **arr, char *s, char *var);
char				*new_var(char *s, char *var);
void				export_add(char **arr, char *s, char *var);
void				check_flag(int flag, char *command);
void				print_env(t_print print, int fd, int j, char **arr);
int					cmdprocess(t_ex *exec, t_cmd *cmd, int i);
char				*cd1(char *command);
void				ft_update(char *dir, char *current);
void				check_env(t_list *tmp, int fd);
void				unset1(char **arr, char *command);
void				print_command(char **command, int fd);
int					echo1(char **command, int fd);
void				free_list2(t_list *head);
int					**myfree_int(int **p, int size);
void				quithandle(int num);
void				sighandle(int num);
void				sigint_handle(int sig_num);
int					ft_check_n(char *command);
void				printf_env(char **arr, int i);
void				heredoc_pro(t_files files, int end);

void				norm_join(t_print *print);
void				write_free(t_print print, int fd);
int					heredoc_process(t_cmd *cmd);
int					*open_files(t_cmd *cmd);
int					ft_strcmp(char *s1, char *s2);
int					check_heredoc(t_cmd *cmd);
void				exec(t_cmd *cmd, int i);
void				ft_input_redirection(t_cmd **lst, t_vars *vars);
void				ft_output_redirection(t_cmd **lst, t_vars *vars);
void				ft_herdoc(t_cmd **lst, t_vars *vars);
void				ft_append(t_cmd **lst, t_vars *vars);
void				ft_command(t_cmd **lst, t_vars *vars);
/**/
void				aloc_nodes(t_cmd **lst, t_args *args, t_vars *vars);
void				alloc_cmd(t_cmd **lst, t_vars *vars);
void				alloc_files(t_cmd **lst, t_vars *vars);
/**/
char				*create_list(t_cmd **lst, t_vars *vars);
char				*create_2d_array(t_vars *vars, char *str);
/**/

t_cmd				*ft_lstlast_1(t_cmd *lst);
void				error(char *s, int fd, int ex);
t_list				*ft_lstnew(char *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					lstsize(t_list *tmp);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					open_outfiles(t_cmd *cmd);
int					process(t_cmd *cmd, t_ex **exec, int count);

void				child_process(t_cmd *cmd, t_ex *exec, int *fd, int count);
char				**fill_arr(void);
t_list				*my_env(char **env);
void				ft_execute(t_cmd *cmd, char **arr);
void				not_found(char *s1, char *s2, int ex);
void				protection(char **command, char **arr);
char				**find_path(char **arr);
char				**myfree(char **p);
int					is_builtin(char **cmd);
void				builtins(char **command, int fd);
int					echo_process(char **command, int fd);
int					cd_process(char **command);
int					pwd_process(int fd);
int					exit_process(char **command);
int					unset_process(char **command);
int					env_process(char **command, int fd);
int					export_process(char **command, int fd);
char				*get_env(char *s);
void				ft_check(char *cmd);
void				remove_list(t_list **head, char *key);
int					ft_parse(char *cmd);
void				selection_sort(char **arr, int n);
void				export1(char **command);
void				export2(char *command, char *var, char *fd);
char				*search(char **arr, char *command);

int					checknext(t_files *files, int type, int i);
// readline :
void				rl_replace_line(const char *text, int a);
void				here_handle(int num);
void				free_list(t_cmd *head);
#endif

//
