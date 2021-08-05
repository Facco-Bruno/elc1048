#include <stdint.h>
#include <stdio.h>
#include "multitarefas.h"

/*
 * Prototipos das tarefas
 */

void tarefa_0(void);
void tarefa_1(void);
void tarefa_2(void);
void tarefa_3(void);
void tarefa_4(void);
void tarefa_5(void);

/*
 * Configuracao dos tamanhos das pilhas
 */

#define TAM_PILHA_0		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_1		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_2		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_3		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_4		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_5		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_OCIOSA	(TAM_MINIMO_PILHA + 24)

/*
 * Declaracao das pilhas das tarefas
 */

uint32_t PILHA_TAREFA_0[TAM_PILHA_0];
uint32_t PILHA_TAREFA_1[TAM_PILHA_1];
uint32_t PILHA_TAREFA_2[TAM_PILHA_2];
uint32_t PILHA_TAREFA_3[TAM_PILHA_3];
uint32_t PILHA_TAREFA_4[TAM_PILHA_4];
uint32_t PILHA_TAREFA_5[TAM_PILHA_5];
uint32_t PILHA_TAREFA_OCIOSA[TAM_PILHA_OCIOSA];

/*
 * Definição dos contadores
 */

uint16_t a = 0;
uint16_t b = 0;
uint16_t c = 0;
uint16_t d = 0;
uint16_t e = 0;

/*
 * Funcao principal de entrada do sistema
 */

int main(void)
{
  /* Criacao das tarefas */
	/* Parametros: ponteiro, nome, ponteiro da pilha, tamanho da pilha, prioridade da tarefa */
	
	CriaTarefa(tarefa_0, "Tarefa 0", PILHA_TAREFA_0, TAM_PILHA_0, 5);
	
	CriaTarefa(tarefa_1, "Tarefa 1", PILHA_TAREFA_1, TAM_PILHA_1, 4);
        
        CriaTarefa(tarefa_2, "Tarefa 2", PILHA_TAREFA_2, TAM_PILHA_2, 3);
        
        CriaTarefa(tarefa_3, "Tarefa 3", PILHA_TAREFA_3, TAM_PILHA_3, 2);
        
        CriaTarefa(tarefa_4, "Tarefa 4", PILHA_TAREFA_4, TAM_PILHA_4, 1);
        
        CriaTarefa(tarefa_5, "Tarefa 5", PILHA_TAREFA_5, TAM_PILHA_5, 6);
        
	/* Cria tarefa ociosa do sistema */
	CriaTarefa(tarefa_ociosa,"Tarefa ociosa", PILHA_TAREFA_OCIOSA, TAM_PILHA_OCIOSA, 0);
	
	/* Configura marca de tempo */
	ConfiguraMarcaTempo();   
	
	/* Inicia sistema multitarefas */
	IniciaMultitarefas();
	
	/* Nunca chega aqui */
	while (1)
	{
	}
}

/* Tarefas de exemplo que usam funcoes para suspender/continuar as tarefas */

void tarefa_0(void)
{
	for(;;)
	{
		a++;
                TarefaSuspende(1);
                TarefaContinua(5);
                
	
	}
}

void tarefa_1(void)
{
	for(;;)
	{
		b++;
                TarefaSuspende(4);
                TarefaContinua(5);
                
	}
}

void tarefa_2(void)
{
	for(;;)
	{
		c++;
                TarefaSuspende(3);
                TarefaContinua(4);
                
	}
}

void tarefa_3(void)
{
	for(;;)
	{
		d++;
                TarefaContinua(3);
                TarefaSuspende(2);
        }
}

void tarefa_4(void)
{
	for(;;)
	{
		e++;
                TarefaContinua(2);
                TarefaSuspende(5);	
                
	}
}

void tarefa_5(void)
{
    for(;;)
	{
            printf("%d", a+b+c+d+e);
            TarefaEspera(30000);
        }
}
