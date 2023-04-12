#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = 1, idx = 0, jdx = 0;
  if (NULL == A || NULL == B) {
    status = err_matrix;
  } else if ((A->rows != B->rows) || (A->columns != B->columns)) {
    status = err_matrix;
  } else {
    }
}