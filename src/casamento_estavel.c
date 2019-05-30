#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "universidade.h"
#include "aluno.h"

int* cont_alunos_aplicados(int n,int m,Aluno_t **Alunos,Universidade_t* Univ){
	//atribui para cada Universidade q quantidade de alunos que a escolheu
	int *Alunos_aplicados = (int*)malloc(m*sizeof(int));
	for (int i = 0;i < n;i++)
		for(int j = 0;j < Alunos[i]->n_aplicacoes;j++)
			Univ[Alunos[i]->Univ_aplicadas[j] -1].n_aln_aplic += 1;			
	for(int i = 0;i < m;i++){
		Univ[i].lista_aln_aprov = (int*)malloc(Univ[i].n_aln_aplic*sizeof(int));
		Alunos_aplicados[i] = Univ[i].n_aln_aplic;
		for(int j = 0;j < Univ[i].n_aln_aplic;j++)
			Univ[i].lista_aln_aprov[j] = -1;
	}

	return Alunos_aplicados;
}

int* alunos_aprovados(int n,int m,Aluno_t **Alunos_Ordenados,Universidade_t* Univ){
	//faz com que caa universidade tenha a sua lista de aprovados determinando os casamnetos estaveis
	int *aprovados  = (int*)malloc(n*sizeof(int));
	Universidade_t *Univ_atual = NULL;
	for (int i = 0;i < n;i++){
		aprovados[Alunos_Ordenados[i]->id] = -1;	
		for (int j = 0;j < Alunos_Ordenados[i]->n_aplicacoes;j++){
			Univ_atual = &Univ[Alunos_Ordenados[i]->Univ_aplicadas[j] - 1];
			if (Alunos_Ordenados[i]->nota >= Univ_atual->nota_de_corte && Univ_atual->vagas > Univ_atual->n_aprov){
				Univ_atual->lista_aln_aprov[Univ_atual->n_aprov] = Alunos_Ordenados[i]->id;
				Univ_atual->n_aprov++;
				aprovados[Alunos_Ordenados[i]->id] = Univ_atual->id + 1;
				break;
			}				
		}
	}
	return aprovados;
}

double satisfacao_alunos(int n,Aluno_t **Alunos,int *aprovados){
	double somatorio = 0.0;
	double pos = 0;
	for (int i = 0;i < n;i++){
		pos = 0;
		if (aprovados[i] > -1){
			for(int j =0;j < Alunos[i]->n_aplicacoes;j++){
				if(aprovados[i] == Alunos[i]->Univ_aplicadas[j]){
					pos = (double) j + 1.0;
					break; 
				}
				somatorio += 1/((log((double)pos + 1.0 )/log((double)2.0)));
			}
		}
	}
	return somatorio;
}