#include <stdio.h>
#include <conio.h>

#define Maxlength 30
/*========= Khai bao danh sach ddac ================*/
typedef int ElementType;
typedef int Position;
typedef struct {
  ElementType Elements[Maxlength];
  Position    Last;
}List;
/*======== Ket thuc khai bao =======================*/

/*=========Cac phep toan tren danh sach ================*/
void MakeNull_List(List *L){
     L->Last = 0;
}

int Empty_List(List L){
    return (L.Last == 0);
}

int Full_List(List L){
    if(L.Last == Maxlength)
	return 1;
    else
	return 0;
//return (L.last==Maxlength);
}

Position FirstList(List L){
    return 1;
}

Position EndList(List L){
    return L.Last+1;
}

Position Next(Position P, List L){
    return P+1;
}

Position Previous(Position P, List L){
    return P-1;
}

ElementType Retrieve(Position P, List L){
    return L.Elements[P-1];
}

void Insert_List(ElementType X, Position P, List *L){
    int i=0;
    if(L->Last == Maxlength)
       printf("\nDanh sach dday !!!");
    else if ((P<1) || (P>L->Last+1))
	    printf("\nVi tri khong hop le !!!");
	 else {
	    for(i=L->Last ;i>=P ; i--)
		L->Elements[i] = L->Elements[i-1];
	    L->Last++;
	    L->Elements[P-1] = X;
	 }
}

void Delete_List(Position P, List *L){
    if((P > L->Last) || (P<1))
	printf("\nVi tri khong hop le !!!");
    else
	if(Empty_List(*L))
	  printf("\nDanh sach rong !");
	else{
	  Position i;
	  for(i=P; i<L->Last; i++)
	  {
	     L->Elements[i-1] = L-> Elements[i];
	  }
	  L->Last--;
	}
}
/*============ Ket thuc cac phep toan tren danh sach ============*/
/*============ Ham in danh sach =================================*/
void Print_List(List L){
     Position P;
     P = FirstList(L);
     while(P != EndList(L)){
	printf("%10d",Retrieve(P,L));
	P = Next(P,L);
     }
}
/*============ Ket thuc ham in danh sach ========================*/

/*============ Ham tim vi tri phan tu X ddau tien danh sach =====*/
Position Locate(ElementType X,List L){
    Position P;
    int found = 0;
    P = FirstList(L);
    while ((P!=EndList(L)) && (found==0)){
	if(Retrieve(P,L) == X)
	  found = 1;
	else P = Next(P, L);
    }
    return P;
}
