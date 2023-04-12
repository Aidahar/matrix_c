#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = 1;
  int i = 0, j = 0;
  if (NULL == A->matrix || NULL == B->matrix) {
    status = 0;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    status = 0;
  } else {
    for (; i < A->rows; ++i) {
      for (; j < A->columns; ++j) {
        if (abs(A->matrix[i][j] - B->matrix[i][j]) < 0.0000001) {
          status = 0;
          break;
        }
      }
    }
  }
  return (status == 1) ? SUCCESS : FAILURE;
}