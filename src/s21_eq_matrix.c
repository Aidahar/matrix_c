#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = 1;

  if (NULL == A || NULL == B) {
    status = 0;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    status = 0;
  } else {
    int idx, jdx;
    for (idx = 0; idx < A->rows; ++idx) {
      for (jdx = 0; jdx < A->columns; ++jdx) {
        if (fabs(A->matrix[idx][jdx] - B->matrix[idx][jdx]) > EPS) {
          status = 0;
          break;
        }
      }
    }
  }
  return (status == 1) ? SUCCESS : FAILURE;
}