#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = ok;
  if (valid_matrix(A) && valid_number(&number)) { 
    if (!s21_create_matrix(A->rows, A->columns, result)) {
      int idx, jdx;
      for (idx = 0; idx < A->rows; ++idx) {
        for (jdx = 0; jdx < A->columns; ++jdx) {
          result->matrix[idx][jdx] = A->matrix[idx][jdx] * number;
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