#include "universidade.h"
#include "aluno.h"
#ifndef CASAMENTOESTAVEL_H
#define CASAMENTOESTAVEL_H
int* cont_alunos_aplicados(int n,int m,Aluno_t **Alunos,Universidade_t* Univ);
int* alunos_aprovados(int n,int m,Aluno_t **Alunos_Ordenados,Universidade_t* Univ);
double satisfacao_alunos(int n,Aluno_t **Alunos,int *aprovados);

#endif