#include "s21_matrix.h"

int valid_matrix(matrix_t *A) {
  int status = ok;
  if (NULL == A) status = err_matrix;
  return status;
}

int check_pos(int a, int b) {
  int status = 0;
  if (0 < a && 0 < b) {
    status = 1;
  }
  return status;
}