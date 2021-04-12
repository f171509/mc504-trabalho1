#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

//como passaremos 2 argumentos para a thread, criaremos uma struct com eles
struct arg_struct{
  char linha[9];
  int teste;
};

void *cacarPalavraNaLinha(void *args){
  //carregando a struct para a função
  struct arg_struct *argumentos = args;
  char palavra[5];
  for(int i = 0; i<5; i++){
    strncpy(palavra,argumentos->linha+i,4);


    if(strcmp(palavra,"foco")==0){
      if(argumentos->teste == 0){
        printf("achei a palavra foco na horizontal\n");
      }
      else{
        printf("achei a palavra foco na vertical\n");
      }
    }

    if(strcmp(palavra,"pato")==0){
      if(argumentos->teste == 0){
        printf("achei a palavra pato na horizontal\n");
      }
      else{
        printf("achei a palavra pato na vertical\n");
      }
    }

    if(strcmp(palavra,"cubo")==0){
      if(argumentos->teste == 0){
        printf("achei a palavra cubo na horizontal\n");
      }
      else{
        printf("achei a palavra cubo na vertica\nl");
      }
    }

    if(strcmp(palavra,"casa")==0){
      if(argumentos->teste == 0){
        printf("achei a palavra casa na horizontal\n");
      }
      else{
        printf("achei a palavra casa na vertical\n");
      }
    }

    if(strcmp(palavra,"sapo")==0){
      if(argumentos->teste == 0){
        printf("achei a palavra sapo na horizontal\n");
      }
      else{
        printf("achei a palavra sapo na vertical\n");
      }
    }

    if(strcmp(palavra,"caro")==0){
      if(argumentos->teste == 0){
        printf("achei a palavra caro na horizontal\n");
      }
      else{
        printf("achei a palavra caro na vertical\n");
      }
    }

    if(strcmp(palavra,"cabo")==0){
      if(argumentos->teste == 0){
        printf("achei a palavra cabo na horizontal\n");
      }
      else{
        printf("achei a palavra cabo na vertical\n");
      }
    }

    if(strcmp(palavra,"caso") == 0){
      if(argumentos->teste == 0){
        printf("achei a palavra caso na horizontal\n");
      }
      else{
        printf("achei a palavra caso na vertical\n");
      }
    }

  }

}


int main(){
  //faremos um caça palavras simples, onde a palavra pode estar na vertical ou na horizontal

  //primeiramente geraremos um caça palavras 8x8 contendo as seguintes
  //8 palavras de 4 letras: *foco, *pato, *cubo, *casa, *sapo, caro*, cabo, caso
  char chart[8][8] =          {{'c','h','g','f','o','c','o','l'},
                              {'j','d','a','o','h','a','s','p'},
                              {'p','a','t','o','l','s','a','m'},
                              {'j','f','z','v','d','a','p','k'},
                              {'l','c','a','r','o','d','o','j'},
                              {'c','a','c','u','b','o','k','f'},
                              {'e','b','j','o','a','g','k','h'},
                              {'b','o','c','a','s','o','z','v'}};


  //utilizaremos 2 threads para fazer a busca das palavras. a thread 1 testara
  //as palavras na horizontal e a thread 2 testara as palavras na vertical
  pthread_t thread1, thread2;

  //criando as 2 structs para passar de argumento nas threads
  struct arg_struct *arg1 = (struct arg_struct*)malloc(sizeof(struct arg_struct));
  struct arg_struct *arg2 = (struct arg_struct*)malloc(sizeof(struct arg_struct));


  //passaremos a linha inteira (na vertical ou horizontal) para a função de caça
  //palavras, e la a função vera se temos uma palavra contida nela
  for(int i = 0; i<8; i++){
    //criando as 2 structs para passar de argumento nas threads

    //copiando a linha inteira para a string na struct
    arg1->linha[0] = chart[i][0];
    arg1->linha[1] = chart[i][1];
    arg1->linha[2] = chart[i][2];
    arg1->linha[3] = chart[i][3];
    arg1->linha[4] = chart[i][4];
    arg1->linha[5] = chart[i][5];
    arg1->linha[6] = chart[i][6];
    arg1->linha[7] = chart[i][7];
    arg1->linha[8] = '\n';

    arg2->linha[0] = chart[0][i];
    arg2->linha[1] = chart[1][i];
    arg2->linha[2] = chart[2][i];
    arg2->linha[3] = chart[3][i];
    arg2->linha[4] = chart[4][i];
    arg2->linha[5] = chart[5][i];
    arg2->linha[6] = chart[6][i];
    arg2->linha[7] = chart[7][i];
    arg2->linha[8] = '\n';
    //avisar que o arg1 é uma linha na horizontal e arg2 é uma linha na vertical
    arg1->teste = 0;
    arg2->teste = 1;

    //criação das threads para procurar as palavras
    pthread_create(&thread1, NULL, cacarPalavraNaLinha, (void*)arg1);
    pthread_create(&thread2, NULL, cacarPalavraNaLinha, (void*)arg2);
    pthread_join(thread1,NULL);
    pthread_join(thread2, NULL);


  }
  free(arg1);
  free(arg2);
  return 0;
}
