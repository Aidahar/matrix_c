#include "s21_matrix.h"

int valid_matrix(matrix_t *A) {
  return (A && check_pos(A->rows, A->rows)) ? 1 : 0;
}

int check_pos(int a, int b) { return (a > 0 && b > 0) ? 1 : 0; }

int eq_size(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns) ? 1 : 0;
}

int is_square_mx(matrix_t *mx) { return (mx->rows == mx->columns) ? 1 : 0; }