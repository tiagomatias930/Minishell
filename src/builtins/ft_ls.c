/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 06:03:27 by timatias          #+#    #+#             */
/*   Updated: 2024/11/18 07:00:42 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void  ft_ls(t_data sct)
{
    char    *env_ = getenv(sct.arg);
    char *path = "/bin/ls"; // Caminho completo do executável
    char *args[] = {path, sct.arg, sct.data, NULL}; // Argumentos para o executável
    char *env[] = {env_}; // Ambiente, pode ser NULL se não precisar de variáveis de ambiente
    
    // Usar execve para substituir o processo atual pelo novo
    pid_t fd = fork();
    if (fd == 0)
    {
        if ((ft_strcmp(sct.arg, " ") == 0) || (ft_strcmp(sct.arg, "-l") == 0))
        {
            if (execve(path, args, env) == -1)
            {
                perror("Erro ao executar o execve");
            }
            write(STDOUT_FILENO, "\n", 1);
            rl_set_prompt("timatias:~$ ");
            rl_on_new_line();
            rl_replace_line("", 1);
            rl_redisplay();
        }
        else
        {
            if (execve(path, args, env) == -1)
                perror("Erro ao executar o execve");
            
        }
    }
    else
        waitpid(fd, &sct.status, 0);
    
}

/*
// Função para dividir a string em tokens
char **tokenize(const char *input) {
    char **tokens = malloc(100 * sizeof(char *)); // Array para armazenar tokens
    char *input_copy = strdup(input);            // Cópia da string de entrada
    char *token;
    int i = 0;

    // Separadores básicos: espaço, pipe, redirecionamentos
    char *delimiters = " \t\r\n|><";

    token = strtok(input_copy, delimiters);
    while (token) {
        tokens[i++] = strdup(token);
        token = strtok(NULL, delimiters);
    }
    tokens[i] = NULL; // Terminar o array com NULL

    free(input_copy); // Liberar memória da cópia
    return tokens;
}

int main() {
    char input[256];
    printf("Digite um comando: ");
    fgets(input, 256, stdin);

    // Tokenizar
    char **tokens = tokenize(input);

    // Mostrar os tokens
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("Token %d: %s\n", i, tokens[i]);
        free(tokens[i]); // Liberar memória de cada token
    }
    free(tokens); // Liberar o array de tokens

    return 0;
}
*/