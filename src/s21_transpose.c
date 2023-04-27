#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = ok;
  if (valid_matrix(A)) {
    if (!s21_create_matrix(A->columns, A->rows, result)) {
      int idx, jdx;
      for (idx = 0; idx < A->columns; ++idx) {
        for (jdx = 0; jdx < A->rows; ++jdx) {
          result->matrix[idx][jdx] = A->matrix[jdx][idx];
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