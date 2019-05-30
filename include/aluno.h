#ifndef ALUNO_H
#define ALUNO_H

typedef struct Aluno{
	int id;
	int nota;
	int n_aplicacoes;
	int *Univ_aplicadas;
} Aluno_t;
int alocs;
int frees;

void print_aluno(Aluno_t aluno);
Aluno_t **merge(Aluno_t **esquerda,Aluno_t **direita,int n_esq,int n_dir);
Aluno_t **mergesort (Aluno_t **alunos,int inicio,int fim);
Aluno_t **inicializa_alunos(int n,int A_Naplic[],int A_notas[],int **A_aplic);

#endif