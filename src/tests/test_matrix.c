#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"
#define SUCCESS 1
#define FAILURE 0

#define OK 0
#define UNABLE 2

START_TEST(s21_create_matrix_1) {
  matrix_t t;
  int result = s21_create_matrix(-1, 2, &t);
  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  matrix_t t;
  int result = s21_create_matrix(1, -2, &t);
  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t t;
  int result = s21_create_matrix(-1, -2, &t);
  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  matrix_t t;
  int result = s21_create_matrix(1, 2, &t);
  s21_remove_matrix(&t);
  ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  matrix_t *t = NULL;
  int result = s21_create_matrix(1, 2, t);
  s21_remove_matrix(t);
  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(s21_eq_matrix_1) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;

  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 5;

  int result = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(SUCCESS, result);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.12345678;
  A.matrix[0][1] = 0.12345678;
  A.matrix[1][0] = 2.12345678;
  A.matrix[1][1] = 5.12345678;

  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1.12345679;
  B.matrix[0][1] = 0.12345679;
  B.matrix[1][0] = 2.12345679;
  B.matrix[1][1] = 5.12345679;

  int result = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(SUCCESS, result);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.12345678;
  A.matrix[0][1] = 0.12345678;
  A.matrix[1][0] = 2.12345678;
  A.matrix[1][1] = 5.12345678;

  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1.12245678;
  B.matrix[0][1] = 0.12245678;
  B.matrix[1][0] = 2.12245678;
  B.matrix[1][1] = 5.12245678;

  int result = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(FAILURE, result);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(2, 1, &A);
  A.matrix[0][0] = 1.12345678;
  A.matrix[1][0] = 2.12345678;

  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1.12245678;
  B.matrix[0][1] = 0.12245678;
  B.matrix[1][0] = 2.12245678;
  B.matrix[1][1] = 5.12245678;

  int result = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(FAILURE, result);
}
END_TEST

START_TEST(s21_sum_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;

  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 6;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;

  int result = s21_sum_matrix(&A, &B, &res);

  ck_assert_int_eq(7, res.matrix[0][0]);
  ck_assert_int_eq(0, res.matrix[0][1]);
  ck_assert_int_eq(4, res.matrix[1][0]);
  ck_assert_int_eq(8, res.matrix[1][1]);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 2, &B);

  int result = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;

  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 6;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;

  int result = s21_sub_matrix(&A, &B, &res);

  ck_assert_int_eq(-5, res.matrix[0][0]);
  ck_assert_int_eq(0, res.matrix[0][1]);
  ck_assert_int_eq(0, res.matrix[1][0]);
  ck_assert_int_eq(2, res.matrix[1][1]);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 2, &B);

  int result = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_1) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;

  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 6;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;

  int result = s21_mult_matrix(&A, &B, &res);

  ck_assert_int_eq(6, res.matrix[0][0]);
  ck_assert_int_eq(0, res.matrix[0][1]);
  ck_assert_int_eq(22, res.matrix[1][0]);
  ck_assert_int_eq(15, res.matrix[1][1]);
  ck_assert_int_eq(res.rows, 2);
  ck_assert_int_eq(res.columns, 2);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(1, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 9;

  s21_create_matrix(2, 3, &B);
  B.matrix[0][0] = 6;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 8;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 9;

  int result = s21_mult_matrix(&A, &B, &res);

  ck_assert_int_eq(24, res.matrix[0][0]);
  ck_assert_int_eq(27, res.matrix[0][1]);
  ck_assert_int_eq(89, res.matrix[0][2]);
  ck_assert_int_eq(res.rows, 1);
  ck_assert_int_eq(res.columns, 3);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(4, 3, &A);
  s21_create_matrix(2, 3, &B);
  int result = s21_mult_matrix(&A, &B, &res);
  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_number_1) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;

  int result = s21_mult_number(&A, 21, &res);

  ck_assert_int_eq(21, res.matrix[0][0]);
  ck_assert_int_eq(0, res.matrix[0][1]);
  ck_assert_int_eq(42, res.matrix[1][0]);
  ck_assert_int_eq(105, res.matrix[1][1]);
  ck_assert_int_eq(res.rows, 2);
  ck_assert_int_eq(res.columns, 2);

  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_transpose_1) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;

  int result = s21_transpose(&A, &res);

  ck_assert_int_eq(1, res.matrix[0][0]);
  ck_assert_int_eq(2, res.matrix[0][1]);
  ck_assert_int_eq(0, res.matrix[1][0]);
  ck_assert_int_eq(5, res.matrix[1][1]);
  ck_assert_int_eq(res.rows, 2);
  ck_assert_int_eq(res.columns, 2);

  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_transpose_2) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(3, 1, &A);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 0;
  A.matrix[2][0] = 2;

  int result = s21_transpose(&A, &res);

  ck_assert_int_eq(1, res.matrix[0][0]);
  ck_assert_int_eq(0, res.matrix[0][1]);
  ck_assert_int_eq(2, res.matrix[0][2]);
  ck_assert_int_eq(res.rows, 1);
  ck_assert_int_eq(res.columns, 3);

  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_determinant_1) {
  matrix_t A;
  double res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;

  int result = s21_determinant(&A, &res);

  ck_assert_int_eq(res, 5);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t A;
  double res;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 11;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = 17;
  A.matrix[2][2] = 11;

  int result = s21_determinant(&A, &res);

  ck_assert_int_eq(res, -34);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3) {
  matrix_t A;
  double res;
  s21_create_matrix(2, 1, &A);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 2;

  int result = s21_determinant(&A, &res);

  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_1) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  int result = s21_calc_complements(&A, &res);

  ck_assert_int_eq(4, res.matrix[0][0]);
  ck_assert_int_eq(-3, res.matrix[0][1]);
  ck_assert_int_eq(-2, res.matrix[1][0]);
  ck_assert_int_eq(1, res.matrix[1][1]);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  A.rows = -1;

  int result = s21_calc_complements(&A, &res);
  ck_assert_int_eq(result, 1);

  A.rows = 2;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(3, 2, &A);

  int result = s21_calc_complements(&A, &res);
  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_1) {
  matrix_t A;
  matrix_t res;
  matrix_t B;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 12;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1.0 / 11;
  B.matrix[0][1] = -(2.0 / 11);
  B.matrix[0][2] = 1.0 / 11;
  B.matrix[1][0] = -(2.0 / 11);
  B.matrix[1][1] = -(29.0 / 11);
  B.matrix[1][2] = 20.0 / 11;
  B.matrix[2][0] = 1.0 / 11;
  B.matrix[2][1] = 82.0 / 33;
  B.matrix[2][2] = -(52.0 / 33);

  int result = s21_inverse_matrix(&A, &res);
  int result_2 = s21_eq_matrix(&res, &B);

  ck_assert_int_eq(SUCCESS, result_2);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  int result = s21_inverse_matrix(&A, &res);
  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(4, 3, &A);
  A.rows = -2;

  int result = s21_inverse_matrix(&A, &res);
  ck_assert_int_eq(result, 1);

  A.rows = 4;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(4, 3, &A);

  int result = s21_inverse_matrix(&A, &res);
  ck_assert_int_eq(result, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_5) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5;

  int result = s21_inverse_matrix(&A, &res);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(res.matrix[0][0], 1.0 / 5);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_incorrect_add) {
  matrix_t A, B, C;
  s21_create_matrix(3, 4, &A);
  s21_create_matrix(4, 3, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &C), UNABLE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_incorrect_sub) {
  matrix_t A, B, C;
  s21_create_matrix(7, 4, &A);
  s21_create_matrix(4, 9, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &C), UNABLE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_incorrect_mul) {
  matrix_t A, B, C;
  s21_create_matrix(7, 4, &A);
  s21_create_matrix(11, 9, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), UNABLE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_incorrect_det) {
  matrix_t A;
  double d;
  s21_create_matrix(7, 4, &A);
  ck_assert_int_eq(s21_determinant(&A, &d), UNABLE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_incorrect_inverse) {
  matrix_t A, B;
  s21_create_matrix(7, 4, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &B), UNABLE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_zero_det) {
  matrix_t A;
  double d = 0;
  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 0.;
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &d), OK);
  ck_assert_int_eq(d, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_random_inverse) {
  matrix_t A, B, C, D;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &D);

  A.matrix[0][0] = 11;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == j)
        D.matrix[i][j] = 1;
      else
        D.matrix[i][j] = 0;
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &B), OK);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &C), OK);
  ck_assert_int_eq(s21_eq_matrix(&D, &C), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_create_matrix_1);
  tcase_add_test(tc1_1, s21_create_matrix_2);
  tcase_add_test(tc1_1, s21_create_matrix_3);
  tcase_add_test(tc1_1, s21_create_matrix_4);
  tcase_add_test(tc1_1, s21_create_matrix_5);
  tcase_add_test(tc1_1, s21_eq_matrix_1);
  tcase_add_test(tc1_1, s21_eq_matrix_2);
  tcase_add_test(tc1_1, s21_eq_matrix_3);
  tcase_add_test(tc1_1, s21_eq_matrix_4);
  tcase_add_test(tc1_1, s21_sum_matrix_1);
  tcase_add_test(tc1_1, s21_sum_matrix_2);
  tcase_add_test(tc1_1, s21_sub_matrix_1);
  tcase_add_test(tc1_1, s21_sub_matrix_2);
  tcase_add_test(tc1_1, s21_mult_matrix_1);
  tcase_add_test(tc1_1, s21_mult_matrix_2);
  tcase_add_test(tc1_1, s21_mult_matrix_3);
  tcase_add_test(tc1_1, s21_mult_number_1);
  tcase_add_test(tc1_1, s21_transpose_1);
  tcase_add_test(tc1_1, s21_transpose_2);
  tcase_add_test(tc1_1, s21_determinant_1);
  tcase_add_test(tc1_1, s21_determinant_2);
  tcase_add_test(tc1_1, s21_determinant_3);
  tcase_add_test(tc1_1, s21_calc_complements_1);
  tcase_add_test(tc1_1, s21_calc_complements_2);
  tcase_add_test(tc1_1, s21_calc_complements_3);
  tcase_add_test(tc1_1, s21_inverse_matrix_1);
  tcase_add_test(tc1_1, s21_inverse_matrix_2);
  tcase_add_test(tc1_1, s21_inverse_matrix_3);
  tcase_add_test(tc1_1, s21_inverse_matrix_4);
  tcase_add_test(tc1_1, s21_inverse_matrix_5);
  tcase_add_test(tc1_1, s21_zero_det);
  tcase_add_test(tc1_1, s21_incorrect_det);
  tcase_add_test(tc1_1, s21_incorrect_inverse);
  tcase_add_test(tc1_1, s21_incorrect_add);
  tcase_add_test(tc1_1, s21_incorrect_sub);
  tcase_add_test(tc1_1, s21_incorrect_mul);
  tcase_add_test(tc1_1, s21_random_inverse);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}