#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = ok;
  if (valid_matrix(A)) {
    int r = s21_create_matrix(A->rows, A->columns, result);
    if (is_square_mx(A) && r) {
      minor_mx(A, result);
    } else {
      status = err_calculate;
    }
  } else {
    status = err_matrix;
  }
  return status;
}

int minor_mx(matrix_t *A, matrix_t *result) {
  int status = ok, idx, jdx;
  matrix_t tmp;
  if (s21_create_matrix(A->rows - 1, A->columns - 1, &tmp)) {
    for (idx = 0; idx < A->rows; ++idx) {
      for (jdx = 0; jdx < A->columns; ++jdx) {
        fill_mx(idx, jdx, A, &tmp);
        int s = s21_determinant(&tmp, &result->matrix[idx][jdx]);
        if (!s) {
          status = err_calculate;
          break;
        }
        if ((idx + jdx) % 2 != 0) result->matrix[idx][jdx] *= -1;
      }
    }
    s21_remove_matrix(&tmp);
  } else {
    status = err_matrix;
  }
  return status;
}

void fill_mx(int i, int j, matrix_t *A, matrix_t *tmp) {
  int idx, jdx, idx_skip = 0, jdx_skip = 0;
  for (idx = 0; idx < A->rows; ++idx) {
    for (jdx = 0; jdx < A->columns; ++jdx) {
      if (idx != i && jdx != j) {
        tmp->matrix[idx_skip][jdx_skip] = A->matrix[idx][jdx];
        ++jdx_skip;
      }
    }
    if (idx != i) ++idx_skip;
  }
}
