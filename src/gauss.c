#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
void zamien_wiersze(Matrix *mat,Matrix *b,int k,int l){
	int s;
	double m;
	for(s=k;s<mat->c;s++){
		m=mat->data[k][s];
		mat->data[k][s]=mat->data[l][s];
		mat->data[l][s]=m;
	}
	m=b->data[k][0];
	b->data[k][0]=b->data[l][0];
	b->data[l][0]=m;
}
int eliminate(Matrix *mat, Matrix *b){
	double liczba,liczba2,liczba3,liczba4;
	int i,j,k;
	int s,l;
	double m;
	
	k=0;
	while(k != (mat->r-1)){
		l=k;
		m=fabs(mat->data[k][k]);
		for(s=k;s<mat->r;s++){
			if(fabs(mat->data[s][k])>m){
				m=fabs(mat->data[s][k]);
					l=s;
			}
		}
		if(l!=k){
			zamien_wiersze(mat,b,k,l);
		}
		
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

