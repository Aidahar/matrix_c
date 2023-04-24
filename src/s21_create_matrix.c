#include "s21_matrix.h"

// int main(void) {
//   int rows = -1, columns = -1;
//   matrix_t A = {0};
//   int res = s21_create_matrix(rows, columns, &A);
//   printf("%d %d\n", res, err_matrix);
//   s21_remove_matrix(&A);
//   return 0;
// }

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
