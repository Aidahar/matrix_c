#include "s21_matrix.h"

int minor_mx(int i, int j, matrix_t *A, matrix_t *result) {
  int status = ok, idx, jdx;
  if(valid_matrix(A) && (A->rows == A->columns)) {
    if (!s21_create_matrix(A->rows, A->columns, &result)) {
      for(idx = ; idx < A->rows; ++idx) {
        for (jdx = ; jdx < A->columns; ++jdx) {
          if (idx != i && jdx != j) {
            result->matrix[idx][jdx] = A->matrix[idx][jdx];
          }
        }
      }
    } else {
      status = err_matrix;
    }
  } else {
    status = err_matrix;
  }
  return status;
}