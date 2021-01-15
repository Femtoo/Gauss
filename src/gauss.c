#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
void zamien_wiersze(Matrix *mat,Matrix *b,int k,int l){
	double m;
	for(int s=k;s<mat->c;s++){
		m=mat->data[k][s];
		mat->data[k][s]=mat->data[l][s];
		mat->data[l][s]=m;
	}
	m=b->data[k][0];
	b->data[k][0]=b->data[l][0];
	b->data[l][0]=m;
}
int eliminate(Matrix *mat, Matrix *b){
	double liczba,m;
	int k,l;
	
	k=0;
	while(k != (mat->r-1)){
		l=k;
		m=fabs(mat->data[k][k]);
		for(int s=k;s<mat->r;s++){
			if(fabs(mat->data[s][k])>m){
				m=fabs(mat->data[s][k]);
					l=s;
			}
		}
		if(l!=k){
			zamien_wiersze(mat,b,k,l);
		}
		
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

