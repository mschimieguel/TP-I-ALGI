#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"

void print_universidade(Universidade_t Universidade){
	printf("UNIVERSIDADE \n");
	
	printf("  id : %d \n",Universidade.id + 1);
	printf("  nota_de_corte : %d \n",Universidade.nota_de_corte);
	printf("  Vagas : %d \n",Universidade.vagas);
	printf("  n_alunos_aplicados : %d \n",Universidade.n_aln_aplic);
	printf("  n_alunos_aprovados : %d \n",Universidade.n_aprov);
	
	printf("  Alunos aprovados : ");
	
	for (int i = 0; i < Universidade.n_aln_aplic;i++)
		printf("%d ",Universidade.lista_aln_aprov[i]);
	printf("\n");

}
Universidade_t* inicializa_universidades(int m,int U_vagas[],int U_nota_corte[]){
	Universidade_t *Universidades = (Universidade_t*)malloc(m*sizeof(Universidade_t));
	
	for(int i = 0;i < m;i++){
		Universidades[i].n_aln_aplic = 0;
		Universidades[i].n_aprov = 0;
		Universidades[i].vagas = U_vagas[i];
		Universidades[i].nota_de_corte = U_nota_corte[i];
	}
	return Universidades;
}
