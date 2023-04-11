#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = 1;
  if (rows < 0 || columns < 0) {
    status = 0;
  } else {
    result->matrix =
        (double **)calloc((double)rows * (double)columns * (sizeof(double)));
    result->rows = rows;
    result->columns = columns;
  }
  return (status = 1) ? SUCCESS : FAILURE;
}