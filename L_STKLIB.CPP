#include <D:\tuyen\cautru~1\ALISTLIB.CPP>
//Cai ddat stack bang danh sach
/*==== Khai bao====*/
typedef List Stack;
/*==== Tao rong ====*/
void MakeNull_Stack(Stack *S)
{
 MakeNull_List(S);
}
/*==== Kiem tra rong ====*/
int Empty_Stack(Stack S)
{
 return Empty_List(S);
}
/*==== Kiem tra dday ====*/
int Full_Stack(Stack S)
{
 return Full_List(S);
}
/*=== Lay noi dung phan tu tai dinh ===*/
ElementType Top(Stack S)
{
 return Retrieve(FirstList(S),S);
}
/*=== Them phan tu vao stack ===*/
void Push(ElementType X, Stack *S)
{
 Insert_List(X,FirstList(*S),S);
}
/*=== Lay phan tu ra khoi stack ===*/
void Pop(Stack *S)
{
 Delete_List(FirstList(*S),S);
}

/*void main()
{
int n,m;
Stack S;
clrscr();
printf("Nhap vao so thap phan can doi "); scanf("%d",&n);
m=n;
if (n==0) printf("\n\n so nhi phan la 0");
else
{ MakeNull_Stack(&S);
  // Day cac so du vao ngan xep
  while (m!=0)
  { Push(m%2,&S);
    m=m/2;
  }
  // Hien thi du lieu trong ngan xep ra man hinh
  while (!Empty_Stack(S))
    { printf("%1d",Top(S));
      Pop(&S);
    }
}

getch();
} */