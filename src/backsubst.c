#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	double roznica;	
	if(mat->r != mat->c || mat->r != b->r)
		return 2;
	for(int i=0;i<b->r;i++) {
		roznica=b->data[(b->r)-i-1][0];
		for(int j=0;j<i;j++) {
		roznica-=mat->data[(mat->r)-i-1][(mat->c)-j-1]*(x->data[(b->r)-j-1][0]);
		}
		
		if(mat->data[(mat->r)-i-1][(mat->c)-i-1]==0)
			return 1;
		x->data[(b->r)-i-1][0]=roznica/mat->data[(mat->r)-i-1][(mat->c)-i-1];
	}
	
				return 0;
}


