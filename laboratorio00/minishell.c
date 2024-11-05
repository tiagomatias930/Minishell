#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char **argv, char **env)
{
    /*while (env[i++] != NULL)
    {
        if (env[i])
           printf("%s\n", env[i]);
    }
    printf("i: %d", i);
*/
    char    *pwd = getcwd (NULL, 0); // Está linha mostra o caminho absoluto de
    char *line;
    while (1)
    {

        line = readline("bocal > ");
        if (line[0] != '\0')
        {
            printf("%s\n", line);
            printf ("%s\n", pwd);
            add_history(line);
        }
    }
    return (0);
}