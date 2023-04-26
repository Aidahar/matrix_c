#include "s21_matrix.h"

int valid_matrix(matrix_t *A) {
  return (A && check_pos(A->rows, A->rows)) ? 1 : 0;
}

int check_pos(int a, int b) { return (a > 0 && b > 0) ? 1 : 0; }

int eq_size(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns) ? 1 : 0;
}

int is_square_mx(matrix_t *mx) { return (mx->rows == mx->columns) ? 1 : 0; }

void swap_rows(matrix_t *A, int pivot, int i) {
  double tmp;
  for (int j = 0; j < A->columns; ++j) {
    tmp = A->matrix[pivot][j];
    A->matrix[pivot][j] = A->matrix[i][j];
    A->matrix[i][j] = tmp;
  }
}

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

// void print_mx(matrix_t *A) {
//   for (int idx = 0; idx < A->rows; ++idx) {
//     for (int jdx = 0; jdx < A->columns; ++jdx) {
//       printf("matrix[%d][%d] = %f, ", idx, jdx, A->matrix[idx][jdx]);
//     }
//     printf("\n");
//   }
// }

void square_mx(matrix_t *A, double *result) {
  *result =
      A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
}