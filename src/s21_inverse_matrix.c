#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = 0;
  if ((result != NULL) && (A->rows > 0) && (A->columns > 0)) {
    if (A->rows == A->columns) {
      double det = 0;
      flag = s21_determinant(A, &det);
      if ((det != 0) && (!flag)) {
        s21_create_matrix(A->rows, A->columns, result);
        if (A->rows == 1) {
          (result->matrix)[0][0] == A->matrix[0][0];
        } else {
          matrix_t calc = {0};
          flag = s21_calc_complements(A, &calc);
          if (!flag) {
            matrix_t trans = {0};
            flag = s21_transpose(&calc, &trans);
            if (!flag) {
              flag = s21_mult_number(&trans, 1 / det, result);
            }
            s21_remove_matrix(&trans);
          }
          s21_remove_matrix(&calc);
        }
      } else {
        flag = 2;
      }
    } else {
      flag = 2;
    }
  } else {
    flag = 1;
  }
  return flag;
}