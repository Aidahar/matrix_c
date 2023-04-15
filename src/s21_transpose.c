#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = ok;
  if (valid_matrix(A)) {
    if (!s21_create_matrix(A->columns, A->rows, result)) {
      int idx, jdx;
      for (idx = 0; idx < A->rows; ++idx) {
        for (jdx = 0; jdx < A->columns; ++jdx) {
          result->matrix[jdx][idx] = A->matrix[idx][jdx];
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