#include "s21_matrix.h"

int valid_matrix(matrix_t *A) {
  int status = 0;
  if (NULL != A) status = 1;
  return status;
}

int valid_number(double num) {
  int status = 0;
  if (NULL != num) status = 1;
  return status;
 }

int check_pos(int a, int b) {
  int status = 0;
  if (0 < a && 0 < b) {
    status = 1;
  }
  return status;
}

int eq_size(matrix_t *A, matrix_t *B) {
  int status = 0;
  if (A->rows == B->rows && A->columns == B->columns) status = 1;
  return status;
}