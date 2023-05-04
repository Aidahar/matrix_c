#include "s21_matrix.h"

// int main(void) {
<<<<<<< HEAD
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
=======
//   matrix_t A = {0}, B = {0}, result = {0};
//   s21_create_matrix(3, 3, &A);
//   s21_create_matrix(3, 3, &B);

//   A.matrix[0][0] = 2;
//   A.matrix[0][1] = 5;
//   A.matrix[0][2] = 7;
//   A.matrix[1][0] = 6;
//   A.matrix[1][1] = 3;
//   A.matrix[1][2] = 4;
//   A.matrix[2][0] = 5;
//   A.matrix[2][1] = -2;
//   A.matrix[2][2] = -3;

//   B.matrix[0][0] = 1;
//   B.matrix[0][1] = -1;
//   B.matrix[0][2] = 1;
//   B.matrix[1][0] = -38;
//   B.matrix[1][1] = 41;
//   B.matrix[1][2] = -34;
//   B.matrix[2][0] = 27;
//   B.matrix[2][1] = -29;
//   B.matrix[2][2] = 24;
//   int ret_val = s21_inverse_matrix(&A, &result);
//   printf("%d %d\n", ret_val, ok);
//   int eq = s21_eq_matrix(&result, &B);
//   printf("%d %d\n", eq, SUCCESS);

//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
>>>>>>> 1604a728220b156ccdba76b1b282301c5faea5d3
//   s21_remove_matrix(&result);
//   return 0;
// }

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = ok;
<<<<<<< HEAD
=======

>>>>>>> 1604a728220b156ccdba76b1b282301c5faea5d3
  if (valid_matrix(A)) {
    if (is_square_mx(A)) {
      double det = 1;
      matrix_t A_cpy = {0};
      copy_mx(A, &A_cpy);
      s21_determinant(&A_cpy, &det);
<<<<<<< HEAD
      if (fabs(det) < 1e-60 || det != det) {
        status = err_calculate;
      } else {
=======
      if (det != 0) {
>>>>>>> 1604a728220b156ccdba76b1b282301c5faea5d3
        matrix_t comp = {0}, transpon = {0};
        s21_calc_complements(A, &comp);
        s21_transpose(&comp, &transpon);
        double koef = 1.0 / det;
        s21_mult_number(&transpon, koef, result);
        s21_remove_matrix(&transpon);
        s21_remove_matrix(&comp);
<<<<<<< HEAD
=======
      } else {
        status = err_calculate;
>>>>>>> 1604a728220b156ccdba76b1b282301c5faea5d3
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