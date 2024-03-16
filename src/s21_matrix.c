#include "s21_matrix.h"

// void print_matrix(matrix_t* m) {
//     for(int x = 0; x < m->rows; x++) {
//         for(int y = 0; y < m->columns; y++) {
//             printf("%lf\t", m->matrix[x][y]);
//         }
//         printf("\n");
//     }
//     printf("\n");
// }
// void num_matrix(matrix_t* m) {
//     double num;
//     for(int i = 0; i < m->rows; i++) {
//         for(int j = 0; j < m->columns; j++) {
//             printf("x[%d][%d] = ", i, j);
//             scanf("%lf", &num);
//             printf("\n");
//             m->matrix[i][j] = num;
//         }
//     }
// }
int cross(matrix_t *A) {  // 2 × 2
  double opr;
  opr = (A->matrix)[0][0] * (A->matrix)[1][1] -
        (A->matrix)[0][1] * (A->matrix)[1][0];
  return opr;
}
void ponizh(matrix_t *A, matrix_t *result, int x,
            int y) {  // ponizhaem stepen' matrix
  int i, j, k, m;
  k = 0;
  for (i = 0; i < (result->rows); i++) {
    if (i == x) {
      k = 1;
    }
    m = 0;
    for (j = 0; j < (result->rows); j++) {
      if (j == y) {
        m = 1;
      }
      (result->matrix)[i][j] = (A->matrix)[i + k][j + m];
    }
  }
}

// int main() {
//     matrix_t my_matrix, trans;
//     printf("Матрица А\n");
//     printf("Введите количество строк:");
//     scanf("%d", &(my_matrix.rows));
//     printf("Введите количество столбцов:");
//     scanf("%d", &(my_matrix.columns));
//    // double num;

//     int r = s21_create_matrix(my_matrix.rows, my_matrix.columns, &my_matrix);

//     //num_matrix(&my_matrix);
//     // print_matrix(&my_matrix);
//     // s21_transpose(&my_matrix, &trans);
//     // print_matrix(&trans);
//     // print_matrix(&my_matrix);

//     // printf("Матрица B\n");
//     // matrix_t matr_b;
//     // printf("Введите количество строк:");
//     // scanf("%d", &(matr_b.rows));
//     // printf("Введите количество столбцов:");
//     // scanf("%d", &(matr_b.columns));
//     // s21_create_matrix(matr_b.rows, matr_b.columns, &matr_b);
//     // printf("Введите значения для матрицы В:\n");
//     // num_matrix(&matr_b);

//     // // int equal;
//     // // equal = s21_eq_matrix(&my_matrix, &matr_b);
//     // printf("Вывод матрицы А:\n");
//     // print_matrix(&my_matrix);
//     // printf("\n");
//     // printf("Вывод матрицы B:\n");
//     // print_matrix(&matr_b);
//     // // printf("\nРавенство: %d\n", equal);

//     // //s21_remove_matrix(&my_matrix);
//     // // s21_sum_matrix(&my_matrix, &matr_b, &my_matrix);
//     // // printf("Вывод матрицы А после суммы:\n");
//     // // print_matrix(&my_matrix);

//     // // s21_sub_matrix(&my_matrix, &matr_b, &my_matrix);
//     // // printf("Вывод матрицы А после разности:\n");
//     // // print_matrix(&my_matrix);
//     // // double number;
//     // // printf("Введите число для умножения: ");
//     // // scanf("%lf", &number);

//     // // s21_mult_number(&my_matrix, number, &my_matrix);
//     // // printf("\nВывод матрицы А после умножения на число:\n");
//     // // print_matrix(&my_matrix);
//     // matrix_t matr_c;
//     // printf("Матрица C\n");
//     // printf("Введите количество строк:");
//     // scanf("%d", &(matr_c.rows));
//     // printf("Введите количество столбцов:");
//     // scanf("%d", &(matr_c.columns));

//     // s21_create_matrix(matr_c.rows, matr_c.columns, &matr_c);

//     // s21_mult_matrix(&my_matrix, &matr_b, &matr_c);
//     // printf("Вывод матрицы C:\n");
//     // print_matrix(&matr_c);
//     // matrix_t res;
//     // s21_inverse_matrix(&my_matrix, &res);
//     // print_matrix(&res);
//     // double determ;
//     // s21_determinant(&my_matrix, &determ);
//     // printf("%lf", determ);
//     s21_remove_matrix(&my_matrix);
//     return 0;
// }
