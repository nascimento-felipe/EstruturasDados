# Projeto Estruturas de Dados - Prof. Douglas Maioli

## Intuito do repositório

Esse projeto foi criado para que eu possa acompanhar as aulas do [Prof. Douglas Maioli](https://www.youtube.com/c/ProfessorDouglasMaioli) e, ao mesmo tempo, disponibilizar o código escrito por mim para qualquer pessoa que tenha interesse no curso também. Sinta-se livre para estudar os códigos.

Os códigos são todos feitos em C++. Também estou usando o projeto para aprender essa linguagem, então pode ser que tenha escrito códigos ruins, com funções que talvez não foram criadas para serem usadas da forma que eu usei. 
Caso perceba algo do tipo, me contate ou abra uma issue pra explicar o problema e como resolver.

Playlist de Estruturas de Dados: [Estrutura de Dados com C++](https://www.youtube.com/playlist?list=PLrOyM49ctTx_AMgNGQaic10qQJpTpXfn_)

## Pastas

Todos os códigos estão na pasta [Estruturas](./Estruturas/) e cada exemplo de estrutura de dados está separada em sua pasta específica. Há, em toda pasta, um binário compilado em Linux para teste, caso você use Linux também. Caso use Windows, é só rodar o seguinte comando:

```batch
g++ main.cpp nome_estrutura.cpp -o nome_executavel.exe 
```

Todas as pastas contam com um arquivo main.cpp que mantém a lógica do menu e consome a estrutura para mostrar seus dados no console. O segundo arquivo pra passar é o arquivo .cpp que tem o mesmo nome da estrutura. Exemplo:
```batch
g++ main.cpp pilha.cpp -o pilhaExemplo.exe
```

Clique nos hyperlinks para ir direto para a pasta com o assunto:

 - [Pilhas](./Estruturas/pilha/);
 - [Filas](./Estruturas/fila/);
 - [Pilhas Dinâmicas](./Estruturas/pilhaDinamica/);
 - [Filas Dinâmicas](./Estruturas/filaDinamica/);
 - [Tabela Hash (sem tratamento de colisão)](./Estruturas/tabelaHashSemColisao/);
 - [Tabela Hash com tratamento de colisão](./Estruturas/tabelaHashComColisao/);
 - [Árvore Binária de Busca / Binary Search Tree (ABB ou BST)](./Estruturas/ArvoreBinariaBusca/);
 - [Árvore AVL](./Estruturas/ArvAvl/);