#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 255
typedef struct BiNode
{
  char data;
  struct BiNode *lchild;
  struct BiNode *rchild;
}BiTree;

BiTree *CreateBiTreepre(char *str) // 创建二叉树
{
  BiTree *bt, *stack[MAXSIZE], *p=NULL;
  int top=-1, k, j=0;
  char ch;
  bt=NULL;
  ch=str[j];
  while(ch != '\0') {
    switch(ch)
    {
      case '(': { top++; stack[top] = p; k=1; break; }
      case ')': { top--; break; }
      case ',': { k=2; break; }
      default:
      {
        p=(BiTree *)malloc(sizeof(BiTree));
        p->data=ch; p->lchild=p->rchild=NULL;
        if(bt==NULL) bt=p;
        else {
          switch(k) {
            case 1: stack[top]->lchild = p; break;
            case 2: stack[top]->rchild = p; break;
          }
        }
      }
    }
    j++;
    ch=str[j];
  }
  return bt;
}

void OutBiTree(BiTree *bt) // 输出二叉树
{
  BiTree *stack[MAXSIZE], *p;
  int level[MAXSIZE][2], top, n, i, width=4;
  char type;
  if(bt!=NULL) {
    top=1; stack[top]=bt;
    level[top][0]=width; level[top][1]=2;
    while(top>0) {
      p=stack[top];
      n=level[top][0];
      switch(level[top][1])
      {
        case 0: type='0'; break;
        case 1: type='1'; break;
        case 2: type='r'; break;
      }
      for(i=1; i<=n; i++) printf(" ");
      printf("%c(%c)\n", p->data, type);
      for(i=n+1; i<=1; i+=2) printf("--");
      top--;
      if(p->rchild != NULL) {
        top++;
        stack[top]=p->rchild;
        level[top][0]=n+width;
        level[top][1]=1;
      }
      if(p->lchild != NULL) {
        top++;
        stack[top]=p->lchild;
        level[top][0]=n+width;
        level[top][1]=0;
      }
     }
  }
}

void Preorder(BiTree *bt) // 先序遍历二叉树 根左右
{
  if(bt != NULL) {
    printf("%c", bt->data);
    Preorder(bt->lchild);
    Preorder(bt->rchild);
  }
}

int main() {
  BiTree *bt;
  char *gyb, str[MAXSIZE];
  int j=1;
  printf("\n*******************************************************");
  printf("\n  1.将按照输入的二叉树广义表表示字符串生成对应的二叉树链式结构   ");
  printf("\n  2.输出二叉树的凹入法表示形式 r--根 0--左孩子 1--右孩子   ");
  printf("\n  即将创建二叉树：a(b(c,d(e,f)),i(j,k(x,y)))   ");
  printf("\n*******************************************************\n");
  // printf("请输入二叉树的广义表形式：\n");
  gyb="a(b(c,d(e,f)),i(j,k(x,y)))";
  // scanf("%s", str);
  bt=CreateBiTreepre(gyb);
  printf("二叉树建立成功！\n");
  printf("此二叉树的凹入表示为：\n");
  OutBiTree(bt);
  printf("\n先序遍历序列为：");
  Preorder(bt);
  printf("\n");
  return 0;
}