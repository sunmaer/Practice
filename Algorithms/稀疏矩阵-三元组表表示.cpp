#include<iostream>
using namespace std;

#define MAXSIZE 1000

typedef struct {
  int row, col; // 非零元素的行下标和列下标
  int e; // 非零元素的值
}Triple;

typedef struct {
  Triple data[MAXSIZE]; // 非零元素的三元组表
  int m, n, len; // 矩阵的行数、列数和非零元素的个数
}TSMatrix;

/**
 * 1) 列序递增转置法
 */
void transMatrix(int source[][7], int dest[][6]) {
  for(int i=0; i<6; i++) {
    for(int j=0; j<7; j++) {
      dest[j][i] = source[i][j];
    }
  }
}

void display(TSMatrix m) { // 打印稀疏矩阵
  
}

int main() {
  TSMatrix source, dest;
  source.data[0] = { 1, 2, 12 };
  source.data[1] = { 1, 3, 9 };
  source.data[2] = { 3, 1, -3 };
  source.data[3] = { 3, 6, 14 };
  source.data[4] = { 4, 3, 24 };
  source.data[5] = { 5, 2, 18 };
  source.data[6] = { 6, 1, 15 };
  source.data[7] = { 6, 4, -7 };
  source.m = 6;
  source.n = 7;
  source.len = 8;

  return 0;
}