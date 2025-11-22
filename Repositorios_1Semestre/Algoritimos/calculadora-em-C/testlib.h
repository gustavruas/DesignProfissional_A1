#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265
#define MAX_HISTORICO 100

int *array;
int tamanho;

// Estrutura para o histórico
typedef struct {
    char operacao[50];
    char entrada[200];
    char resultado[100];
} RegistroHistorico;

RegistroHistorico historico[MAX_HISTORICO];
int total_historico = 0;

void historico_persistente(){
  FILE *fptr;

  fptr = fopen("historico.txt", "a"); // "a" determinado o modo, esse sendo o append

  fprintf(fptr, "Operacao: %s\n",historico[total_historico].operacao);
  fprintf(fptr, "Entrada: %s\n", historico[total_historico].entrada);
  fprintf(fptr, "Resultado: %s\n",historico[total_historico].resultado);
  fprintf(fptr, "------------------------------\n");

  fclose(fptr);
}

// Função para adicionar ao histórico
void adicionar_historico(const char* operacao, const char* entrada, double resultado) {
    if(total_historico < MAX_HISTORICO) {
        strcpy(historico[total_historico].operacao, operacao);
        strcpy(historico[total_historico].entrada, entrada);
        snprintf(historico[total_historico].resultado, 100, "%.4lf", resultado);
        historico_persistente();
        total_historico++;
    } else {
        // Se o histórico estiver cheio, desloca tudo uma posição e adiciona no final
        for(int i = 0; i < MAX_HISTORICO - 1; i++) {
            historico[i] = historico[i + 1];
        }
        strcpy(historico[MAX_HISTORICO - 1].operacao, operacao);
        strcpy(historico[MAX_HISTORICO - 1].entrada, entrada);
        snprintf(historico[MAX_HISTORICO - 1].resultado, 100, "%.4lf", resultado);
        historico_persistente();
    }
}

// Função para mostrar o histórico
void mostrar_historico() { // Mostrar o arquivo inves do salvo em memoria

    FILE *fp;
    fp = fopen("historico.txt", "r");
    char conteudo[100];

    if(total_historico == 0 && fp == NULL) {
        printf("\n=== HISTORICO VAZIO ===\n");
        printf("Nenhuma operacao foi realizada ainda.\n");
        return;
    }
    
    printf("\n========== HISTORICO DE CALCULOS ==========\n");
    while(fgets(conteudo, 100, fp)){
      printf("%s", conteudo);
    } 
    printf("==========================================\n");
}

// Função para limpar o histórico
void limpar_historico() {
    total_historico = 0;
    FILE *fp;
    fp = fopen("historico.txt", "w");
    fprintf(fp, " ");
    printf("\nHistorico limpo com sucesso!\n");
}

int ab32(){
    printf("Tamanho do array: ");
    scanf("%d", &tamanho);
    if(tamanho <= 0){
        printf("Selecione um tamanho maior que 0\n");
        return 1;
    }
    
    array = (int *) malloc(tamanho * sizeof(int));
    if(array == NULL){
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    
    printf("Digite %d elementos:\n", tamanho);
    return 0;
}

void ler_array(){
    for(int i = 0; i < tamanho; i++){
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

void soma(){
    double res = 0;
    if(ab32() != 0) {   
        return;
    }
    ler_array();
    
    char entrada[200] = "";
    char temp[20];
    for(int i = 0; i < tamanho; i++){
        res += array[i];
        snprintf(temp, 20, "%d", array[i]);
        strcat(entrada, temp);
        if(i < tamanho - 1) strcat(entrada, " + ");
    }
    
    printf("Soma = %lf\n", res);
    adicionar_historico("Soma", entrada, res);
    free(array);
}

void subtrair(){
    double res = 0;
    if(ab32() != 0) {      
       return;
    }
    ler_array();
    
    char entrada[200] = "";
    char temp[20];
    for(int i = 0; i < tamanho; i++){
       res -= array[i];
       snprintf(temp, 20, "%d", array[i]);
       strcat(entrada, temp);
       if(i < tamanho - 1) strcat(entrada, " - ");
    }
    
    printf("Subtracao = %lf\n", res);
    adicionar_historico("Subtracao", entrada, res);
    free(array);
}

void multiplicar(){
    double res = 1;
    if(ab32() != 0) {       
        return;
    }
    ler_array();
    
    char entrada[200] = "";
    char temp[20];
    for(int i = 0; i < tamanho; i++){
        res *= array[i];
        snprintf(temp, 20, "%d", array[i]);
        strcat(entrada, temp);
        if(i < tamanho - 1) strcat(entrada, " * ");
    }
    
    printf("Multiplicacao = %lf\n", res);
    adicionar_historico("Multiplicacao", entrada, res);
    free(array);
}

void dividir(){
    if(ab32() != 0) {       
        return;
    }
    ler_array();
    double res = (double)array[0];
    
    char entrada[200] = "";
    char temp[20];
    snprintf(temp, 20, "%d", array[0]);
    strcat(entrada, temp);
    
    for(int i = 0; i < tamanho-1; i++){
        if(array[i+1] == 0){
            printf("Nao divida por zero.\n");
            free(array);
            return;
        }
        res /= array[i+1];
        snprintf(temp, 20, " / %d", array[i+1]);
        strcat(entrada, temp);
    }
    
    printf("Divisao = %lf\n", res);
    adicionar_historico("Divisao", entrada, res);
    free(array);
}

void porcentagem(){
    double a;
    printf("Digite o numero base: ");
    scanf("%lf", &a);
    printf("Digite as porcentagens:\n");
    
    double res = 1;
    if(ab32() != 0) {       
        return;
    }
    ler_array();
    
    char entrada[200];
    char temp[50];
    snprintf(entrada, 200, "%.2lf * ", a);
    
    for(int i = 0; i < tamanho; i++){
        res *= (array[i]/100.0);
        snprintf(temp, 50, "%d%%", array[i]);
        strcat(entrada, temp);
        if(i < tamanho - 1) strcat(entrada, " * ");
    }
    
    double resFinal = a * res;
    printf("Resultado: %lf\n", resFinal);
    adicionar_historico("Porcentagem", entrada, resFinal);
    free(array);
}

void potencia(){
    double a;
    printf("Digite o numero base: ");
    scanf("%lf", &a);
    printf("Digite os expoentes:\n");
    
    double res = 1;
    if(ab32() != 0) {       
        return;
    }
    ler_array();
    
    char entrada[200];
    char temp[50];
    snprintf(entrada, 200, "%.2lf ^ (", a);
    
    for(int i = 0; i < tamanho; i++){
        res *= array[i];
        snprintf(temp, 50, "%d", array[i]);
        strcat(entrada, temp);
        if(i < tamanho - 1) strcat(entrada, " * ");
    }
    strcat(entrada, ")");
    
    double resFinal = pow(a, res);
    printf("Resultado: %lf\n", resFinal);
    adicionar_historico("Potencia", entrada, resFinal);
    free(array);
}

void raiz2(){
    double a;
    printf("Base: ");
    scanf("%lf", &a);
    
    if(a < 0){
        printf("Nao trataremos numeros complexos\n");
        return;
    }
    
    double res = pow(a, 0.5);
    char entrada[100];
    snprintf(entrada, 100, "√%.2lf", a);
    printf("Resultado: %lf\n", res);
    adicionar_historico("Raiz Quadrada", entrada, res);
}

void raiz3(){
    double a;
    printf("Base: ");
    scanf("%lf", &a);
    
    if(a < 0){
        printf("Nao trataremos numeros complexos\n");
        return;
    }
    
    double res = pow(a, 1.0/3.0);
    char entrada[100];
    snprintf(entrada, 100, "∛%.2lf", a);
    printf("Resultado: %lf\n", res);
    adicionar_historico("Raiz Cubica", entrada, res);
}

void potenciareversa(){
    double a;
    printf("Digite o numero base: ");
    scanf("%lf", &a);
    printf("Digite os expoentes:\n");
    
    double res = 1;
    if(ab32() != 0) {       
        return;
    }
    ler_array();
    
    char entrada[200];
    snprintf(entrada, 200, "%.2lf ^ -(%d", a, array[0]);
    
    for(int i = 0; i < tamanho; i++){
        res *= array[i];
        if(i > 0) {
            char temp[20];
            snprintf(temp, 20, " * %d", array[i]);
            strcat(entrada, temp);
        }
    }
    strcat(entrada, ")");
    
    double resFinal = pow(a, -res);
    printf("Resultado: %lf\n", resFinal);
    adicionar_historico("Pot. Reversa", entrada, resFinal);
    free(array);
}

void fatorial(){
    int a;
    printf("Selecione um numero: ");
    scanf("%d", &a);
    
    if(a < 0){
        printf("Fatorial nao eh feito pra numeros negativos\n");
        return;
    }
    
    double res = tgamma(a + 1);
    char entrada[50];
    snprintf(entrada, 50, "%d!", a);
    printf("Fatorial de %d eh: %lf\n", a, res);
    adicionar_historico("Fatorial", entrada, res);
}

void s3n(){
    double angulo, res, c;
    printf("Selecione o angulo: ");
    scanf("%lf", &angulo);
    res = angulo * PI / 180.0;
    c = sin(res);
    
    char entrada[50];
    snprintf(entrada, 50, "sen(%.2lf°)", angulo);
    printf("Seno: %lf\n", c);
    adicionar_historico("Seno", entrada, c);
}

void c0s(){
    double angulo, res, c;
    printf("Selecione o angulo: ");
    scanf("%lf", &angulo);
    res = angulo * PI / 180.0;
    c = cos(res);
    
    char entrada[50];
    snprintf(entrada, 50, "cos(%.2lf°)", angulo);
    printf("Cosseno: %lf\n", c);
    adicionar_historico("Cosseno", entrada, c);
}

void t4n(){
    double angulo, res, c;
    printf("Selecione o angulo: ");
    scanf("%lf", &angulo);
    res = angulo * PI / 180.0;
    c = tan(res);
    
    char entrada[50];
    snprintf(entrada, 50, "tan(%.2lf°)", angulo);
    printf("Tangente: %lf\n", c);
    adicionar_historico("Tangente", entrada, c);
}

void secante(){
    double angulo, res, c;
    printf("Selecione o angulo: ");
    scanf("%lf", &angulo);
    res = angulo * PI / 180.0;
    c = 1 / sin(res);
    
    char entrada[50];
    snprintf(entrada, 50, "sec(%.2lf°)", angulo);
    printf("Secante: %lf\n", c);
    adicionar_historico("Secante", entrada, c);
}

void cossecante(){
    double angulo, res, c;
    printf("Selecione o angulo: ");
    scanf("%lf", &angulo);
    res = angulo * PI / 180.0;
    c = 1 / cos(res);
    
    char entrada[50];
    snprintf(entrada, 50, "csc(%.2lf°)", angulo);
    printf("Cossecante: %lf\n", c);
    adicionar_historico("Cossecante", entrada, c);
}

void contangente(){
    double angulo, res, c;
    printf("Selecione o angulo: ");
    scanf("%lf", &angulo);
    res = angulo * PI / 180.0;
    c = 1 / tan(res);
    
    char entrada[50];
    snprintf(entrada, 50, "cot(%.2lf°)", angulo);
    printf("Cotangente: %lf\n", c);
    adicionar_historico("Cotangente", entrada, c);
}

void logaritmo(){
    double base, numero, res;
    printf("Selecione a base: ");
    scanf("%lf", &base);
    printf("Selecione o numero: ");
    scanf("%lf", &numero);
    
    if(base <= 0 || base == 1 || numero <= 0){
        printf("Input invalido\n");
        return;
    }
    
    res = log(numero) / log(base);
    char entrada[100];
    snprintf(entrada, 100, "log_%.2lf(%.2lf)", base, numero);
    printf("Logaritmo: %lf\n", res);
    adicionar_historico("Logaritmo", entrada, res);
}

void log_natural(){
    double numero, res;
    printf("Selecione o numero: ");
    scanf("%lf", &numero);
    
    if(numero <= 0){
        printf("Selecione um input valido\n");
        return;
    }
    
    res = log(numero);
    char entrada[100];
    snprintf(entrada, 100, "ln(%.2lf)", numero);
    printf("Log natural: %lf\n", res);
    adicionar_historico("Log Natural", entrada, res);
}

void modulo(){
    int a;
    printf("Selecione um numero: ");
    scanf("%d", &a);
    
    int res = abs(a);
    char entrada[50];
    snprintf(entrada, 50, "|%d|", a);
    printf("O valor absoluto de %d eh %d\n", a, res);
    adicionar_historico("Modulo", entrada, (double)res);
}

void dezElevadoaX(){
    printf("10 elevado a qual expoente:\n");
    double res = 1;
    if(ab32() != 0) {       
        return;
    }
    ler_array();
    
    char entrada[200] = "10 ^ (";
    char temp[20];
    for(int i = 0; i < tamanho; i++){
        res *= array[i];
        snprintf(temp, 20, "%d", array[i]);
        strcat(entrada, temp);
        if(i < tamanho - 1) strcat(entrada, " * ");
    }
    strcat(entrada, ")");
    
    double resFinal = pow(10, res);
    printf("Resultado: %lf\n", resFinal);
    adicionar_historico("10^X", entrada, resFinal);
    free(array);
}

void vezesEuler(){
    printf("Digite os multiplicadores:\n");
    double res = 1;
    if(ab32() != 0) {       
        return;
    }
    ler_array();
    
    char entrada[200] = "e * (";
    char temp[20];
    for(int i = 0; i < tamanho; i++){
        res *= array[i];
        snprintf(temp, 20, "%d", array[i]);
        strcat(entrada, temp);
        if(i < tamanho - 1) strcat(entrada, " * ");
    }
    strcat(entrada, ")");
    
    double resFinal = exp(1) * res;
    printf("Resultado: %lf\n", resFinal);
    adicionar_historico("X * Euler", entrada, resFinal);
    free(array);
}

void EulerElevado(){
    printf("Digite os expoentes:\n");
    double res = 1;
    if(ab32() != 0) {       
        return;
    }
    ler_array();
    
    char entrada[200] = "e ^ (";
    char temp[20];
    for(int i = 0; i < tamanho; i++){
        res *= array[i];
        snprintf(temp, 20, "%d", array[i]);
        strcat(entrada, temp);
        if(i < tamanho - 1) strcat(entrada, " * ");
    }
    strcat(entrada, ")");
    
    double resFinal = exp(res);
    printf("Resultado: %lf\n", resFinal);
    adicionar_historico("Euler^X", entrada, resFinal);
    free(array);
}

void media(){
    double res = 0;
    if(ab32() != 0){
        return;
    }
    ler_array();
    
    char entrada[200] = "(";
    char temp[20];
    for(int i = 0; i < tamanho; i++){
        res += array[i];
        snprintf(temp, 20, "%d", array[i]);
        strcat(entrada, temp);
        if(i < tamanho - 1) strcat(entrada, " + ");
    }
    char divisor[20];
    snprintf(divisor, 20, ") / %d", tamanho);
    strcat(entrada, divisor);
    
    double d = res / tamanho;
    printf("Media: %lf\n", d);
    adicionar_historico("Media", entrada, d);
    free(array);
}

void maximo(){
    if(ab32() != 0){
        return;
    }
    ler_array();
    
    int max_val = array[0];
    char entrada[200] = "max(";
    char temp[20];
    
    for(int i = 0; i < tamanho; i++){
        if(array[i] > max_val){
            max_val = array[i];
        }
        snprintf(temp, 20, "%d", array[i]);
        strcat(entrada, temp);
        if(i < tamanho - 1) strcat(entrada, ", ");
    }
    strcat(entrada, ")");
    
    printf("O valor maximo eh: %d\n", max_val);
    adicionar_historico("Maximo", entrada, (double)max_val);
    free(array);
}

void determinante2x2(){
    double matriz[2][2];
    
    printf("\n=== DETERMINANTE DE MATRIZ 2x2 ===\n");
    printf("Digite os elementos da matriz:\n");
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%lf", &matriz[i][j]);
        }
    }
    
    // Cálculo do determinante: det = a*d - b*c
    double det = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
    
    // Montar entrada para histórico
    char entrada[200];
    snprintf(entrada, 200, "|%.2lf %.2lf; %.2lf %.2lf|", 
             matriz[0][0], matriz[0][1], matriz[1][0], matriz[1][1]);
    
    printf("\nMatriz:\n");
    printf("| %.2lf  %.2lf |\n", matriz[0][0], matriz[0][1]);
    printf("| %.2lf  %.2lf |\n", matriz[1][0], matriz[1][1]);
    printf("\nDeterminante: %lf\n", det);
    
    adicionar_historico("Det 2x2", entrada, det);
}

void determinante3x3(){
    double matriz[3][3];
    
    printf("\n=== DETERMINANTE DE MATRIZ 3x3 ===\n");
    printf("Digite os elementos da matriz:\n");
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%lf", &matriz[i][j]);
        }
    }
    
    // Cálculo do determinante pela regra de Sarrus
    double det = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1])
               - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0])
               + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
    
    // Montar entrada para histórico (simplificada)
    char entrada[200];
    snprintf(entrada, 200, "|%.1lf %.1lf %.1lf; %.1lf %.1lf %.1lf; %.1lf %.1lf %.1lf|", 
             matriz[0][0], matriz[0][1], matriz[0][2],
             matriz[1][0], matriz[1][1], matriz[1][2],
             matriz[2][0], matriz[2][1], matriz[2][2]);
    
    printf("\nMatriz:\n");
    printf("| %.2lf  %.2lf  %.2lf |\n", matriz[0][0], matriz[0][1], matriz[0][2]);
    printf("| %.2lf  %.2lf  %.2lf |\n", matriz[1][0], matriz[1][1], matriz[1][2]);
    printf("| %.2lf  %.2lf  %.2lf |\n", matriz[2][0], matriz[2][1], matriz[2][2]);
    printf("\nDeterminante: %lf\n", det);
    
    adicionar_historico("Det 3x3", entrada, det);
}

void menu(){
    int escolha; 
    printf("\n+-------------------------------------------------------------+\n");
    printf("|  1. Soma           |  2. Subtrair      |  3. Multiplicar    |\n");
    printf("|  4. Dividir        |  5. Porcentagem   |  6. Potencia       |\n");
    printf("|  7. Raiz quadrada  |  8. Raiz cubica   |  9. Pot. reversa   |\n");
    printf("| 10. Fatorial       | 11. Seno          | 12. Cosseno        |\n");
    printf("| 13. Tangente       | 14. Secante       | 15. Cossecante     |\n");
    printf("| 16. Cotangente     | 17. Log base N    | 18. Log natural    |\n");
    printf("| 19. Modulo         | 20. 10^X          | 21. X * Euler      |\n");
    printf("| 22. Euler^X        | 23. Media         | 24. Max            |\n");
    printf("| 25. Det 2x2        | 26. Det 3x3                            |\n");
    printf("| 27. Ver Historico  | 28. Limpar Historico                   |\n");
    printf("|                    0. Sair                                  |\n");
    printf("+-------------------------------------------------------------+\n");
    printf("Escolha uma opcao: ");        
    scanf("%d", &escolha);

    switch(escolha){
        case 1: soma(); break;
        case 2: subtrair(); break;
        case 3: multiplicar(); break;
        case 4: dividir(); break;
        case 5: porcentagem(); break;
        case 6: potencia(); break;
        case 7: raiz2(); break;
        case 8: raiz3(); break;
        case 9: potenciareversa(); break;
        case 10: fatorial(); break;
        case 11: s3n(); break;
        case 12: c0s(); break;
        case 13: t4n(); break;
        case 14: secante(); break;
        case 15: cossecante(); break;
        case 16: contangente(); break;
        case 17: logaritmo(); break;
        case 18: log_natural(); break;
        case 19: modulo(); break;
        case 20: dezElevadoaX(); break;
        case 21: vezesEuler(); break;
        case 22: EulerElevado(); break;
        case 23: media(); break;
        case 24: maximo(); break;
        case 25: determinante2x2(); break;
        case 26: determinante3x3(); break;
        case 27: mostrar_historico(); break;
        case 28: limpar_historico(); break;
        case 0: 
            printf("Encerrando programa...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}
