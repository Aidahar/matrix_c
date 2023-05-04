#ifndef S21_MATRIX_H_
#define S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define EPS 0.000001

enum status { ok, err_matrix, err_calculate };

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Help functions
int check_pos(int a, int b);
int eq_size(matrix_t *A, matrix_t *B);
int valid_matrix(matrix_t *A);
void mul_matr(matrix_t *A, matrix_t *B, matrix_t *result);
int minor_mx(matrix_t *A, matrix_t *result);
int is_square_mx(matrix_t *mx);
void swap_rows(matrix_t *A, int pivot, int i);
void fill_mx(int i, int j, matrix_t *A, matrix_t *tmp);
void print_mx(matrix_t *A);
void square_mx(matrix_t *A, double *result);
int copy_mx(matrix_t *A, matrix_t *result);

int swap(matrix_t *A, int idx, int kdx, int col);
void det_calc(matrix_t *A, double **result, int cnt);
void gauss(matrix_t *A, int *cnt);
#endif  // S21_MATRIX_H