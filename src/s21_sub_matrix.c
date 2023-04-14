#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = ok; 
  if (valid_matrix(A) && valid_matrix(B) && eq_size(A, B)) { 
    if (!s21_create_matrix(A->rows, A->columns, result)) {
      int idx, jdx;
      for (idx = 0; idx < A->rows; ++idx) {
        for (jdx = 0; jdx < A->columns; ++jdx) {
          result->matrix[idx][jdx] = A->matrix[idx][jdx] - B->matrix[idx][jdx];
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