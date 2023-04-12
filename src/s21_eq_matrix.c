#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = 1;
  int i = 0, j = 0;
  if (NULL == A || NULL == B) {
    status = 0;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    status = 0;
  } else {
    for (; i < A->rows; ++i) {
      for (; j < A->columns; ++j) {
        if (fabs(A->matrix[i][j] - fabs(B->matrix[i][j])) > 1e-6) {
          status = 0;
          break;
        }
      }
    }
  }
  return (status == 1) ? SUCCESS : FAILURE;
}