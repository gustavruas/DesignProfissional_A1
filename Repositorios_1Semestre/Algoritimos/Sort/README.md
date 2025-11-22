COMPARACAO DE ALGORITMOS DE ORDENACAO
VISAO GERAL
Este projeto em C implementa e compara dois algoritmos de ordenacao fundamentais Bubble Sort e Insertion Sort.
O objetivo e ordenar uma string de 8 digitos (simulando um codigo como RGM) e medir o desempenho de cada algoritmo.
As metricas de desempenho sao tempo de execucao, numero de comparacoes e numero de trocas.
FUNCIONALIDADES
Implementacao de Bubble Sort Ordena a string trocando elementos adjacentes.
Implementacao de Insertion Sort Constroi a string final inserindo cada elemento em sua posicao correta.
Medicao de Desempenho Mede o Tempo de execucao em milissegundos (tempo_ms).
Medicao de Desempenho Conta o numero global de Comparacoes (count_cmp).
Medicao de Desempenho Conta o numero global de Trocas Movimentacoes (count_swap).
Validacao de Entrada Verifica se a string de entrada possui exatamente 8 digitos.
ESTRUTURA DO CODIGO
Bibliotecas Utilizadas
stdio.h Para entrada e saida padrao (como printf).
string.h Para manipulacao de strings (como strlen).
time.h Para medicao do tempo de execucao.
Funcoes Principais
bubble_sort(char rgm) Executa o Bubble Sort e imprime as metricas de desempenho.
insert_sort(char rgm) Executa o Insertion Sort e imprime as metricas de desempenho. Nota A contagem de passos (count_cmp e count_swap) e global e acumula os valores do bubble_sort.
main Define a string de entrada "46456732" e chama bubble_sort e insert_sort sequencialmente. A string ja estara ordenada quando insert_sort for chamado.
COMO COMPILAR E EXECUTAR
Pre-requisitos
Voce precisara de um compilador C (como GCC) instalado em seu sistema.
Compilacao
Salve o codigo em um arquivo por exemplo sort_comparison.c.
Compile o codigo no terminal usando o comando gcc -o sort_app sort_comparison.c.
Execucao
Execute o programa compilado usando o comando ./sort_app.
EXEMPLO DE SAIDA
A saida sera semelhante a esta os valores de tempo e contagem podem variar
Rgm ordenado bubble-sort 23445667
Tempo bubble-sort 0.005000
Quantidade de passos count 21
Quantidade de passos swap 11
Rgm ordenado insert-sort 23445667
Tempo insert-sort 0.001000
Quantidade de passos count 28
Quantidade de passos swap 11
DISCUSSAO E CONCLUSAO SOBRE O METODO
COMPUTABILIDADE
Correcão Ambos os algoritmos ordenaram corretamente a string de 8 digitos (RGM) para "23445667".
Robustez Ambos lidaram corretamente com empates ou valores repetidos (os digitos '4' e '6' no RGM). O codigo trata o RGM como uma string de caracteres (char) e realiza a ordenacao baseada nos valores ASCII (o que e correto para digitos).
Tamanhos Diferentes Embora o codigo exija N=8, os algoritmos subjacentes sao robustos para qualquer N, bastando ajustar os limites dos loops.
ESCALABILIDADE E COMPLEXIDADE
Complexidade Teorica Tanto o Bubble Sort quanto o Insertion Sort possuem uma complexidade de tempo de O(n elevado a 2) no pior e caso medio (o quadrado do numero de elementos). Isso significa que para conjuntos de dados muito grandes, o tempo de execucao aumenta drasticamente.
Observacao Pratica (N=8) Para uma entrada tao pequena (N=8), a diferenca de tempo entre os dois algoritmos e minima e irrelevante (milissegundos). A complexidade O(n elevado a 2) so se torna um problema perceptivel quando N e grande (milhares de elementos).
Comparacao com O(n log n) Ambos os metodos seriam significativamente mais lentos em grandes amostras do que algoritmos mais eficientes como Merge Sort ou Quick Sort, que possuem complexidade O(n log n).
ESTABILIDADE E USO DE MEMORIA
Estabilidade Ambos os algoritmos (Bubble Sort e Insertion Sort, como implementados) sao estaveis, o que significa que mantem a ordem relativa de elementos iguais (importante se os digitos tivessem informacoes secundarias).
Uso de Memoria Ambos os metodos sao in-place (no local). Eles exigem apenas uma variavel temporaria ('temp' ou 'e') para realizar as trocas, resultando em um uso de memoria O(1) (constante) muito eficiente.
SENSIBILIDADE AO CASO (ESTADO INICIAL)
Bubble Sort Foi executado em uma string aleatoria ("46456732"), o que geralmente se aproxima do caso medio O(n elevado a 2).
Insertion Sort Foi executado em uma string totalmente ordenada ("23445667"), o que representa o melhor caso para o Insertion Sort. Seu melhor caso tem complexidade O(n) (linear), pois ele so precisa verificar a ordenacao uma vez.
CONCLUSAO FINAL
O MELHOR METODO (BASEADO NAS OBSERVACOES)
Para a aplicacao especifica de ordenar o RGM (N=8), ambos os metodos sao aceitaveis devido ao pequeno tamanho da entrada.
Conexao Teoria x Pratica A principal licao observada na pratica e a sensibilidade do Insertion Sort ao caso. O Insertion Sort demonstrou um tempo de execucao excepcionalmente rapido no segundo teste (caso ordenado), refletindo sua complexidade teorica O(n) no melhor caso.
Apesar disso, se o objetivo fosse construir um algoritmo de ordenacao de proposito geral para grandes volumes de dados (Escalabilidade), nenhum dos O(n elevado a 2) seria o melhor metodo. Um algoritmo O(n log n) seria necessario.
Entre os dois, o Insertion Sort e geralmente o preferido para pequenos arrays ou para arrays que se espera que estejam quase ordenados, devido ao seu melhor desempenho no melhor caso (O(n)).
