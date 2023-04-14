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
  ck_assert_int_eq((int)(R.matrix[0][0]), 0);
  ck_assert_int_eq((int)(R.matrix[0][1] * 10), 82);
  ck_assert_int_eq((int)(R.matrix[1][0]), 10);
  ck_assert_int_eq((int)(R.matrix[1][1]), 12);
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
  int rows = 2, columns = 2,rows1 = 4, columns1 = 4, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows1, columns1, &B);
  status = s21_sum_matrix(&A, &B, &R);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
END_TEST

//Sub matrix
START_TEST(s21_sub_matrix_fn) {
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
  status = s21_sub_matrix(&A, &B, &R);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq((int)(R.matrix[0][0]), -6);
  ck_assert_int_eq((int)(R.matrix[0][1] * 10), 2);
  ck_assert_int_eq((int)(R.matrix[1][0]), 0);
  ck_assert_int_eq((int)(R.matrix[1][1]), 0);
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
  int rows = 2, columns = 2,rows1 = 4, columns1 = 4, status = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows1, columns1, &B);
  status = s21_sub_matrix(&A, &B, &R);
  ck_assert_int_eq(status, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
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