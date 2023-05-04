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
  int idx, jdx, idx_skip = 0;
  for (idx = 0; idx < A->rows; ++idx) {
    int jdx_skip = 0;
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

int copy_mx(matrix_t *A, matrix_t *result) {
  int status = ok;
  if (valid_matrix(A)) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int idx = 0; idx < A->rows; ++idx) {
      for (int jdx = 0; jdx < A->columns; ++jdx) {
        result->matrix[idx][jdx] = A->matrix[idx][jdx];
      }
    }
  } else {
    status = err_matrix;
  }
  return status;
}

int minor_mx(matrix_t *A, matrix_t *result) {
  int status = ok, idx, jdx;
  matrix_t tmp;
  if (A->rows == 1 && A->columns == 1) {
    result->matrix[0][0] = A->matrix[0][0];
  } else if (!s21_create_matrix(A->rows - 1, A->columns - 1, &tmp)) {
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

// void print_mx(matrix_t *A) {
//   int i, j;
//   for (i = 0; i < A->rows; i++) {
//     for (j = 0; j < A->columns; j++) {
//       printf("%lf\t", A->matrix[i][j]);
//     }
//     printf("\n");
//   }
// }