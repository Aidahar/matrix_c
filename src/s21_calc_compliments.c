#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = ok;
  if (valid_matrix(A)) {
    if (is_square_mx(A)) {
      s21_create_matrix(A->rows, A->columns, result);
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
  if (!s21_create_matrix(A->rows - 1, A->columns - 1, &tmp)) {
    for (idx = 0; idx < A->rows; ++idx) {
      for (jdx = 0; jdx < A->columns; ++jdx) {
        fill_mx(idx, jdx, A, &tmp);
        double res = 0;
        s21_determinant(&tmp, &res);
        result->matrix[idx][jdx] = res;
        if ((idx + jdx) % 2 != 0) result->matrix[idx][jdx] *= -1;
      }
    }
    s21_remove_matrix(&tmp);
  } else {
    status = err_matrix;
  }
  return status;
}
