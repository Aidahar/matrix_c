CFLAGS = -Wall -Wextra -Werror 
GCOV = -fprofile-arcs -ftest-coverage -fPIC
FILES = s21_create_matrix.c s21_eq_matrix.c s21_matrix_help.c s21_sum_matrix.c s21_sub_matrix.c s21_mult_number.c s21_mult_matrix.c s21_transpose.c s21_determinant.c s21_calc_compliments.c s21_inverse_matrix.c
OS = $(shell uname)

ifeq (${OS}, Linux)
	TEST_FLAGS = -lcheck -pthread -lrt -lm -L.
else
	TEST_FLAGS = -lcheck
endif

all: s21_matrix.a

gcov_report: test 
	lcov -t "matrix" -o matrix.info -c -d .
	genhtml -o report matrix.info

ifeq (${OS}, Linux)
	cd report && firefox index.html
else
	cd report && open index.html
endif

test: s21_matrix.a
	gcc s21_matrix_test.c -c
	gcc ${CFLAGS} ${TEST_FLAGS} ${GCOV} ${FILES} s21_matrix_test.o -o s21_matrix_test
	./s21_matrix_test

s21_matrix.a : s21_matrix.o
	ar rc libs21_matrix.a *.o
	ranlib libs21_matrix.a
	cp libs21_matrix.a s21_matrix.a

s21_matrix.o: ${FILES}
	gcc ${CFLAGS} -c ${FILES}

.PHONY: all build clean rebuild

clean:
	rm -rf *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno *.a s21_matrix_test *.css *.html vgcore* report *.info *.gz *.log test

rebuild: clean s21_matrix.a
