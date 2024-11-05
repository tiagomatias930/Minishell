 Implementar o Prompt e Histórico
Prompt: Comece com uma função que exibe o prompt e espera o usuário inserir um comando.
Histórico: Utilize readline e add_history para registrar os comandos inseridos. Isso permitirá que o usuário acesse comandos anteriores com as setas para cima e para baixo.
3. Parsing e Execução de Comandos
Parsing básico: Inicialmente, faça um parser que separe o comando dos argumentos, para que você possa chamar as funções apropriadas.
Execução: Use fork e execve para executar comandos básicos. Isso é importante para entender a execução em processos filhos e o gerenciamento de comandos.
4. Implementar Redirecionamentos e Pipes
Redirecionamentos: Use dup2 para redirecionar a entrada e saída. Teste com <, >, << e >>, assegurando-se de lidar com as permissões corretas ao abrir arquivos.
Pipes: Implemente a funcionalidade de pipes usando pipe(). Garanta que a saída de um comando seja a entrada do próximo.
5. Variáveis de Ambiente e Sinais
Variáveis de Ambiente: Implemente o suporte para $VARIABLE usando a função getenv para buscar valores das variáveis de ambiente.
Sinais: Implemente o tratamento de ctrl-C, ctrl-D e ctrl-\ conforme descrito. Use sigaction para lidar com sinais de forma apropriada.
6. Implementação dos Built-ins
Os built-ins podem ser implementados como funções separadas chamadas a partir do executor:
echo: Lide com a flag -n.
cd: Altere o diretório atual com chdir.
pwd, export, unset, env, exit: Siga os requisitos e implemente o básico.
7. Testes e Debugging
Testes Manuais: Execute cada funcionalidade conforme for implementada para garantir que está funcionando.
Memory Leaks: Use valgrind para verificar se há vazamento de memória.
