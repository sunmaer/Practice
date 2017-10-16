#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<malloc/malloc.h>
using namespace std;

typedef struct LKString { // 链串存储结构
  char ch;
  struct LKString *next;
} LKString, *LKStringList;

void Create_LKString(LKStringList &L, string s) { // 创建链串
  LKString *p,*r;
  L = (LKStringList)malloc(sizeof(LKString));
  r = L; // 尾结点
  for(int i=0; i<s.length(); i++) {
    p = (LKStringList)malloc(sizeof(LKString)); // 新结点
    p->ch = s[i];
    r->next = p; // 尾插法插入
    r = p;
  }
  r->next = NULL;
}

void Display_LKString(LKStringList L) { // 链串的显示
  LKStringList p; p=L;
  while(p->next) {
    printf("%c ", p->next->ch);
    p = p->next;
  }
}

LKString * StrIndex(LKStringList &s, LKStringList &t) {
  /* 求模式串 t 在主串 s 中第一次出现的位置指针 */
  
}

int main() {
  LKStringList s,t;
  string s1 = "hello world!",s2 = "hello";
  Create_LKString(s, s1); // 主串
  Create_LKString(t, s2); // 模式串
  Display_LKString(t);
  return 0;
}