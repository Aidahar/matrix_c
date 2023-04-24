#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = ok;
  if (valid_matrix(A) && valid_matrix(B)) {
    if (A->columns == B->rows) {
      if (!s21_create_matrix(A->rows, B->columns, result)) {
        mul_matr(A, B, result);
      } else {
        status = err_matrix;
      }
    } else {
      status = err_calculate;
    }
  } else {
    status = err_matrix;
  }
  return status;
}

void mul_matr(matrix_t *A, matrix_t *B, matrix_t *result) {
  int idx, jdx, kdx;
  for (idx = 0; idx < A->rows; ++idx) {
    for (jdx = 0; jdx < B->columns; ++jdx) {
      for (kdx = 0; kdx < A->columns; ++kdx) {
        result->matrix[idx][jdx] += A->matrix[idx][kdx] * B->matrix[kdx][jdx];
      }
    }
  }
}