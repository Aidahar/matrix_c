#include "s21_matrix.h"

int minor_mx(int i, int j, matrix_t *A, matrix_t *result) {
  int status = ok, idx, jdx;
  if(valid_matrix(A) && (A->rows == A->columns)) {
    if (!s21_create_matrix(A->rows - 1, A->columns - 1, &result)) {
      for(idx = 0; idx < A->rows; ++idx) {
        for (jdx = 0; jdx < A->columns; ++jdx) {
          if (idx != i && jdx != j) {
            result->matrix[idx][jdx] = A->matrix[idx][jdx];
          }
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