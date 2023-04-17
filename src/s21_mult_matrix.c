#include "s21_matrix.h"

int main(void){

  int rows = 2, columns = 3, rows2 = 2, columns2 = 2;
  matrix_t A = {0}, B = {0}, R = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows2, columns2, &B);
  int status = s21_mult_matrix(&A, &B, &R);
  status = s21_mult_matrix(&A, &B, &R);
  printf("status %d\n", status);
  // printf("matrix[0][0] = %f need = %f\n", R.matrix[0][0], 9.0);
  // printf("matrix[0][0] = %f need = %f\n", R.matrix[0][1], 11.0);
  // printf("matrix[0][0] = %f need = %f\n", R.matrix[0][2], 17.0);
  // printf("matrix[0][0] = %f need = %f\n", R.matrix[1][0], 12.0);
  // printf("matrix[0][0] = %f need = %f\n", R.matrix[1][1], 13.0);
  // printf("matrix[0][0] = %f need = %f\n", R.matrix[1][2], 22.0);
  // printf("matrix[0][0] = %f need = %f\n", R.matrix[2][0], 15.0);
  // printf("matrix[0][0] = %f need = %f\n", R.matrix[2][1], 15.0);
  // printf("matrix[0][0] = %f need = %f\n", R.matrix[2][2], 27.0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
  int status = ok;
  if (valid_matrix(A) && valid_matrix(B)) {
    if (A->columns == B->rows) {
      if (!s21_create_matrix(A->rows, B->columns, result)){
        mul_matr(A, B, result);
      } else {
        status = err_matrix;
      }
    } else {
      status = err_calculate;
    }
  } else {
    status = err_matrix;
  }
  return status;
}

void mul_matr(matrix_t *A, matrix_t *B, matrix_t *result) {
  int idx, jdx, kdx;
  for (idx = 0; idx < A->rows; ++idx) {
    for (jdx = 0; jdx < B->columns; ++jdx) {
      for (kdx = 0; kdx < A->columns; ++kdx){
        result->matrix[idx][jdx] += A->matrix[idx][kdx] * B->matrix[kdx][jdx];
      }
    }
  }
}