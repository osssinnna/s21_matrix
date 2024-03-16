#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag;
  if ((result != NULL) && (A->rows > 0) && (A->columns > 0)) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      double det;
      matrix_t dop_matrix;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          s21_create_matrix((A->rows) - 1, (A->columns) - 1, &dop_matrix);
          ponizh(A, &dop_matrix, i, j);
          s21_determinant(&dop_matrix, &det);
          (result->matrix)[i][j] = pow((-1), i + j) * det;
          s21_remove_matrix(&dop_matrix);
        }
      }
      flag = 0;
    } else {
      flag = 2;
    }
  } else {
    flag = 1;
  }
  return flag;
}