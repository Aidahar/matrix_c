#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = ok, idx = 0, jdx = 0;
  if (valid_matrix(A) || valid_matirx(B) || valid_matrix(result)) {
    status = err_matrix;
  } else if (check_pos(A->rows, B->rows) || check_pos(A->columns, B->columns) ||
             check_pos(result->rows, A->rows) ||
             check_pos(result->columns, A->columns)) {
    status = err_matrix;
  } else {
    for (; idx < A->rows; ++idx) {
      for (; jdx < A->columns; ++jdx) {
        result->matrix[idx][jdx] = A->matrix[idx][jdx] + B->matrix[idx][jdx];
        if (!result) {
          status = err_calculate;
        }
      }
    }
  }
  return status;
}