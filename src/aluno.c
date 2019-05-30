#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
void print_aluno(Aluno_t aluno){
	printf("ALUNO \n");
	printf("id : %d \n",aluno.id + 1);
	printf("nota : %d \n",aluno.nota);
	//printf("Uniersidade aprov: %d \n",aluno.univ_aprov);
	printf("Universidades aplicadas : ");
	for (int i = 0; i < aluno.n_aplicacoes;i++)
		printf("%d ",aluno.Univ_aplicadas[i]);
	printf("\n\n");
}

Aluno_t **merge(Aluno_t **esquerda,Aluno_t **direita,int n_esq,int n_dir){
	Aluno_t **resultado =(Aluno_t **)malloc((n_esq + n_dir) * sizeof(Aluno_t*));
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < n_esq && j < n_dir){
		if (esquerda[i]->nota >= direita[j]->nota){
			resultado[k] = esquerda[i];
			i++;
		}
		else{
			resultado[k] = direita[j];
			j++;
		}
		k++;
	} 	
	if (k < n_esq + n_dir){
		for(;i < n_esq;i++){
			resultado[k] = esquerda[i];
			k++;
		}
		for(;j < n_dir;j++){
			resultado[k] = direita[j];
			k++;
		}
	}
	free(esquerda);
	free(direita);
	return resultado;
}
Aluno_t **mergesort (Aluno_t **alunos,int inicio,int fim){
	Aluno_t **resultado;
	
	if(fim == inicio){
		resultado = (Aluno_t**)malloc(1* sizeof(Aluno_t*));
		alocs++;
		resultado[0] = alunos[inicio];
		return resultado;
	}
	int meio = (inicio + fim)/2;
	Aluno_t **esquerda = mergesort(alunos,inicio,meio);
	Aluno_t **direita = mergesort(alunos,meio+1,fim);
	resultado = merge(esquerda,direita,meio - inicio + 1,fim - meio);
	
	return resultado;
}
Aluno_t **inicializa_alunos(int n,int A_Naplic[],int A_notas[],int **A_aplic){
	Aluno_t **Alunos = (Aluno_t**)malloc(n*sizeof(Aluno_t*));
	for (int i = 0;i < n;i++){
		Alunos[i] = (Aluno_t*)malloc(sizeof(Aluno_t));
		Alunos[i]->id = i;
		Alunos[i]->Univ_aplicadas = A_aplic[i];
		Alunos[i]->n_aplicacoes = A_Naplic[i];
		Alunos[i]->nota = A_notas[i];
	}
	return Alunos;
}