#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = 1;
  if (result) {
    if (check_pos(rows, columns)) {
      result->matrix = calloc(rows, sizeof(double *));
      int i;
      for (i = 0; i < rows; ++i) {
        result->matrix[i] = calloc(columns, sizeof(double));
        if (NULL == result->matrix[i]) {
          int j;
          for (j = 0; j < rows; ++j) {
            free(result->matrix[j]);
          }
          free(result);
          status = 0;
          break;
        }
      }
      result->rows = rows;
      result->columns = columns;
    } else {
      status = 0;
    }
  } else {
    status = 0;
  }

  return (status == 1) ? ok : err_matrix;
}

void s21_remove_matrix(matrix_t *A) {
  if (NULL != A->matrix) {
    int i = 0;
    for (; i < A->rows; ++i) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->rows = 0;
    A->columns = 0;
  }
}
