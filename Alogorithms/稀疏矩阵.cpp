#include<iostream>
using namespace std;

void displayMatrix(int matrix[][7], int m, int n) { // 打印稀疏矩阵
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      printf("%3d  ", matrix[i][j]);
    }
    cout<<endl;
  }
}

int main() {
  int source[6][7] = {0, 12, 9, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,  -3, 0, 0, 0, 0, 14, 0,  0, 0, 24, 0, 0, 0, 0,  0, 18, 0, 0, 0, 0, 0,  15, 0, 0, -7, 0, 0, 0};
  displayMatrix(source, 6, 7);
  return 0;
}