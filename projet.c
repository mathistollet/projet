#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE1 50
#define SIZE2 100

void affichejeu(char tab[SIZE1][SIZE2], int size1, int size2) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (i == 0 || i == size1 - 1) {
                tab[i][j] = '*';
            }
            
           else if(j == 0 || j == size2 - 1) {
            	tab[i][j] = '*';
            	}
            	else{
            	 tab[i][j] = ' ';
            	 }
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
   
}

int main() {
    int size1 = SIZE1, size2 = SIZE2;
    char tab[SIZE1][SIZE2];  
    
    affichejeu(tab, size1, size2);

    return 0;
}
