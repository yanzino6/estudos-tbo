# Ordenacao e busca de sufixos

Execute os comandos neste diretorio. Para compilar a consulta e o benchmark:

```sh
make
```

`./main` le `in/tale.txt`, ordena os sufixos com `qsort` e recebe uma consulta
pela entrada padrao. A busca diferencia maiusculas e minusculas e mostra ate
12 ocorrencias, com 15 caracteres de contexto antes e depois de cada uma.
Os indices e o contexto sao medidos em bytes.

```sh
printf 'Sydney\n' | ./main
```

Para executar os testes de leitura, ordenacao, consulta e erros de entrada:

```sh
make test
```

Para verificar acessos invalidos a memoria com Clang ou GCC:

```sh
make clean
make test CFLAGS='-O1 -g -std=c11 -Wall -Wextra -Wpedantic -fsanitize=address,undefined'
make clean
make
```

## Benchmark

Para comparar a ordenacao dos sufixos com MSD radix e `qsort` em todas as entradas:

```sh
make bench
```

Para escolher as entradas e o numero de repeticoes (padrao: 7):

```sh
./benchmark -r 15 in/abra.txt in/moby.txt in/tale.txt
```

Cada algoritmo recebe uma copia do mesmo vetor original, na mesma ordem.
A leitura, a criacao dos sufixos, as copias dos vetores e a verificacao ficam
fora do tempo medido. O vetor auxiliar do radix e alocado antes; as alocacoes
internas do radix fazem parte do tempo da ordenacao. Ha uma rodada de
aquecimento descartada, e a ordem de execucao dos algoritmos e alternada.
A tabela mostra a mediana dos tempos em milissegundos e `qsort/radix`:
um valor maior que 1 indica vantagem do radix (por exemplo, 2 significa
que o qsort levou o dobro do tempo).

O benchmark verifica em todas as rodadas se os algoritmos produziram a mesma
ordem de sufixos e termina com erro se houver divergencia. A quantidade de
sufixos corresponde ao texto depois do tratamento feito por `readFile`.
Os arquivos devem seguir o formato existente em `in/`: tamanho na primeira
linha, seguido do texto.
O tamanho declarado orienta a alocacao inicial; a leitura cresce o buffer se
necessario, troca quebras de linha por espacos e comprime espacos consecutivos.
Entradas sem tamanho valido ou arquivos que nao podem ser lidos retornam erro.

`abra.txt` e pequeno demais para uma conclusao confiavel de desempenho:
os tempos podem ser dominados pela resolucao do relogio e pelo ruido do sistema.
Compare os resultados usando o mesmo compilador, opcoes e maquina.
O MSD e recursivo: textos com prefixos muito longos e repetidos podem exigir
muita pilha e memoria para os vetores de contagem.
