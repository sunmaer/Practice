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
 * 采用按照被转置后矩阵三元组表A的列序递增的顺序进行转置，并依次送入转置后矩阵的三元组表B中，这样
 * 一来，转置后矩阵的三元组表B恰好是以“行序为主序”的
 */
void transMatrix(TSMatrix source, TSMatrix *dest) {
  dest->m = source.n;
  dest->n = source.m;
  dest->len = source.len;
  
  int k=0;
  if(dest->len > 0) {
    for(int i=0; i<source.n; i++) {
      for(int j=0; j<source.len; j++) {
        if(source.data[j].col == i) {
          dest->data[k].row = source.data[j].col;
          dest->data[k].col = source.data[j].row;
          dest->data[k].e = source.data[j].e;
          k++;
        }
      }
    }
  }
}

/**
 * 2) 一次定位快速转置法
 */ 
void FastTransposeTSMatrix(TSMatrix source, TSMatrix *dest) {
  int num[MAXSIZE]; // 原矩阵每一列的非零元素个数
  int position[MAXSIZE]; // 每一列第一个非零元素转置后在三元组表中的位置
  dest->m = source.n;
  dest->n = source.m;
  dest->len = source.len;
  
  if(dest->len > 0) {
    for(int i=0; i<source.n; i++) { // 初始化数组
      num[i] = 0;
    }

    for(int i=0; i<source.len; i++) {
      num[source.data[i].col]++;
    }

    position[0] = 1;
    for(int i=1; i<source.n; i++) {
      position[i] = position[i-1] + num[i-1];
    }

    for(int i=0; i<source.len; i++) {
      int col = source.data[i].col;
      int q = position[col];
      dest->data[q].row = source.data[i].col;
      dest->data[q].col = source.data[i].row;
      dest->data[q].e = source.data[i].e;
      position[col]++;
    }
  }
}

void display(TSMatrix m) { // 打印稀疏矩阵
  for(int i=0; i<m.m; i++) {
    for(int j=0; j<m.n; j++) {
      int flag = 0;
      for(int k=0; k<m.len; k++) {
        if((i+1) == m.data[k].row && (j+1) == m.data[k].col) {
          flag = 1;
          printf("%3d  ", m.data[k].e);
        }
      }
      if(!flag) {
        printf("%3d  ", 0);
      }
    }
    cout<<endl;
  }
}

int main() {
  TSMatrix source, dest;
  source.data[0] = (Triple){ 1, 2, 12 };
  source.data[1] = (Triple){ 1, 3, 9 };
  source.data[2] = (Triple){ 3, 1, -3 };
  source.data[3] = (Triple){ 3, 6, 14 };
  source.data[4] = (Triple){ 4, 3, 24 };
  source.data[5] = (Triple){ 5, 2, 18 };
  source.data[6] = (Triple){ 6, 1, 15 };
  source.data[7] = (Triple){ 6, 4, -7 };
  source.m = 6;
  source.n = 7;
  source.len = 8;

  cout<<"原矩阵："<<endl;
  display(source);

  // transMatrix(source, &dest);
  FastTransposeTSMatrix(source, &dest);
  cout<<endl<<"转置后矩阵："<<endl;
  display(dest);

  return 0;
}