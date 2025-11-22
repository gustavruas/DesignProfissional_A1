#include <stdio.h>

typedef struct Aluno{
  int Matricula;
  char Nome[50]; // Definindo como string até 50 chars,
  float nota1;
  float nota2;
};

int media(){
  struct Aluno a1;

  printf("Digite seu nome:");
  fgets(a1.Nome, sizeof(a1.Nome), stdin); // Fgets é o scanf, mas não termina de mostrar quando tem um espaço; sintaxe: fgets(variavel, até qual caractere, de onde deve ser lido)
  a1.Nome[strcspn(a1.Nome, "\n")] = '\0';  // Isso remove a nova linha
  printf("Digite sua matricula:");
  scanf("%d", &a1.Matricula);
  printf("Digite sua nota1:");
  scanf("%f", &a1.nota1);
  printf("Digite sua nota2:");
  scanf("%f", &a1.nota2);

  double res = (a1.nota1+a1.nota2)/2;

  if(a1.nota1 > 10 || a1.nota1 < 0|| a1.nota2 < 0|| a1.nota2 > 10){
    printf("Mentiroso...");
    return 1;
  }
  printf("O aluno %s da matricula %d que obteve notas %lf e %lf foi:\n", a1.Nome, a1.Matricula, a1.nota1, a1.nota2);
  if(res >= 6){
    printf("Aprovado!");
  }
  else {
    printf("Reprovado!");
  }
  return 0;
}

int main(){
  media();  
  return 0;
}
