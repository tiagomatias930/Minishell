#include "minishell.h"

void    ft_cd(char *path)
{
    if (!path)
        path = getenv("HOME");
    if (!path || chdir(path) != 0)
    {
        perror("cd");
    }
}
