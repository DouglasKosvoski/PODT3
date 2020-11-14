#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void generate_vetor(int tamanho, char metodo[], int *vetor) {
  if(strcmp("Aleatorio", metodo) == 0) {
    srand((unsigned)time(NULL));
    for (size_t i = 0; i < tamanho; i++)
      vetor[i] = rand() % 10;
  }

  if(strcmp("Crescente", metodo) == 0) {
    for (size_t i = 0; i < tamanho; i++)
      vetor[i] = i;
  }

  if(strcmp("Decrescente", metodo) == 0) {
    int aux = 0;
    for (size_t i = tamanho-1; i > 0; i--)
      vetor[aux++] = i;
  }
}

void imprime_vetor(int vetor[], int tamanho){
  for(size_t i = 0; i<tamanho; i++){
    printf("%2d ", vetor[i]);
  } printf("\n");
}

int busca_max(int vetor[], int tamanho) {
  int max = 0;
  for (size_t i = 0; i < tamanho; i++) {
    if (max < vetor[i]) {
      max = vetor[i];
    }
  }
  return max;
}

void counting_sort(int vetor[], int d, int tamanho) {
  int aux[tamanho];
  int contagem[10] = {0,0,0,0,0,0,0,0,0,0};
  int posicao[10] = {0,0,0,0,0,0,0,0,0,0};
  int digito = 0;

  // copia vetor para aux
  for (size_t i = 0; i < tamanho; i++) {
    aux[i] = vetor[i];
  }

  // conta as ocorrencias dos digitos
  for (size_t i = 0; i < tamanho; i++) {
    digito = (vetor[i] / d) % 10;
    contagem[digito]++;
  }

  // controla a posicao onde o valor vai ser colocado
  for (size_t i = 1; i < 10; i++) {
    posicao[i] = contagem[i-1] + posicao[i-1];
  }

  // constroi o vetor de saida
  for (size_t i = 0; i < tamanho; i++) {
    digito = (vetor[i] / d) % 10;
    aux[posicao[digito]] = vetor[i];
    posicao[digito]++;
  }

  // passa os valores de aux para o vetor original
  for (size_t i = 0; i < tamanho; i++) {
    vetor[i] = aux[i];
  }
}

void radix_sort(int vetor[], int tamanho) {
  int max = busca_max(vetor, tamanho);
  for (size_t i = 1; max/i > 0; i*=10) {
    counting_sort(vetor, i, tamanho);
  }
}

int main() {
  clock_t startTime, endTime;
  double deltaTime;

  // Aleatorio, Crescente or Decrescente
  char metodo[] = "Decrescente";
  int tamanho = 10;
  int vetor[tamanho];

  generate_vetor(tamanho, metodo, &vetor[0]);
  startTime = clock();
  imprime_vetor(vetor, tamanho);
	radix_sort(vetor, tamanho);
  imprime_vetor(vetor, tamanho);
  endTime = clock();

  deltaTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  // printf("Itens=%06d \tMetodo=%s \t%fs \t%fms\n", tamanho, metodo, deltaTime, deltaTime*1000);
  return 0;
}
