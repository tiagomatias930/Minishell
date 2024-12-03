/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:46:39 by timatias          #+#    #+#             */
/*   Updated: 2024/12/03 16:00:37 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define YELLOW "\033[33m"
# define PROMPT GREEN "╭─" RESET CYAN "[bocal@time7/] " RESET YELLOW "──►" RESET "\n" GREEN "╰─$ " RESET

# ifndef ERROR_MSG
#  define ERROR_MSG "\033[1;31mERROR\n\033[0m"
# endif

# ifndef EXIT_MSG
#  define EXIT_MSG " "
# endif

# ifndef PROMPT_MSG
#  define PROMPT_MSG GREEN "╭─" RESET CYAN "[bocal@time7/] " RESET YELLOW "──►" RESET "\n" GREEN "╰─$ " RESET
# endif

# ifndef INVALID_USAGE
#  define INVALID_USAGE "invalid usage"
# endif

# ifndef SEP
#  define SEP -1
# endif

# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_token
{
	char			*cmd;
	int				type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_mini
{
	char	*input;
	char	*prompt;
	char	**envp;
	t_token	*token;
	char	error;
	char	exit;
}	t_mini;

typedef struct s_expand
{
	char	**hold_str;
	int		ex;
	int		start;
	int		end;
	int		quotes;
	int		ex_n;
	int		i;
}	t_expand;

typedef struct s_executor
{
	t_token	*temp;
	char	**cmd;
	int		**fd;
	int		status;
	pid_t	*pid;
	int		n_pros;
}	t_executor;

void		exit_handler(t_mini *ms, const char *msg, const int code);
int			check_quotes(char c, int quotes);
char		*ft_mattstr_copy(char **mat);
char		**ft_matdup(char **mat);
char		*free_ptr(char *ptr);
char		**free_mat(char **mat);
t_token		*free_token(t_token *token);
char		**lexer(char *input);
int			parser(t_token **head, char *str);
char		*find_path(char	*cmd, char **envp);
void		check_pipe(char *cmd, t_token **head);
int			syntax_checker(t_mini *ms);
char		*expand(t_mini *ms, char *cmd, char **envp);
void		expander(t_mini *ms, t_token **head, char **envp);
char		*get_envp(t_mini *ms, char *cmd, char **envp);
void		executor(t_mini *ms);
char		**token_to_mat(t_token *token);
void		close_fds(int **fd);
void		child(t_mini *ms, char **cmd, int **fd, int i);
char		**redirect(t_mini *ms, char **cmd, int *out, int *in);
void		set_redirect(t_mini *ms, char **cmd, int *fd, char **ret);
int			execbi(t_mini *ms, char **cmd, char ***envp, char *prompt);
void		ft_echo(t_mini *ms, char **cmd);
void		ft_cd(t_mini *ms, char **cmd, char ***envp);
void		ft_pwd(t_mini *ms, char **cmd, char **envp);
void		ft_export(t_mini *ms, char **cmd, char ***envp);
void		ft_unset(t_mini *ms, char **cmd, char ***envp);
void		ft_env(t_mini *ms, char **cmd, char ***envp);
void		ft_exit(t_mini *ms, char **cmd);

enum e_type{
	PIPE = 10,
	EXECVE = 11,
	BUILDIN = 12,
	ARG = 13,
	ARG_FILE = 14,
	REDIRECT = 15,
	HEREDOC = 16
};

#endif