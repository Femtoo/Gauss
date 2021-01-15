#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */


int eliminate(Matrix *mat, Matrix *b){
	double liczba, tmp;
	int k;
	int sortowanie;
	k=0;
	while(k != (mat->r-1)){
		
		do {
			sortowanie=1;
		for(int j=1; j< mat->r-k;j++) {
		if(mat->data[j-1+k][k] > mat->data[j+k][k]) {
		for(int m=k;m<mat->c;m++){
			tmp= mat->data[k][m];
			mat->data[k][m]=mat->data[j-1][m];
			mat->data[j-1][m]=tmp;
		}
		tmp=b->data[k][0];
		b->data[k][0]=b->data[j-1][0];
		b->data[j-1][0]=tmp;

			
			/*double tmp = mat->data[j-1+k][k];
		mat->data[j-1+k][k]=mat->data[j+k][k];
		mat->data[j+k][k] = tmp;
		for(int m=1;m
			*/
		sortowanie=0;
		}
		}
		} while(!sortowanie);	

		for(int i=k;i<mat->r-1;i++){
			if(mat->data[k][k]==0){
				return 1;
			}
			liczba = (mat->data[i+1][k]/mat->data[k][k]);
			for(int j=k;j<mat->c;j++){
				mat->data[i+1][j]=(mat->data[i+1][j]-(mat->data[k][j]*liczba));
			}
			b->data[i+1][0]=(b->data[i+1][0]-(liczba*b->data[k][0]));	
		}
		k++;
	}
	return 0;
}

