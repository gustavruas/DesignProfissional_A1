#include "testlib.h"

// To-do abaixo:
// Dar um jeito de usar o array para juntar funções

int main(){
    int continuar = 1;
    
    printf("=== CALCULADORA CIENTIFICA ===\n");
    
    while(continuar == 1) {
        menu();
        
        if(continuar){
            printf("\n\nDeseja fazer outra operacao? (1-Sim / 0-Nao): "); 
            scanf("%d", &continuar);
        }
    }
    printf("\nPrograma encerrado. Ate logo!\n");
    return 0;
}
