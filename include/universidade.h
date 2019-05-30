#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H

typedef struct Universidade{
	int id;
	int nota_de_corte;
	int vagas;
	int n_aln_aplic;
	int n_aprov;
	int *lista_aln_aprov;
} Universidade_t;
void print_universidade(Universidade_t Universidade);
Universidade_t* inicializa_universidades(int m,int U_vagas[],int U_nota_corte[]);

#endif