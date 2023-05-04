#include "s21_matrix.h"

#include <check.h>
#include <stdlib.h>

// Create matrix
START_TEST(s21_create_matrix_fn) {
  int rows = 4, columns = 4;
  matrix_t A = {0};
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, ok);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_1_fn) {
  int rows = -1, columns = -1;
  matrix_t A = {0};
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, err_matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2_fn) {
  int rows = 0, columns = 0;
  matrix_t A = {0};
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, err_matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_3_fn) {
  int rows = 1, columns = 0;
  matrix_t A = {0};
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, err_matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_4_fn) {
  int rows = 0, columns = 1;
  matrix_t A = {0};
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, err_matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_5_fn) {
  int rows = 1, columns = 1;
  matrix_t A = {0};
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, ok);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_6_fn) {
  int rows = 25, cols = 5;
  int ret_val = s21_create_matrix(rows, cols, NULL);
  ck_assert_int_eq(ret_val, err_matrix);
}
END_TEST

// Equality matrix
START_TEST(s21_eq_matrix_fn) {
  int rows = 1, columns = 1, idx = 0, jdx = 0;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  int res = s21_eq_matrix(&A, &B);
  for (; idx < rows; ++idx) {
    for (; jdx < columns; ++jdx) {
      double el = (double)idx + (double)jdx;
      A.matrix[idx][jdx] = el;
      B.matrix[idx][jdx] = el;
    }
  }
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_1_fn) {
  int rows1 = 1, columns1 = 2;
  int rows2 = 2, columns2 = 1;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows1, columns1, &A);
  s21_create_matrix(rows2, columns2, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2_fn) {
  int rows1 = 2, columns1 = 1;
  int rows2 = 1, columns2 = 2;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows1, columns1, &A);
  s21_create_matrix(rows2, columns2, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_3_fn) {
  int rows1 = 2, columns1 = 2;
  int rows2 = 1, columns2 = 2;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows1, columns1, &A);
  s21_create_matrix(rows2, columns2, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_4_fn) {
  int rows1 = 2, columns1 = 1;
  int rows2 = 2, columns2 = 2;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows1, columns1, &A);
  s21_create_matrix(rows2, columns2, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_5_fn) {
  int rows = 1, columns = 1, idx = 0, jdx = 0;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (; idx < rows; ++idx) {
    for (; jdx < columns; ++jdx) {
      double el = (double)idx + (double)jdx;
      A.matrix[idx][jdx] = el;
      B.matrix[idx][jdx] = el;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_6_fn) {
  int rows = 1, columns = 1, idx = 0, jdx = 0;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (; idx < rows; ++idx) {
    for (; jdx < columns; ++jdx) {
      double el = (double)idx + (double)jdx;
      A.matrix[idx][jdx] = el + 1e8;
      B.matrix[idx][jdx] = el + 1e8;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_7_fn) {
  int rows = 1, columns = 1, idx = 0, jdx = 0;
  matrix_t A = {0}, B = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (; idx < rows; ++idx) {
    for (; jdx < columns; ++jdx) {
      double el = (double)idx + (double)jdx;
      A.matrix[idx][jdx] = el;
      B.matrix[idx][jdx] = el + 2.0;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_8_fn) {
  int rows1 = 1, columns1 = 2, idx = 0, jdx = 0;
  matrix_t A = {0};
  s21_create_matrix(rows1, columns1, &A);
  for (; idx < rows1; ++idx) {
    for (; jdx < columns1; ++jdx) {
      double el = (double)idx + (double)jdx;
      A.matrix[idx][jdx] = el;
    }
  }
  int res = s21_eq_matrix(&A, NULL);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_matrix_9_fn) {
  int rows1 = 1, columns1 = 2, idx = 0, jdx = 0;
  matrix_t B = {0};
  s21_create_matrix(rows1, columns1, &B);
  for (; idx < rows1; ++idx) {
    for (; jdx < columns1; ++jdx) {
      double el = (double)idx + (double)jdx;
      B.matrix[idx][jdx] = el;
    }
  }
  int res = s21_eq_matrix(NULL, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&B);
}
END_TEST

// Helper functions
START_TEST(s21_helper_fn) {
  int rows = 0, columns = 0;
  int res = check_pos(rows, columns);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_helper_1_fn) {
  int rows1 = 1, columns1 = 2, idx = 0, jdx = 0;
  matrix_t B = {0};
  s21_create_matrix(rows1, columns1, &B);
  for (; idx < rows1; ++idx) {
    for (; jdx < columns1; ++jdx) {
      double el = (double)idx + (double)jdx;
      B.matrix[idx][jdx] = el;
    }
  }
  int res = valid_matrix(&B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_helper_2_fn) {
  int res = valid_matrix(NULL);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_helper_3_fn) {
  int rows = 0, columns = 23;
  int res = check_pos(rows, columns);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_helper_4_fn) {
  int rows = 23, columns = -23;
  int res = check_pos(rows, columns);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_helper_5_fn) {
  int rows = 23, columns = 23;
  int res = check_pos(rows, columns);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_helper_6_fn) {
  int rows = -23, columns = 23;
  int res = check_pos(rows, columns);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_helper_7_fn) {
  matrix_t R = {0};
  int res = copy_mx(NULL, &R);
  ck_assert_int_eq(res, err_matrix);
}
END_TEST

// Sum matrix
START_TEST(s21_sum_matrix_fn) {
  matrix_t A = {0}, B = {0}, R = {0};
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = -3;
  A.matrix[0][1] = 4.2;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 5;
  B.matrix[1][1] = 6;
  status = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(R.matrix[0][0], 0, 0.0000001);
  ck_assert_double_eq_tol(R.matrix[0][1], 8.2, 0.0000001);
  ck_assert_double_eq_tol(R.matrix[1][0], 10, 0.0000001);
  ck_assert_double_eq_tol(R.matrix[1][1], 12, 0.0000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_sum_matrix_1_fn) {
  matrix_t A = {0}, R = {0};
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 123.33;
  A.matrix[0][1] = 4.2;
  A.matrix[1][0] = 4444;
  A.matrix[1][1] = 123.231;
  status = s21_sum_matrix(&A, NULL, &R);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_sum_matrix_2_fn) {
  matrix_t B = {0}, R = {0};
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 123.33;
  B.matrix[0][1] = 4.2;
  B.matrix[1][0] = 4444;
  B.matrix[1][1] = 123.231;
  status = s21_sum_matrix(NULL, &B, &R);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_sum_matrix_3_fn) {
  matrix_t A = {0}, B = {0}, R = {0};
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  status = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_sum_matrix_4_fn) {
  matrix_t A = {0}, B = {0}, R = {0};
  int rows = 2, columns = 2, rows1 = 4, columns1 = 4, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows1, columns1, &B);
  status = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

// Sub matrix
START_TEST(s21_sub_matrix_fn) {
  matrix_t A = {0}, B = {0}, R = {0};
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = -3;
  A.matrix[0][1] = 4.2;
  A.matrix[1][0] = 245.4;
  A.matrix[1][1] = 666.33;
  B.matrix[0][0] = 3.011;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 5;
  B.matrix[1][1] = 6;
  status = s21_sub_matrix(&A, &B, &R);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol((R.matrix[0][0]), -6.011, 0.000001);
  ck_assert_double_eq_tol((R.matrix[0][1]), 0.2, 0.000001);
  ck_assert_double_eq_tol((R.matrix[1][0]), 240.4, 0.000001);
  ck_assert_double_eq_tol((R.matrix[1][1]), 660.33, 0.000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_sub_matrix_1_fn) {
  matrix_t A = {0}, R = {0};
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 123.33;
  A.matrix[0][1] = 4.2;
  A.matrix[1][0] = 4444;
  A.matrix[1][1] = 123.231;
  status = s21_sum_matrix(&A, NULL, &R);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_sub_matrix_2_fn) {
  matrix_t B = {0}, R = {0};
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &B);
  B.matrix[0][0] = 123.33;
  B.matrix[0][1] = 4.2;
  B.matrix[1][0] = 4444;
  B.matrix[1][1] = 123.231;
  status = s21_sub_matrix(NULL, &B, &R);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_sub_matrix_3_fn) {
  matrix_t A = {0}, B = {0}, R = {0};
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  status = s21_sub_matrix(&A, &B, &R);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_sub_matrix_4_fn) {
  matrix_t A = {0}, B = {0}, R = {0};
  int rows = 2, columns = 2, rows1 = 4, columns1 = 4, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows1, columns1, &B);
  status = s21_sub_matrix(&A, &B, &R);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

// Multiply by number
START_TEST(s21_mul_num_fn) {
  matrix_t A = {0}, R = {0};
  int rows = 2, columns = 2, status = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 123.33;
  A.matrix[0][1] = 4.2;
  A.matrix[1][0] = 444.4;
  A.matrix[1][1] = 123.231;
  status = s21_mult_number(&A, 2, &R);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(R.matrix[0][0], 246.66, 0.000001);
  ck_assert_double_eq_tol(R.matrix[0][1], 8.4, 0.000001);
  ck_assert_double_eq_tol(R.matrix[1][0], 888.8, 0.000001);
  ck_assert_double_eq_tol(R.matrix[1][1], 246.462, 0.000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_mul_num_1_fn) {
  matrix_t R = {0};
  int status = s21_mult_number(NULL, 2, &R);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&R);
}
END_TEST

// Multiply matrix
START_TEST(s21_mul_matrix_fn) {
  int status = 0, rows = 3, columns = 2, rows2 = 2, columns2 = 3;
  matrix_t A = {0}, B = {0}, R = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows2, columns2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;
  status = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(R.matrix[0][0], 9, 0.000001);
  ck_assert_double_eq_tol(R.matrix[0][1], 11, 0.000001);
  ck_assert_double_eq_tol(R.matrix[0][2], 17, 0.000001);
  ck_assert_double_eq_tol(R.matrix[1][0], 12, 0.000001);
  ck_assert_double_eq_tol(R.matrix[1][1], 13, 0.000001);
  ck_assert_double_eq_tol(R.matrix[1][2], 22, 0.000001);
  ck_assert_double_eq_tol(R.matrix[2][0], 15, 0.000001);
  ck_assert_double_eq_tol(R.matrix[2][1], 15, 0.000001);
  ck_assert_double_eq_tol(R.matrix[2][2], 27, 0.000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_mul_matrix_1_fn) {
  int rows = 2, columns = 3, rows2 = 2, columns2 = 2;
  matrix_t A = {0}, B = {0}, R = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows2, columns2, &B);
  int status = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_mul_matrix_2_fn) {
  int rows = 2, columns = 3, rows2 = 1, columns2 = 1;
  matrix_t A = {0}, B = {0}, R = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows2, columns2, &B);
  int status = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_mul_matrix_3_fn) {
  int rows = 2, columns = 3, rows2 = 5, columns2 = 5;
  matrix_t A = {0}, B = {0}, R = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows2, columns2, &B);
  int status = s21_mult_matrix(&A, &B, &R);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_mul_matrix_4_fn) {
  int rows = 2, columns = 2;
  matrix_t A = {0}, R = {0};
  s21_create_matrix(rows, columns, &A);
  int status = s21_mult_matrix(&A, NULL, &R);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_mul_matrix_5_fn) {
  matrix_t B = {0}, R = {0};
  s21_create_matrix(2, 2, &B);
  int status = s21_mult_matrix(NULL, &B, &R);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

// Transpose matrix
START_TEST(s21_transpose_fn) {
  matrix_t A = {0}, R = {0};
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  int status = s21_transpose(&A, &R);
  ck_assert_int_eq(status, 0);
  ck_assert_double_eq_tol(R.matrix[0][0], 1, 0.000001);
  ck_assert_double_eq_tol(R.matrix[0][1], 2, 0.000001);
  ck_assert_double_eq_tol(R.matrix[0][2], 3, 0.000001);
  ck_assert_double_eq_tol(R.matrix[1][0], 4, 0.000001);
  ck_assert_double_eq_tol(R.matrix[1][1], 5, 0.000001);
  ck_assert_double_eq_tol(R.matrix[1][2], 6, 0.000001);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_transpose_1_fn) {
  matrix_t R = {0};
  int status = s21_transpose(NULL, &R);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(s21_transpose_2_fn) {
  int rows = 3, columns = 2;
  matrix_t A = {0}, check = {0}, result = {0};
  int ret_val = 0;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &check);

  A.matrix[0][0] = 8975.678;
  A.matrix[0][1] = 4.5124231241;
  A.matrix[1][0] = 0.80989999;
  A.matrix[1][1] = -5.412541232123;
  A.matrix[2][0] = 7878.889999999;
  A.matrix[2][1] = 4123;

  check.matrix[0][0] = 8975.678;
  check.matrix[0][1] = 0.80989999;
  check.matrix[0][2] = 7878.889999999;
  check.matrix[1][0] = 4.5124231241;
  check.matrix[1][1] = -5.412541232123;
  check.matrix[1][2] = 4123;

  s21_transpose(&A, &result);
  ret_val = s21_eq_matrix(&check, &result);
  ck_assert_int_eq(ret_val, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// Determinant
START_TEST(s21_determinant_fn) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  double result = 0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, ok);
  ck_assert_int_eq(result, -40);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_1_fn) {
  matrix_t A = {0};
  double result = 0;
  int ret_val = s21_determinant(&A, &result);
  ck_assert_int_eq(ret_val, err_matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_2_fn) {
  matrix_t A = {0};
  s21_create_matrix(3, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = 3;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 2;
  double result = 0;
  int ret_val = s21_determinant(&A, &result);
  ck_assert_int_eq(ret_val, err_calculate);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3_fn) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  double result = 0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, ok);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
}
END_TEST
START_TEST(s21_determinant_4_fn) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 3;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = -1;
  double result = 0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, ok);
  ck_assert_int_eq(result, -5);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_5_fn) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result = 0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, ok);
  ck_assert_int_eq(result, -4);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_6_fn) {
  matrix_t A = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 8;
  A.matrix[0][3] = 7;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 4;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  A.matrix[2][3] = 3;
  A.matrix[3][0] = 1;
  A.matrix[3][1] = 1;
  A.matrix[3][2] = 2;
  A.matrix[3][3] = 0;
  double result = 0;
  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, ok);
  ck_assert_int_eq(result, -308);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_7_fn) {
  matrix_t A = {0};
  double result = 0;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = -2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = -7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  s21_determinant(&A, &result);

  ck_assert_double_eq(result, 204);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_8_fn) {
  matrix_t A = {0};
  double result = 0;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 0.448;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[0][3] = 7;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 1;
  A.matrix[1][3] = 8.8;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 2;
  A.matrix[2][3] = 6;
  A.matrix[3][0] = 1;
  A.matrix[3][1] = 7.33;
  A.matrix[3][2] = 4.4;
  A.matrix[3][3] = 0;
  s21_determinant(&A, &result);
  ck_assert_double_eq_tol(result, -103.329184, 7);
  s21_remove_matrix(&A);
}
END_TEST

// Calc_compliments
START_TEST(s21_calc_complements_fn) {
  matrix_t A = {0}, check = {0}, result = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  check.matrix[0][0] = 0;
  check.matrix[0][1] = 10;
  check.matrix[0][2] = -20;
  check.matrix[1][0] = 4;
  check.matrix[1][1] = -14;
  check.matrix[1][2] = 8;
  check.matrix[2][0] = -8;
  check.matrix[2][1] = -2;
  check.matrix[2][2] = 4;

  int ret_val = s21_calc_complements(&A, &result);
  ck_assert_int_eq(ret_val, ok);
  int eq = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_1_fn) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(3, 5, &A);
  int ret_val = s21_calc_complements(&A, &result);
  ck_assert_int_eq(ret_val, err_calculate);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_2_fn) {
  matrix_t A = {0}, result = {0};
  A.rows = -3, A.columns = 5;
  int ret_val = s21_calc_complements(&A, &result);
  ck_assert_int_eq(ret_val, err_matrix);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_3_fn) {
  matrix_t A = {0}, result = {0};
  int ret_val = s21_calc_complements(&A, &result);
  ck_assert_int_eq(ret_val, err_matrix);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_4_fn) {
  matrix_t A = {0}, check = {0}, result = {0};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &check);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 15;
  A.matrix[0][3] = 9;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 8;
  A.matrix[1][2] = 8;
  A.matrix[1][3] = 9;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 7;
  A.matrix[2][3] = 6;
  A.matrix[3][0] = 4;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 2;
  A.matrix[3][3] = 2;

  check.matrix[0][0] = -13;
  check.matrix[0][1] = 36;
  check.matrix[0][2] = -3;
  check.matrix[0][3] = -25;
  check.matrix[1][0] = 13;
  check.matrix[1][1] = 4;
  check.matrix[1][2] = 43;
  check.matrix[1][3] = -75;
  check.matrix[2][0] = 91;
  check.matrix[2][1] = -212;
  check.matrix[2][2] = -199;
  check.matrix[2][3] = 335;
  check.matrix[3][0] = -273;
  check.matrix[3][1] = 456;
  check.matrix[3][2] = 417;
  check.matrix[3][3] = -685;

  int ret_val = s21_calc_complements(&A, &result);
  ck_assert_int_eq(ret_val, ok);
  int eq = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_5_fn) {
  matrix_t A = {0}, check = {0}, result = {0};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &check);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 15;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 9;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = 2;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 9;
  A.matrix[2][3] = 9;
  A.matrix[3][0] = -1;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 3;
  A.matrix[3][3] = 2;

  check.matrix[0][0] = -6;
  check.matrix[0][1] = 92;
  check.matrix[0][2] = -222;
  check.matrix[0][3] = 192;
  check.matrix[1][0] = 234;
  check.matrix[1][1] = 48;
  check.matrix[1][2] = 174;
  check.matrix[1][3] = -216;
  check.matrix[2][0] = 66;
  check.matrix[2][1] = -204;
  check.matrix[2][2] = 18;
  check.matrix[2][3] = 312;
  check.matrix[3][0] = -504;
  check.matrix[3][1] = 456;
  check.matrix[3][2] = 744;
  check.matrix[3][3] = -840;

  int ret_val = s21_calc_complements(&A, &result);
  ck_assert_int_eq(ret_val, ok);
  int eq = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_6_fn) {
  matrix_t result = {0};
  int ret_val = s21_calc_complements(NULL, &result);
  ck_assert_int_eq(ret_val, err_matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_7_fn) {
  matrix_t A = {0}, check = {0}, result = {0};
  int ret_val = 0;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  check.matrix[0][0] = 0;
  check.matrix[0][1] = 10;
  check.matrix[0][2] = -20;
  check.matrix[1][0] = 4;
  check.matrix[1][1] = -14;
  check.matrix[1][2] = 8;
  check.matrix[2][0] = -8;
  check.matrix[2][1] = -2;
  check.matrix[2][2] = 4;

  ret_val = s21_calc_complements(&A, &result);
  ck_assert_int_eq(ret_val, 0);
  ret_val = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(ret_val, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_8_fn) {
  matrix_t A = {0}, check = {0}, result = {0};
  int ret_val = 0;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &check);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 0;

  check.matrix[0][0] = 0;
  check.matrix[0][1] = -3;
  check.matrix[1][0] = -2;
  check.matrix[1][1] = 1;

  ret_val = s21_calc_complements(&A, &result);
  ck_assert_int_eq(ret_val, ok);
  ret_val = s21_eq_matrix(&check, &result);
  ck_assert_int_eq(ret_val, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_9_fn) {
  matrix_t A = {0}, check = {0}, result = {0};
  int ret_val = 0;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &check);

  A.matrix[0][0] = -56;
  check.matrix[0][0] = -56;
  ret_val = s21_calc_complements(&A, &result);
  ck_assert_int_eq(ret_val, ok);
  ret_val = s21_eq_matrix(&check, &result);
  ck_assert_int_eq(ret_val, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// Inverse matrix
START_TEST(s21_inverse_fn) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 4;
  A.matrix[0][3] = 8;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 3;
  A.matrix[1][3] = 9;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 2;
  A.matrix[2][3] = 2;
  A.matrix[3][0] = 3;
  A.matrix[3][1] = 6;
  A.matrix[3][2] = 6;
  A.matrix[3][3] = 3;

  int ret_val = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(ret_val, err_calculate);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_1_fn) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = -38;
  B.matrix[1][1] = 41;
  B.matrix[1][2] = -34;
  B.matrix[2][0] = 27;
  B.matrix[2][1] = -29;
  B.matrix[2][2] = 24;

  int ret_val = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(ret_val, ok);
  int eq = s21_eq_matrix(&result, &B);
  ck_assert_int_eq(eq, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_2_fn) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(3, 4, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int ret_val = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(ret_val, err_calculate);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_3_fn) {
  matrix_t result = {0};

  int ret_val = s21_inverse_matrix(NULL, &result);
  ck_assert_int_eq(ret_val, err_matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_4_fn) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = 2.38;
  A.matrix[0][1] = 5.17;
  A.matrix[0][2] = 7.26;
  A.matrix[1][0] = 6.49;
  A.matrix[1][1] = 3.55;
  A.matrix[1][2] = 4.64;
  A.matrix[2][0] = 5.73;
  A.matrix[2][1] = -2.82;
  A.matrix[2][2] = -3.94;

  B.matrix[0][0] = 0.069178;
  B.matrix[0][1] = 0.007928;
  B.matrix[0][2] = 0.136807;
  B.matrix[1][0] = -3.999289;
  B.matrix[1][1] = 3.908749;
  B.matrix[1][2] = -2.766051;
  B.matrix[2][0] = 2.963042;
  B.matrix[2][1] = -2.786102;
  B.matrix[2][2] = 1.924915;
  int ret_val = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(ret_val, ok);
  int eq = s21_eq_matrix(&result, &B);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_5_fn) {
  matrix_t A = {0}, check = {0}, result = {0};
  int ret_val = 0;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &check);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;

  check.matrix[0][0] = -1 / 8.0f;
  check.matrix[0][1] = 5 / 24.0f;
  check.matrix[1][0] = 1 / 4.0f;
  check.matrix[1][1] = -1 / 12.0f;
  ret_val = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(ret_val, 0);
  ret_val = s21_eq_matrix(&check, &result);
  ck_assert_int_eq(ret_val, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_matrix_suit(void) {
  Suite *s;
  s = suite_create("Matrix functions");

  TCase *tc_create = tcase_create("s21_create");
  suite_add_tcase(s, tc_create);
  tcase_add_test(tc_create, s21_create_matrix_fn);
  tcase_add_test(tc_create, s21_create_matrix_1_fn);
  tcase_add_test(tc_create, s21_create_matrix_2_fn);
  tcase_add_test(tc_create, s21_create_matrix_3_fn);
  tcase_add_test(tc_create, s21_create_matrix_4_fn);
  tcase_add_test(tc_create, s21_create_matrix_5_fn);
  tcase_add_test(tc_create, s21_create_matrix_6_fn);

  TCase *tc_eq = tcase_create("s21_eq");
  suite_add_tcase(s, tc_eq);
  tcase_add_test(tc_eq, s21_eq_matrix_fn);
  tcase_add_test(tc_eq, s21_eq_matrix_1_fn);
  tcase_add_test(tc_eq, s21_eq_matrix_2_fn);
  tcase_add_test(tc_eq, s21_eq_matrix_3_fn);
  tcase_add_test(tc_eq, s21_eq_matrix_4_fn);
  tcase_add_test(tc_eq, s21_eq_matrix_5_fn);
  tcase_add_test(tc_eq, s21_eq_matrix_6_fn);
  tcase_add_test(tc_eq, s21_eq_matrix_7_fn);
  tcase_add_test(tc_eq, s21_eq_matrix_8_fn);
  tcase_add_test(tc_eq, s21_eq_matrix_9_fn);

  TCase *tc_help = tcase_create("s21_helper");
  suite_add_tcase(s, tc_help);
  tcase_add_test(tc_help, s21_helper_fn);
  tcase_add_test(tc_help, s21_helper_1_fn);
  tcase_add_test(tc_help, s21_helper_2_fn);
  tcase_add_test(tc_help, s21_helper_3_fn);
  tcase_add_test(tc_help, s21_helper_4_fn);
  tcase_add_test(tc_help, s21_helper_5_fn);
  tcase_add_test(tc_help, s21_helper_6_fn);
  tcase_add_test(tc_help, s21_helper_7_fn);

  TCase *tc_sum = tcase_create("s21_sum");
  suite_add_tcase(s, tc_sum);
  tcase_add_test(tc_sum, s21_sum_matrix_fn);
  tcase_add_test(tc_sum, s21_sum_matrix_1_fn);
  tcase_add_test(tc_sum, s21_sum_matrix_2_fn);
  tcase_add_test(tc_sum, s21_sum_matrix_3_fn);
  tcase_add_test(tc_sum, s21_sum_matrix_4_fn);

  TCase *tc_sub = tcase_create("s21_sub");
  suite_add_tcase(s, tc_sub);
  tcase_add_test(tc_sub, s21_sub_matrix_fn);
  tcase_add_test(tc_sub, s21_sub_matrix_1_fn);
  tcase_add_test(tc_sub, s21_sub_matrix_2_fn);
  tcase_add_test(tc_sub, s21_sub_matrix_3_fn);
  tcase_add_test(tc_sub, s21_sub_matrix_4_fn);

  TCase *tc_mul_num = tcase_create("s21_mul_num");
  suite_add_tcase(s, tc_mul_num);
  tcase_add_test(tc_sub, s21_mul_num_fn);
  tcase_add_test(tc_sub, s21_mul_num_1_fn);

  TCase *tc_mul_matrix = tcase_create("s21_mul_matrix");
  suite_add_tcase(s, tc_mul_matrix);
  tcase_add_test(tc_sub, s21_mul_matrix_fn);
  tcase_add_test(tc_sub, s21_mul_matrix_1_fn);
  tcase_add_test(tc_sub, s21_mul_matrix_2_fn);
  tcase_add_test(tc_sub, s21_mul_matrix_3_fn);
  tcase_add_test(tc_sub, s21_mul_matrix_4_fn);

  TCase *tc_trans = tcase_create("s21_transpose");
  suite_add_tcase(s, tc_trans);
  tcase_add_test(tc_trans, s21_transpose_fn);
  tcase_add_test(tc_trans, s21_transpose_1_fn);
  tcase_add_test(tc_trans, s21_transpose_2_fn);

  TCase *tc_det = tcase_create("s21_determinant");
  suite_add_tcase(s, tc_det);
  tcase_add_test(tc_det, s21_determinant_fn);
  tcase_add_test(tc_det, s21_determinant_1_fn);
  tcase_add_test(tc_det, s21_determinant_2_fn);
  tcase_add_test(tc_det, s21_determinant_3_fn);
  tcase_add_test(tc_det, s21_determinant_4_fn);
  tcase_add_test(tc_det, s21_determinant_5_fn);
  tcase_add_test(tc_det, s21_determinant_6_fn);
  tcase_add_test(tc_det, s21_determinant_7_fn);
  tcase_add_test(tc_det, s21_determinant_8_fn);

  TCase *tc_calc = tcase_create("s21_calc_compliments");
  suite_add_tcase(s, tc_calc);
  tcase_add_test(tc_calc, s21_calc_complements_fn);
  tcase_add_test(tc_calc, s21_calc_complements_1_fn);
  tcase_add_test(tc_calc, s21_calc_complements_2_fn);
  tcase_add_test(tc_calc, s21_calc_complements_3_fn);
  tcase_add_test(tc_calc, s21_calc_complements_4_fn);
  tcase_add_test(tc_calc, s21_calc_complements_5_fn);
  tcase_add_test(tc_calc, s21_calc_complements_6_fn);
  tcase_add_test(tc_calc, s21_calc_complements_7_fn);
  tcase_add_test(tc_calc, s21_calc_complements_8_fn);
  tcase_add_test(tc_calc, s21_calc_complements_9_fn);

  TCase *tc_inv = tcase_create("s21_inverse");
  suite_add_tcase(s, tc_inv);
  tcase_add_test(tc_inv, s21_inverse_fn);
  tcase_add_test(tc_inv, s21_inverse_1_fn);
  tcase_add_test(tc_inv, s21_inverse_2_fn);
  tcase_add_test(tc_inv, s21_inverse_3_fn);
  tcase_add_test(tc_inv, s21_inverse_4_fn);
  tcase_add_test(tc_inv, s21_inverse_5_fn);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_matrix_suit();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (0 == number_failed) ? EXIT_SUCCESS : EXIT_FAILURE;
}