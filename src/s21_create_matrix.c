#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = 1, i = 0;
  result->matrix = NULL;
  if (check_pos(rows, columns)) {
    result->matrix = calloc(rows, sizeof(double *));
    if (NULL != result->matrix) {
      for (; i < rows; ++i) {
        result->matrix[i] = calloc(columns, sizeof(double));
      }
      result->rows = rows;
      result->columns = columns;
    }
  } else {
    status = 0;
  }

  return (status == 1) ? ok : err_matrix;
}

void s21_remove_matrix(matrix_t *A) {
  int i = 0;
  if (NULL != A->matrix) {
    for (; i < A->rows; ++i) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->rows = 0;
    A->columns = 0;
    A = NULL;
  }
}
