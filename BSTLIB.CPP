#include <stdio.h>
#include <conio.h>
#include <malloc.h>

//Khai bao cay tim kiem nhi phan
typedef int KeyType;
typedef struct Node
{
 KeyType Key;
 Node* left;
 Node* right;
};
typedef Node* TTree;
/*=== Tao cay rong ===*/
void MakeNull_Tree(TTree *T)
{
 (*T)=NULL;
}
/*=== Kiem tra cay rong ===*/
int EmptyTree(TTree T)
{
 return T==NULL;
}
/*=== Xac dinh con trai ===*/
TTree LeftChild(TTree T)
{
 if(T != NULL)
	return T->left;
 else   return NULL;
}
/*=== Xac dinh con phai ===*/
TTree RightChild(TTree T)
{
 if(T != NULL)
	return T->right;
 else   return NULL;
}
/*=== Xac dinh nut la ===*/
int isLeaf(TTree T)
{
  if((T != NULL) && (T->left == NULL) && (T->right == NULL))
	return 1;
  else  return NULL;
}
/*=== Xac dinh so nut cua cay ===*/
int nb_nodes(TTree T)
{
 if(EmptyTree(T))
	return 0;
 else   return nb_nodes(T->left)+nb_nodes(T->right)+1;
}

/*=== Duyet cay nhi phan ===*/
//Duyet tien tu
void NLR(TTree T)
{
  if(!EmptyTree(T))
  {
   printf(" %d",T->Key); //Xu ly nut
   NLR(LeftChild(T)); //Duyet tien tu con trai
   NLR(RightChild(T)); //Duyet tien tu con phai
  }
}
//Duyet trung tu
void LNR(TTree T)
{
 if(!EmptyTree(T))
 {
  LNR(LeftChild(T)); //Duyet trung tu con trai
  printf(" %d",T->Key);//Xu ly nut
  LNR(RightChild(T));//Duyet trung tu con phai
  }
}
//Duyet hau tu
void LRN(TTree T)
{
 if(!EmptyTree(T))
 {
  LRN(LeftChild(T)); //Duyet hau tu con trai
  LRN(RightChild(T));//Duyet hau tu con phai
  printf(" %d",T->Key);//Xu ly nut
  }
}
//Ham tra ve nut co khoa la K, khong thay tra ve NULL
TTree Search(KeyType K, TTree T)
{
  if(T!=NULL) //Kiem tra cay rong
	if(K == T->Key) //tim thay khoa
		return T;
	else
		if(K<T->Key) // Hy vong K nam ben trai
			return Search(K,LeftChild(T));
		else      // Hy vong K nam ben phai
			return Search(K,RightChild(T));
  else return NULL;
}
//Them nut co khoa X vao BST
void InsertNode(KeyType X, TTree *T)
{
  if((*T) == NULL)
  {
    (*T)      = (Node*)malloc(sizeof(Node));
    (*T)->Key = X;
    (*T)->left = NULL;
    (*T)->right = NULL;
  }
  else
	if((*T)->Key == X)
		printf("Da ton tai khoa X");
	else
		if((*T)->Key > X)
			InsertNode(X,&(*T)->left);
		else
			InsertNode(X,&(*T)->right);
}
//Xoa mot nut co khoa nho nhat
KeyType DeleteMin(TTree *T)
{
 KeyType k;
 if((*T)->left == NULL)
 {
     k = (*T)->Key;
     (*T) = (*T)->right;
     return k;
 }
 else return DeleteMin(&(*T)->left);
}

//Xoa mot nut co khoa cho truoc tren cay TKNP
void DeleteNode(KeyType X, TTree *T)
{
  if((*T)!=NULL) //Kiem tra cay khac rong
	if(X < (*T)->Key) //Hy vong X nam ben trai cua nut
		DeleteNode(X,&(*T)->left);
	else
	     if(X > (*T)->Key) //Hy vong X nam ben phai cua nut
		DeleteNode(X,&(*T)->right);
	     else // Tim thay khoa X tren cay
		 if(((*T)->left==NULL)&&((*T)->right==NULL))//X la nut la
		     (*T)=NULL; // Xoa nut X
		 else // X co it nhat mot con
		     if((*T)->left==NULL) //Chac chan co con phai
			(*T) = (*T)->right;
		     else
			 if((*T)->right==NULL) //Chac chan co con trai
			    (*T) = (*T)->left;
			 else  // X co hai con
			    (*T)->Key = DeleteMin(&(*T)->right);
}
