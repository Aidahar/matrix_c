#include "s21_matrix.h"

// int main(void) {
//   int rows = 4, columns = 4, idx = 0, jdx = 0;
//   matrix_t A = {0}, B = {0};
//   s21_create_matrix(rows, columns, &A);
//   s21_create_matrix(rows, columns, &B);
//   for (; idx < rows; ++idx) {
//     for (; jdx < columns; ++jdx) {
//       double el = (double)idx + (double)jdx;
//       A.matrix[idx][jdx] = el;
//       B.matrix[idx][jdx] = el + 2;
//     }
//   }
//   int res = s21_eq_matrix(&A, &B);
//   printf("\nres = %d, fail = %d", res, FAILURE);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
//   return 0;
// }

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = 1;
  int i = 0, j = 0;
  if (NULL == A->matrix || NULL == B->matrix) {
    status = 0;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    status = 0;
  } else {
    for (; i < A->rows; ++i) {
      for (; j < A->columns; ++j) {
        if (fabs(A->matrix[i][j] - fabs(B->matrix[i][j])) > 1e-6) {
          status = 0;
          break;
        }
      }
    }
  }
  return (status == 1) ? SUCCESS : FAILURE;
}