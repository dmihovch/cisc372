#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 6




/*
 *
 *
 * 5a:
 *      For the array of arrays matrix, the pros are that the entire data structure is contained
 *      within 1 variable, and the rows can be uneven lengths. The cons are that you have to make
 *      M+1 calls to malloc, since each row of data needs to be allocated seperately
 *
 *      For the one big array matrix, the pros are that since all we are only calling malloc once
 *      to allocate memory for the entire M*N matrix, all the values of the matrix are packed
 *      together efficiently in memory. You also only need to call malloc twice, regardless of
 *      the size of the matrix. The cons are that size you are allocating everything at once,
 *      the matrix is of fixed size, and the rows will always be even. Another con of this
 *      approach is that you have to manually calculate the offsets for each pointer into the matrix,
 *      which can lead to misalignment.
 *
 * 5b:
 *      A situation where I can think that the one big array matrix may be beneficial over the
 *      array of arrays method is in the training of neural networks, or really anywhere that
 *      heavily relies on matrix multiplication. As far as I am aware, these techniques deal in
 *      square or rectangular matrices only, meaning we don't need the row size flexibility of
 *      array of arrays. Also, I would imagine that you could get some sweet sweet optimization
 *      going out of the fact that all the values of the matrix are packed right next to eachother,
 *      maybe some nasty pointer arithmetic?
 *
 *
 *
 *
 */

void matrixArrayOfArrays(int, int);
void matrixOneBigArray(int, int);

int main(int argc, char **argv) {

  matrixArrayOfArrays(N, M);
  matrixOneBigArray(N, M);

  return 0;
}

void matrixArrayOfArrays(int n, int m) {

  float **mat = calloc(m, sizeof(float*));
  if(mat == NULL){
      return;
  }

  int cnt = 1;
  for(int i = 0; i<m; i++){
      mat[i] = calloc(n,sizeof(float));
      for(int j = 0; j<n; j++){
          mat[i][j] = cnt;
          cnt++;
      }
  }

  for(int i = 0; i<m; i++){
      for(int j = 0; j<n; j++){
          printf("%f\t",mat[i][j]);
      }
      printf("\n");
  }

  printf("\n\n");

  for(int i = 0; i<n; i++){
      for(int j = 0; j<m; j++){
          printf("%f\t",mat[j][i]);
      }
      printf("\n");
  }

  for(int i = 0; i<m; i++){
      free(mat[i]);
  }
  free(mat);
}

void matrixOneBigArray(int n, int m) {

    printf("\n");

    float** ptrs = calloc(m,sizeof(float*));
    float* mat = calloc(m*n, sizeof(float));
    if(ptrs == NULL || mat == NULL){
        return;
    }

    int cnt = 1;
    for(int i = 0; i<m; i++){
        ptrs[i] = &mat[n*i];
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            ptrs[i][j] = cnt;
            cnt++;
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            printf("%f\t",ptrs[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            printf("%f\t",ptrs[j][i]);
        }
        printf("\n");
    }
    printf("\n");

    free(ptrs);
    free(mat);

}
