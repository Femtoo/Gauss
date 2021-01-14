#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	double roznica;
	x->data[b->r][0]=b->data[b->r][0]/mat->data[mat->r][mat->c];	
	for(int i=1;i<b->r;i++) {
		roznica=b->data[(b->r)-i][0];
		for(int j=0;j<i;j++) {
		roznica-=mat->data[(mat->r)-i][(mat->c)-j]*x->data[(b->r)-j][0];
		}

		x->data[(b->r)-i][0]=roznica/mat->data[(mat->r)-i][(mat->c)-i];
	}
	
	
	
	
	/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */

	/*			int i;
				for (i =0; i < x->r; i++) {
								x->data[i][0] = b->data[i][0];
				}
	*/
				return 0;
}


