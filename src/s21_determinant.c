#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = ok;
  if (valid_matrix(A) && is_square_mx(A)) {
    int pivot_index = -1, rc = A->rows;
    double pivot_value = 0;
    *result = 1;
    for (int i = 0; i < rc; i++) {
      for (int j = i; j < rc; j++) {
        if (fabs(A->matrix[j][i]) > pivot_value) {
          pivot_index = j;
          pivot_value = fabs(A->matrix[j][i]);
        }
      }
      if (pivot_value < EPS) {
        status = err_calculate;
        break;
      }
      if (pivot_index != i) {
        swap_rows(A, pivot_index, i);
        *result *= -1;
      }
      for (int j = i + 1; j < rc; j++) {
        if (A->matrix[j][i] != 0) {
          double multiplier = 1 / A->matrix[i][i] * A->matrix[j][i];
          for (int k = i; k < rc; k++) {
            A->matrix[j][k] -= A->matrix[i][k] * multiplier;
          }
        }
      }
      *result *= A->matrix[i][i];
    }
  } else {
    status = err_calculate;
  }
  return status;
}

void swap_rows(matrix_t *A, int pivot, int i) {
  int col = A->columns;
  double tmp;
  for (int j = 0; j < col; ++j) {
    tmp = A->matrix[pivot][col];
    A->matrix[pivot][col] = A->matrix[i][col];
    A->matrix[i][col] = tmp;
  }
}