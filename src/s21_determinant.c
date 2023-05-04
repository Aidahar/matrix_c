#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = ok, row = A->rows, col = A->columns;
  *result = 1;
  if (valid_matrix(A)) {
    if (row == 1 && col == 1) {
      *result = A->matrix[0][0];
    } else if (row == 2 && col == 2) {
      square_mx(A, result);
    } else if (is_square_mx(A)) {
      int cnt = 0;
      gauss(A, &cnt);
      det_calc(A, &result, cnt);
    } else {
      status = err_calculate;
    }
  } else {
    status = err_matrix;
  }
  return status;
}

int swap(matrix_t *A, int idx, int kdx, int col) {
  int jdx, cnt = 1;
  for (jdx = 0; jdx < col; ++jdx) {
    double temp;
    temp = A->matrix[idx][jdx];
    A->matrix[idx][jdx] = A->matrix[kdx][jdx];
    A->matrix[kdx][jdx] = temp;
  }
  return cnt;
}

void det_calc(matrix_t *A, double **result, int cnt) {
  int idx;
  for (idx = 0; idx < A->rows; ++idx) {
    **result *= A->matrix[idx][idx];
  }
  **result *= pow(-1, cnt);
}

void gauss(matrix_t *A, int *cnt) {
  int idx, jdx, kdx, row = A->rows, col = A->columns;
  for (idx = 0; idx < row - 1; ++idx) {
    for (kdx = idx + 1; kdx < row; ++kdx) {
      if (A->matrix[idx][idx] == 0) {
        *cnt = swap(A, idx, kdx, col);
      }
    }
    for (kdx = idx + 1; kdx < row; ++kdx) {
      double term = A->matrix[kdx][idx] / A->matrix[idx][idx];
      for (jdx = 0; jdx < col; ++jdx) {
        A->matrix[kdx][jdx] = A->matrix[kdx][jdx] - term * A->matrix[idx][jdx];
      }
    }
  }
}