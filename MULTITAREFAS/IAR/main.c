#include <stdint.h>
#include <stdio.h>
#include "multitarefas.h"

#include <pthread.h>
#include <semaphore.h>

/*
 * Prototipos das tarefas
 */
/*
void tarefa_1(void);
void tarefa_2(void);
/*
/*
 * Configuracao dos tamanhos das pilhas
 */
/*
#define TAM_PILHA_1		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_2		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_OCIOSA	(TAM_MINIMO_PILHA + 24)
*/
/*
 * Declaracao das pilhas das tarefas
 */
/*
uint32_t PILHA_TAREFA_1[TAM_PILHA_1];
uint32_t PILHA_TAREFA_2[TAM_PILHA_2];
uint32_t PILHA_TAREFA_OCIOSA[TAM_PILHA_OCIOSA];
*/

#define N_ITENS 50
int buffer[N_ITENS];

sem_t pos_vazia;
sem_t pos_ocupada;

int inicio = 0, final = 0;

void* produtor(void *v) {
  int i;

  for (i = 0; i < 5 * N_ITENS; i++) {
    SemaforoAguarda(&pos_vazia);
    printf("Produtor, item = %d.\n", i);     
    final = (final + 1) % N_ITENS;
    buffer[final] = i;
    SemaforoLibera(&pos_ocupada);
    sleep(random() % 5);
  }
  return NULL;
}

void* consumidor(void *v) {
  int i;

  for (i = 0; i < 5 * N_ITENS; i++) {
    SemaforoAguarda(&pos_ocupada);
    inicio = (inicio + 1) % N_ITENS;
    printf("Consumidor, item = %d.\n", buffer[inicio]);
    SemaforoLibera(&pos_vazia);
    sleep(random() % 5);    
  }
  return NULL;
}

/*
 * Funcao principal de entrada do sistema
 */
int main(void)
{
  sem_init(&pos_vazia, 0, N_ITENS);
  sem_init(&pos_ocupada, 0, 0);
  
  pthread_create(&thr_produtor, NULL, produtor, NULL);
  pthread_create(&thr_consumidor, NULL, consumidor, NULL);

  pthread_join(thr_produtor, NULL); 
  pthread_join(thr_consumidor, NULL);

  sem_destroy(&pos_vazia);
  sem_destroy(&pos_ocupada);
  
  return 0;
	
}


/* Tarefas de exemplo que usam funcoes para suspender/continuar as tarefas */
/*
void tarefa_1(void)
{
	volatile uint16_t a = 0;
	for(;;)
	{
		a++;
		TarefaContinua(2);
	
	}
}

void tarefa_2(void)
{
	volatile uint16_t b = 0;
	for(;;)
	{
		b++;
		TarefaEspera(100);	
	}
}

*/