#include<iostream>
using namespace std;

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

int main() {
  int source[6][7] = {0, 12, 9, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,  -3, 0, 0, 0, 0, 14, 0,  0, 0, 24, 0, 0, 0, 0,  0, 18, 0, 0, 0, 0, 0,  15, 0, 0, -7, 0, 0, 0};
  int dest[7][6];
  
  cout<<"原矩阵："<<endl;
  for(int i=0; i<6; i++) { 
    for(int j=0; j<7; j++) {
      printf("%3d  ", source[i][j]);
    }
    cout<<endl;
  }

  transMatrix(source, dest);
  
  cout<<endl<<"转置后的矩阵："<<endl;
  for(int i=0; i<7; i++) {
    for(int j=0; j<6; j++) {
      printf("%3d  ", dest[i][j]);
    }
    cout<<endl;
  }

  return 0;
}