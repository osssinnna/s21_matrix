#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag;
  if ((result != NULL) && (rows > 0) && (columns > 0)) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(sizeof(double *) * result->rows);
    if (result->matrix != NULL) {
      for (int i = 0; i < result->rows; i++) {
        result->matrix[i] = (double *)calloc(result->columns, sizeof(double));
      }
      flag = 0;
    } else {
      flag = 1;
    }
  } else {
    flag = 1;
  }
  return flag;
}