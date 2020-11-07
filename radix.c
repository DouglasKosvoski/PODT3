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
    for (size_t i = 0; i < tamanho; i++)
      vetor[i] = -i;
  }
}

void imprime_vetor(int vetor[], int tamanho){
  for(size_t i = 0; i<tamanho; i++){
    printf("%2d ", vetor[i]);
  } printf("\n");
}

void busca_max(int vetor[], int tamanho) {

}

void radix_sort(vetor[], tamanho) {
	int max = busca_max(vetor, tamanho);
	for (size_t i = 0; max/i > 0; i *= 10) {
		counting_sort(vetor, i, tamanho);
	}
}

int counting_sort(int vetor[], int tamanho) {
//encontra o maior valor em v[]
	int maior = v[0];
	for (int i = 1; i < v.length; i++) {
		if (v[i] > maior) {
			maior = v[i];
		}
	}

//conta quantas vezes cada valor de v[] aparece
	int[] c = new int[maior+1];//+1 pois se 10 for o maior valor, ele iria apenas de 0 a 9
	for (int i = 0; i < v.length; i++) {
		c[v[i]] += 1;
	}

//acumula as vezes de cada elemento de v[] com os elementos anteriores a este
	for (int i = 1; i < c.length; i++) {
		c[i] += c[i-1];
	}

//adiciona os elementos em suas posições conforme o acumulo de suas frequencias
	Integer[] b = new Integer[v.length];
	for (int i = b.length-1; i >= 0; i--) {//percorre do fim para o inicio para manter estavel, mas não haveria problema em i = 0; i < b.lenght; i++
		b[c[v[i]] -1] = v[i];
		c[v[i]]--;
	}

	return b;
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
	radixsort(vetor, tamanho);
  imprime_vetor(vetor, tamanho);
  endTime = clock();

  deltaTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
  // printf("Itens=%06d \tMetodo=%s\n", tamanho, metodo);
  printf("Itens=%06d \tMetodo=%s \t%fs \t%fms\n", tamanho, metodo, deltaTime, deltaTime*1000);
  return 0;
}
