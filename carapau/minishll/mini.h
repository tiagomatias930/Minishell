#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>



typedef struct s_read
{
	char *input;
	char **historico;
	int contador;
	int capacidade;


}	t_read;

