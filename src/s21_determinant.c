#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int flag;
  if (result != NULL) {
    if (A->rows == A->columns) {
      if ((A->rows) == 1) {
        *result = (A->matrix)[0][0];
      } else if ((A->rows) == 2) {
        *result = cross(A);
      } else {
        int i = 0;
        double slog;
        matrix_t dop_matrix;
        *result = 0;
        s21_create_matrix((A->rows) - 1, (A->columns) - 1, &dop_matrix);
        for (int j = 0; j < (A->columns); j++) {
          ponizh(A, &dop_matrix, i, j);
          s21_determinant(&dop_matrix, &slog);
          *result += (A->matrix)[i][j] * pow((-1), i + j) * slog;
        }
        s21_remove_matrix(&dop_matrix);
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