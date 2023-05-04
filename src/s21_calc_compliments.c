#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = ok;
  if (valid_matrix(A)) {
    if (is_square_mx(A)) {
      s21_create_matrix(A->rows, A->columns, result);
      minor_mx(A, result);
    } else {
      status = err_calculate;
    }
  } else {
    status = err_matrix;
  }
  return status;
}
