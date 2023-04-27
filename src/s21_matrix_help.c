#include "s21_matrix.h"

int valid_matrix(matrix_t *A) {
  return (A && check_pos(A->rows, A->rows)) ? 1 : 0;
}

int check_pos(int a, int b) { return (a > 0 && b > 0) ? 1 : 0; }

int eq_size(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns) ? 1 : 0;
}

int is_square_mx(matrix_t *mx) { return (mx->rows == mx->columns) ? 1 : 0; }

void fill_mx(int i, int j, matrix_t *A, matrix_t *tmp) {
  int idx, jdx, idx_skip = 0, jdx_skip = 0;
  for (idx = 0; idx < A->rows; ++idx) {
    jdx_skip = 0;
    for (jdx = 0; jdx < A->columns; ++jdx) {
      if (idx != i && jdx != j) {
        tmp->matrix[idx_skip][jdx_skip] = A->matrix[idx][jdx];
        ++jdx_skip;
      }
    }
    if (idx != i) ++idx_skip;
  }
}

void square_mx(matrix_t *A, double *result) {
  *result =
      A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
}

void print_mx(matrix_t *A) {
  for (int idx = 0; idx < A->rows; ++idx) {
    for (int jdx = 0; jdx < A->columns; ++jdx) {
      printf("%f ", A->matrix[idx][jdx]);
    }
    printf("\n");
  }
}

int copy_mx(matrix_t *A, matrix_t *result) {
  int status = ok;
  if (valid_matrix(A)) {
    s21_create_matrix(A->rows, A->columns, result);
    for(int idx = 0; idx < A->rows; ++idx) {
      for (int jdx = 0; jdx < A->columns; ++jdx) {
        result->matrix[idx][jdx] = A->matrix[idx][jdx];
      }
    }
  } else {
    status = err_matrix;
  }
  return status;
}