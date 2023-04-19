#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = ok;
  return status;
}

int minor_mx(int i, int j, matrix_t *A, matrix_t *result) {
  int status = ok, idx, jdx;
  if (valid_matrix(A) && is_square_mx(A)) {
    if (!s21_create_matrix(A->rows - 1, A->columns - 1, &result)) {
      fill_mx(i, j, A, result);
    } else {
      status = err_matrix;
    }
  } else {
    status = err_matrix;
  }
  return status;
}

void fill_mx(int i, int j, matrix_t *A, matrix_t *R) {
  int idx, jdx;
  for (idx = 0; idx < A->rows; ++idx) {
    for (jdx = 0; jdx < A->columns; ++jdx) {
      if (idx != i && jdx != j) {
        R->matrix[idx][jdx] = A->matrix[idx][jdx];
      }
    }
  }
}

int det(matrix_t *mx, double *elem) {
  int status = ok;
  if (valid_matrix(mx)) {
    *elem = mx->matrix[0][0] * mx->matrix[1][1] -
            mx->matrix[0][1] * mx->matrix[1][0];
  } else {
    status = err_matrix;
  }
  return status;
}
