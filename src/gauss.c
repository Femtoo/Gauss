#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	double liczba,liczba2,liczba3,liczba4;
	int i,j,k;

	k=0;
	while(k != (mat->r-1)){
		for(i=k;i<mat->r-1;i++){
			if(mat->data[k][k]==0){
				return 1;
			}
			liczba3 = (mat->data[i+1][k]/mat->data[k][k]);
			for(j=k;j<mat->c;j++){
				liczba2 = mat->data[i+1][j];
				liczba = mat->data[k][j];
				mat->data[i+1][j]=(liczba2-(liczba*liczba3));
			}
			liczba4 = b->data[k][0];
			b->data[i+1][0]=(b->data[i+1][0]-(liczba3*liczba4));	
		}
		k++;
	}
	return 0;
}

