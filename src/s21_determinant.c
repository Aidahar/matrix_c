#include "s21_matrix.h"
int s21_determinant(matrix_t *A, double *result) {
  int status = ok, idx, jdx, k, n = A->rows;
  double ratio; 
  *result = 1;
  if (valid_matrix(A)) {
    if (A->rows == 1 && A->columns == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2 && A->columns == 2) { 
      square_mx(A, result);
    } else if (is_square_mx(A)) {
      for(idx=0; idx < n; ++idx) {
        if(A->matrix[idx][idx] == 0.0) {
            status = err_calculate;
            break;
        }
        for(jdx = idx+1; jdx < n; ++jdx) {
          ratio = A->matrix[jdx][idx]/A->matrix[idx][idx];
          for(k=0;k< n;k++) {
            A->matrix[jdx][k] = A->matrix[jdx][k] - ratio * A->matrix[idx][k];
          }
        }
      }
      for(idx=0; idx < n; ++idx) {
        *result *= A->matrix[idx][idx];
      }
    } else {
      status = err_calculate;
    }
  } else {
    status = err_matrix;
  }
  return status;
}