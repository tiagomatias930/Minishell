#include "mini.h"

void	error(char *error)
{
	printf("%s",error);
}

int	validate(t_read *data)
{
	int i = 0;
	while(data->input[i])
	{
		if(data->input[0] == '|' && data->input[i + 1] == ' ' || data->input[i + 1] == '\t')
		{
			error("bash: erro de sintaxe junto a símbolo ""|"" inesperado\n");
			return (1);	
		}
		else
			return (2);
		i++;
	}
}

int main() {
	
    	t_read	*data = malloc(sizeof(t_read));
    	data->contador = 0;
    	data->capacidade = 10;
    	
	data->historico = (char **)malloc(data->capacidade * sizeof(char *));
	if (data->historico == NULL)
	{
		perror("Erro ao alocar memória");
		return 1;
	}
	while (1)
	{
		data->input = readline("minishell$ ");
		

		if (data->input == NULL)
			break;
		if (strcmp(data->input, "exit") == 0)
		{
			free(data->input);
			break;
		}
		if (strcmp(data->input, "history") == 0)
		{
			for (int i = 0; i < data->contador; i++)
				printf(" %d %s\n", i + 1, data->historico[i]);
		} 
		if (validate(data) == 1)
			return (3);
		if(!validate(data) == 2)
		{
			printf("%s\n", data->input);
			printf("carapau\n");	
		}
		else
		{
			
			if (data->contador == data->capacidade)
            		{
                		data->capacidade *= 2;
				char **novo_historico = realloc(data->historico, data->capacidade * sizeof(char *));
				if (novo_historico == NULL)
				{
					perror("Erro ao realocar memória");
					break;
				}
				data->historico = novo_historico;
			}
			data->historico[data->contador++] = strdup(data->input);
			add_history(data->input);
		}

		free(data->input);
    }
    return 0;
}




	

