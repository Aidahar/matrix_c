#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = 1, idx = 0, jdx = 0;
  if (NULL == A || NULL == B || NULL == result) {
    status = err_matrix;
  } else if ((A->rows != B->rows) || (A->columns != B->columns) || (result->rows != A->rows) || (result->columns != A->columns)) {
    status = err_matrix;
  } else {
    for (; idx < A->rows; ++idx) {
      for (; jdx < A->columns; ++jdx) {
        result->matrix[idx][jdx] = A->matrix[idx][jdx] + B->matrix[idx][jdx];
      }
    }
  }
}