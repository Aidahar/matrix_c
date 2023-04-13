#include "s21_matrix.h"

int main(void) {
  matrix_t A = {0}, B = {0}, R = {0};
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = -3;
  A.matrix[0][1] = 4.2;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 5;
  B.matrix[1][1] = 6;
  status = s21_sum_matrix(&A, &B, &R);
  printf("status = %d, res = %d\n", status, 0);
  printf("matrix[0][0] = %d\n", (int)(R.matrix[0][0]));       // 0
  printf("matrix[0][1] = %d\n", (int)(R.matrix[0][1] * 10));  // 82
  printf("matrix[1][0] = %d\n", (int)(R.matrix[1][0]));       // 10
  printf("matrix[1][1] = %d\n", (int)(R.matrix[1][1]));       // 12
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = ok, idx = 0, jdx = 0;
  s21_create_matrix(A->rows, A->columns, result);
  if (!valid_matrix(A) || !valid_matrix(B) || !valid_matrix(result)) {
    status = err_matrix;
  } else if (!check_pos(A->rows, B->rows) ||
             !check_pos(A->columns, B->columns) ||
             !check_pos(result->rows, A->rows) ||
             !check_pos(result->columns, A->columns)) {
    status = err_matrix;
  } else {
    for (; idx < A->rows; ++idx) {
      for (; jdx < A->columns; ++jdx) {
        result->matrix[idx][jdx] = A->matrix[idx][jdx] + B->matrix[idx][jdx];
        printf("%f\n", result->matrix[idx][jdx]);
      }
    }
  }
  return status;
}