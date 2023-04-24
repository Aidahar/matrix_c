#include "s21_matrix.h"

int main(void) {
    matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  double result = 0;
  int ret_val = s21_determinant(&A, &result);
  printf("%d %d\n", ret_val, ok);
  printf("%f %d\n", result, -40);
  s21_remove_matrix(&A);
  return 0;
}

int s21_determinant(matrix_t *A, double *result) {
  int status = ok;
  if (valid_matrix(A)) {
    if (is_square_mx(A)) {
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
  } else {
    status = err_matrix;
  }
  return status;
}
