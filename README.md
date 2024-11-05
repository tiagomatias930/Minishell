# MInishell-42

    ### Introdução
    Introdução
Minishell é um grande projeto que requer uma boa comunicação entre ambos os membros do grupo e uma boa organização sobre como dividir o trabalho que precisa ser feito para não fazer a mesma coisa duas vezes ou não como o outro espera que funcione.

Comece definindo as principais etapas do projeto e converse sobre como vocês querem trabalhar juntos e tudo isso antes de começar.

Se você quiser fazer os bônus, pense em como você irá implementá-los desde o começo, será muito difícil implementá-los depois sem refazer tudo do zero.

Lista de verificação / documentação
Aqui vou mostrar a maneira como dividimos nosso trabalho. Não estou dizendo que essa é A maneira de fazer, mas dá uma ideia.

Dividimos o trabalho em duas partes principais desde o início, que depois foram divididas novamente em partes menores:

Análise sintática/lexical

Execução

Reserve um tempo para ler/assistir coisas sobre análise lexical e sintática. Esses assuntos podem parecer um pouco chatos, mas são realmente interessantes e ajudarão você a saber para que servem e em que momento você precisará usá-los.

Alguns grupos não fizeram nenhuma análise lexical, dê uma olhada no que é e decida se você quer usar ou não.


Abaixo esta dividido projecto em dois, para que possamos terminar há tempo o projeto.
 **Minishell**. Vamos focar em funções específicas para cada um, desde a estrutura básica até funcionalidades avançadas.

### Parte 1: Responsabilidades do Colega de Equipe
Esta parte ficará com seu colega e cobrirá principalmente a base do shell, execução de comandos, e implementação de *built-ins*.

#### 1. **Estrutura Inicial e Configuração do Projeto**
   - **Setup:** Criar e organizar os arquivos de cabeçalho (por exemplo, `minishell.h`) e outros arquivos principais. Definir estruturas de dados, como as estruturas para comandos e variáveis de ambiente.
   - **Variáveis Globais:** Definir um ambiente global, caso necessário, para armazenar o estado do shell e as variáveis de ambiente.

#### 2. **Execução de Comandos**
   - **Função Execução (`exec_command`)**: Implementar uma função para executar comandos usando `fork` e `execve`.
     - **Processos e *Fork*:** Crie um processo filho com `fork` e execute o comando com `execve`.
     - **Tratamento de Erros:** Verifique se o comando foi encontrado, retornando uma mensagem de erro caso o caminho seja inválido.

#### 3. **Built-in Commands**
   - **`echo`**: Implementar o comando `echo`, com suporte para a flag `-n` para remover a nova linha final.
   - **`cd`**: Implementar o comando `cd` para alterar o diretório atual. Use a função `chdir` e atualize a variável de ambiente `PWD`.
   - **`pwd`**: Implementar o comando `pwd` para exibir o diretório de trabalho atual.
   - **`export` e `unset`**: Implementar as funções para manipular variáveis de ambiente.
   - **`env`**: Implementar o comando `env` para exibir todas as variáveis de ambiente.

#### 4. **Implementação Básica de Sinais**
   - **Tratamento de Sinais:** Implementar a captura de `CTRL+C`, `CTRL+\`, e `CTRL+D` usando a função `signal`. Estes sinais devem interromper ou sair do shell conforme apropriado.

#### 5. **Testes e Integração**
   - Testar a execução de comandos externos e verificar se cada *built-in* responde corretamente.
   - Verificar que o shell responde aos sinais corretamente e retorna para o prompt sem falhas.

---

### Parte 2: Suas Responsabilidades
Esta parte cobrirá funcionalidades avançadas, como *pipes*, redirecionamento e o sistema de parsing.

#### 1. **Parsing e Tokenização**
   - **Tokenização:** Crie uma função para dividir a linha de entrada em tokens (comandos, argumentos e operadores como `|`, `>`, `<`). Cada token será armazenado em uma estrutura de dados que representa um comando.
   - **Parsing de Variáveis (`$VAR`):** Implemente a expansão de variáveis de ambiente. Ex.: `$USER` deve ser substituído pelo valor da variável de ambiente `USER`.

#### 2. **Redirecionamento**
   - **Entrada e Saída (`<`, `>`, `>>`):** Implemente o redirecionamento de entrada e saída para permitir que o usuário envie a saída de um comando para um arquivo ou leia a entrada de um arquivo.
   - **Funções de Manipulação de Arquivos**: Use `open`, `close`, `dup2`, e `unlink` para gerenciar os descritores de arquivos.

#### 3. **Pipes (`|`)**
   - **Implementação de Pipes:** Use `pipe()` para criar canais entre processos. Isso permitirá o encadeamento de comandos, enviando a saída de um comando como entrada de outro.
   - **Execução Encadeada:** Ajuste a função `exec_command` para manipular comandos com pipes.

#### 4. **Função `exit` e Limpeza de Memória**
   - **Exit Graceful:** Implementar o comando `exit`, garantindo que o shell limpe todas as alocações de memória e feche descritores de arquivos.
   - **Liberação de Memória:** Garanta que toda a memória alocada, como o ambiente e a lista de tokens, seja liberada ao sair do shell.

#### 5. **Testes e Revisão Final**
   - Testar os *pipes*, redirecionamentos e o parser para garantir que todas as combinações de comandos funcionem corretamente.
   - Revisar e realizar testes completos para cada funcionalidade, simulando usos reais e verificando a integração com os *built-ins* do colega.

---

### **Sites para aprendizado sobre as bases**
    - Para entender a biblioteca readline/readline.h : https://man7.org/linux/man-pages/man3/readline.3.html
    - Para pegar o caminho absoluto de um diretório: https://man7.org/linux/man-pages/man3/getcwd.3.html
    - Guia completo das funções mais usadas: https://42-cursus.gitbook.io/guide/rank-03/minishell/functions
    - Alterar o caminho do diretório : https://man7.org/linux/man-pages/man2/chdir.2.html
    - Recomendável : https://42-cursus.gitbook.io/guide/rank-03/minishell/functions
    - Entrar em um directorio : https://man7.org/linux/man-pages/man3/readdir.3.html
    - Introdução basica: https://harm-smits.github.io/42docs/projects/minishell
    -   Introdução sobre criação de processos, pipes, intercepção de sinais em , manipulação de um Fd e eerno e gerenciamento de erros em C: https://www.codequoi.com/en/why-i-no-longer-write-articles-about-42-school-projects/#minishell
