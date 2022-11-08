#include <stdio.h>
#include <conio.h>
#include <alloc.h>
/* ==== Khai bao danh sach kieu con tro ====*/
typedef int ElementType;
typedef struct Node{
 ElementType Element;
 Node* 	     Next;
 Node*	     Prev;
};
typedef Node*    Position;
typedef Position List;

/*==== Cac phep toan tren danh sach ====*/
/*== Ham tao danh sach rong ==*/
void MakeNull_List(List *DL){
 *DL = NULL;
}

int Empty_List(List DL){
 return (DL == NULL);
}

/*== Cac ham dinh vi tri trong danh sach lien ket kep ===*/
Position FirstList(List DL)
{
 return DL;
}
Position EndList(List DL)
{
 return NULL;
}
Position Next(Position P, List DL)
{
 return P->Next;
}
Position Previous(Position P, List DL)
{
 return P->Prev;
}

/*== Ham chen phan tu X vao vi tri P ==*/
void Insert_List(ElementType X, Position P,List *DL)
{
  if(*DL == NULL)
  { //Truong hop them vao DS rong
   (*DL)=(Node*)malloc(sizeof(Node));
   (*DL)->Element = X;
   (*DL)->Prev    = NULL;
   (*DL)->Next    = NULL;
  }
  else
  {
   if(P == EndList(*DL)) //Vi tri them cuoi cung trong danh sach
   {
	Position temp,R;
	temp = (Node*)malloc(sizeof(Node));
	temp->Element = X;
	temp->Next    = NULL;
	R = *DL;
	while (R->Next != NULL)
		R = R->Next;
	temp->Prev    =  R;
	R->Next=temp;
   }
   else
   {
	Position temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->Element = X;
	temp->Next    = P;
	temp->Prev    = P->Prev;
	if(P->Prev != NULL) // Kiem tra vi tri them co phai vi tri dau tien khong
		P->Prev->Next = temp;
	else
		(*DL) = temp;

	P->Prev = temp;
   }
  }

}
/*== Ham xoa phan tu tai vi tri P ==*/
void Delete_List(Position P,List *DL){
 if(*DL == NULL)
  printf("\nLoi !Danh sach rong khong the xoa");
 else
     if(P == *DL) // Truong hop xoa phan tu dau tien trong DS kep
	(*DL) = (*DL)->Next;
     else{ //Truong hop phan tu can xoa khong phai phan tu dau tien
      P->Prev->Next = P->Next;
      if(P->Next != NULL)//Kiem tra phan tu xoa co phai la phan tu cuoi khong
		P->Next->Prev = P->Prev;
      free(P);
     }
}
/*== Ham lay noi dung phan tu tai vi tri  P ==*/
ElementType Retrieve(Position P, List DL){
    return P->Element;
}
void Print_List(List L){
     Position P;
     P = FirstList(L);
     while(P != EndList(L)){
	printf("%10d",Retrieve(P,L));
	P = Next(P,L);
     }
}
/*============ Ket thuc ham in danh sach ========================*/
