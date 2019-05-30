#include <stdio.h>
#include <stdlib.h>
#include "casamento_estavel.h"


int main(int argc,char *argv[]){
	FILE *arq_universidade = fopen(argv[1],"r");
	FILE *arq_alunos = fopen(argv[2],"r");
	//tratamento de erro de arquivo caso não existam 
	if(!arq_universidade){
		printf("Arquivo de Universidades Inexistente\n");
		return 0;
	}
	if(!arq_alunos){
		printf("Arquivo de Alunos Inexistente\n");
		return 0;
	}
	//n == alunos
	//m == universidades
	int n,m;
	
	//Inicializando as Universidades 
	fscanf(arq_universidade,"%d",&m);
	int U_vagas[m],U_nota_corte[m];
	for(int i = 0;i < m;i++)
		fscanf(arq_universidade,"%d %d",&U_vagas[i],&U_nota_corte[i]);
	
	Universidade_t* Univ = inicializa_universidades(m,U_vagas,U_nota_corte);
	
	//Inicializando os alunos
	fscanf(arq_alunos,"%d",&n);
	int A_Naplic[n],A_notas[n],*A_aplic[n];
	for (int i = 0;i < n;i++){
		fscanf(arq_alunos,"%d %d",&A_Naplic[i],&A_notas[i]);
		A_aplic[i] = (int*)malloc(A_Naplic[i]*sizeof(int));
		for(int j = 0;j < A_Naplic[i];j++)
			fscanf(arq_alunos,"%d",&A_aplic[i][j]);
	}
	Aluno_t **Alunos = inicializa_alunos(n,A_Naplic,A_notas,A_aplic);
	int *alunos_aplicados = cont_alunos_aplicados(n,m,Alunos,Univ);
	
	//ordenando alunos pela nota
	Aluno_t **Alunos_Ordenados = mergesort(Alunos,0,n - 1);
		
	//Alocando alunos nas universidades
	int *aprovados = alunos_aprovados(n,m,Alunos_Ordenados,Univ); 
	
	//printando o Output na stdout
	printf("Grupos com alocacao\n");
	for (int i = 0;i < n;i++)
		if (aprovados[i] > -1)
			printf("%d %d\n",Alunos[i]->id +1,aprovados[i]);
	printf("Candidatos nao alocados\n");
	for (int i = 0;i < n;i++)
		if (aprovados[i] ==  -1)
			printf("%d\n",Alunos[i]->id +1);
	
	//desalocando 

	for (int i = 0 ; i < n;i++){
		free(Alunos[i]->Univ_aplicadas);
		free(Alunos[i]);
	}
	for(int j = 0;j < m;j++)
		free(Univ[j].lista_aln_aprov);
	free(Univ);
	free(Alunos_Ordenados);
	free(Alunos);
	free(alunos_aplicados);
	free(aprovados);
	return 0;
}