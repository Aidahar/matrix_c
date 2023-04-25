#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = ok;
  return status;
}

void minor_singl(matrix_t *A, double *result) { *result = A->matrix[0][0]; }

void minor_square(matrix_t *A, double *result) {
  *result =
      A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
}

void minor_triangle(matrix_t *A, double *result) {
  *result = A->matrix[0][0] * A->matrix[1][1] * A->matrix[2][2] +
            A->matrix[0][1] * A->matrix[1][2] * A->matrix[2][0] +
            A->matrix[0][2] * A->matrix[1][0] * A->matrix[2][1] -
            A->matrix[0][2] * A->matrix[1][1] * A->matrix[2][0] -
            A->matrix[0][1] * A->matrix[1][0] * A->matrix[2][2] -
            A->matrix[0][0] * A->matrix[1][2] * A->matrix[2][1];
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
  int idx, jdx, idx_skip = 0, jdx_skip = 0;
  for (idx = 0; idx < A->rows; ++idx) {
    for (jdx = 0; jdx < A->columns; ++jdx) {
      if (idx != i && jdx != j) {
        R->matrix[idx_skip][jdx_skip] = A->matrix[idx][jdx];
        ++jdx_skip;
      }
    }
    if (idx != i) ++idx_skip;
  }
}
