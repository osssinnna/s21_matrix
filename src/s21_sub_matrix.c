#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {  // SUCCESS
  int flag;
  if (result != NULL) {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          (result->matrix)[i][j] = (A->matrix)[i][j] - (B->matrix)[i][j];
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