#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 255
typedef struct BiNode
{
  char data;
  struct BiNode *lchild;
  struct BiNode *rchild;
}BiTree, *BinTree;

int depth = 0;

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

void Inorder(BiTree *bt) // 中序遍历二叉树 左根右
{
  if(bt != NULL) {
    Inorder(bt->lchild);
    printf("%c", bt->data);
    Inorder(bt->rchild);
  }
}

void Postorder(BiTree *bt) // 后序遍历二叉树 左右根
{
  if(bt != NULL) {
    Postorder(bt->lchild);
    Postorder(bt->rchild);
    printf("%c", bt->data);
  }
}

// 遍历算法的应用

void leafNode(BiTree *root) // 先序遍历输出二叉树中叶子结点
{
  if(root != NULL) {
    if(root->lchild == NULL && root->rchild == NULL) {
      printf("%c", root->data);
    }
    leafNode(root->lchild);
    leafNode(root->rchild);
  }
}

void CreateBiTree(BinTree *bt) // 用扩展先序遍历序列创建二叉链表
{
  char ch;
  ch=getchar();
  if(ch=='.') (*bt)=NULL;
  else {
    (*bt)=(BiTree *)malloc(sizeof(BiTree));
    (*bt)->data=ch;
    CreateBiTree(&((*bt)->lchild));
    CreateBiTree(&((*bt)->rchild));
  }
}

int PostTreeDepth(BiTree *bt) // 后序遍历求二叉树的高度
{
  int hl, hr, max;
  if(bt != NULL) {
    hl = PostTreeDepth(bt->lchild);
    hr = PostTreeDepth(bt->rchild);
    max = hl>hr ? hl:hr;
    return (max+1);
  } else {
    return 0;
  }
}

void PreTreeDepth(BiTree *bt, int h) // 前序遍历求二叉树高度
{
  if(bt != NULL) {
    if(h>depth) depth = h;
    PreTreeDepth(bt->lchild, h+1);
    PreTreeDepth(bt->rchild, h+1);
  }
}

void PrintTree(BiTree *bt, int nLayer) // 按竖向树状打印二叉树
{
  if(bt == NULL) return;
  PrintTree(bt->rchild, nLayer+1);
  int i;
  for(i=0; i<nLayer; i++) {
    printf("    ");
  }
  printf("%c\n", bt->data);
  PrintTree(bt->lchild, nLayer+1);
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
  // bt=CreateBiTreepre(gyb);
  CreateBiTree(&bt);
  printf("二叉树建立成功！\n");
  printf("此二叉树的凹入表示为：\n");
  OutBiTree(bt);
  printf("按竖向树状打印二叉树：\n");
  PrintTree(bt, 1);
  printf("\n二叉树高度为：%d", PostTreeDepth(bt));
  PreTreeDepth(bt, 1);
  printf("\n二叉树高度为：%d", depth);
  printf("\n先序遍历序列为：");
  Preorder(bt);
  printf("\n中序遍历序列为：");
  Inorder(bt);
  printf("\n后序遍历序列为：");
  Postorder(bt);
  printf("\n叶子结点为：");
  leafNode(bt);
  printf("\n");
  return 0;
}