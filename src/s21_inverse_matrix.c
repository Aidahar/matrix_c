#include "s21_matrix.h"

// int main(void) {
//   matrix_t A = {0}, result = {0};
//   int status = 0;
//   s21_create_matrix(3, 3, &A);
//   A.matrix[0][0] = 2.38;
//   A.matrix[0][1] = 5.17;
//   A.matrix[0][2] = 7.26;
//   A.matrix[1][0] = 6.49;
//   A.matrix[1][1] = 3.55;
//   A.matrix[1][2] = 4.64;
//   A.matrix[2][0] = 5.73;
//   A.matrix[2][1] = -2.82;
//   A.matrix[2][2] = -3.94;
//   s21_inverse_matrix(&A, &result);
//   print_mx(&result);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&result);
//   return 0;
// }

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = ok;
  if (valid_matrix(A)) {
    if (is_square_mx(A)) {
      double det = 1;
      matrix_t A_cpy = {0};
      copy_mx(A, &A_cpy);
      s21_determinant(&A_cpy, &det);
      if (fabs(det) < 1e-60 || det != det) {
        status = err_calculate;
      } else {
        matrix_t comp = {0}, transpon = {0};
        s21_calc_complements(A, &comp);
        s21_transpose(&comp, &transpon);
        double koef = 1.0 / det;
        s21_mult_number(&transpon, koef, result);
        s21_remove_matrix(&transpon);
        s21_remove_matrix(&comp);
      }
      s21_remove_matrix(&A_cpy);
    } else {
      status = err_calculate;
    }
  } else {
    status = err_matrix;
  }
  return status;
}