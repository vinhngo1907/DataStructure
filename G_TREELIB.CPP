#include <stdio.h>
#include <conio.h>
#define MAXLENGTH 50
#define NIL -1
typedef  char DataType;
typedef int Node;
typedef struct {
/* Luu tr? nhan (d? li?u) c?a n£t trong cƒy */
DataType Data[MAXLENGTH];
/* Luu tr? cha c?a c c n£t trong cƒy theo nguyˆn t?c: Cha c?a n£t i s? luu ? v? tr¡ i trong m?ng */
Node Parent[MAXLENGTH];
/* S? n£t th?c s? trong cƒy */
int MaxNode;} Tree;
Tree T;
void MakeNull_Tree (Tree *T){
	(*T).MaxNode=0;
}
int EmptyTree(Tree T){
	return T.MaxNode == 0;
}
Node Parent(Node n,Tree T){
	if (EmptyTree(T) || (n>T.MaxNode-1))
		return NIL;
	else return T.Parent[n];
}
DataType Label_Node(Node n,Tree T){
	if (!EmptyTree(T) && (n<=T.MaxNode-1))
		return T.Data[n];
}
Node Root(Tree T){
	if (!EmptyTree(T)) return 0;
	else return NIL;
}
Node LeftMostChild(Node n,Tree T){
	Node i;
	int found;
	i=n+1;/* V? tr¡ n£t d?u tiˆn hy v?ng l… con c?a n£t n */
	found=0;
	while ((i<=T.MaxNode-1) && !found)
		if (T.Parent[i]==n) found=1; /* Da tm th?y con tr i nh?t c?a n£t n */
		else i=i+1;
	if (found) return i;
	else return NIL;
}
Node RightSibling(Node n,Tree T){
	Node i,parent;
	int found;

	if (n<=0||n>=T.MaxNode-1)
	return NIL;
	else
	{parent=T.Parent[n];
	i=n+1;
	found=0;
	while ((i<=T.MaxNode-1) && !found)
		if (T.Parent[i]==parent) found=1;
		else i=i+1;
	if (found) return i;
	else return NIL; }
}
void PreOrder(Node n,Tree T){
	Node i;
	printf("%c ",Label_Node(n,T));
	i=LeftMostChild(n,T);
	while (i!=NIL){
		PreOrder(i,T);
		i=RightSibling(i,T);
	}
}
void InOrder(Node n,Tree T){
	Node i;
	i=LeftMostChild(n,T);
	if (i!=NIL) InOrder(i,T);
	printf("%c ",Label_Node(n,T));
       //	if (i!=NIL)
	i=RightSibling(i,T);
	while (i!=NIL){
		InOrder(i,T);
		i=RightSibling(i,T);
	}
}
void PostOrder(Node n,Tree T){
	Node i;
	i=LeftMostChild(n,T);
	while (i!=NIL){
		PostOrder(i,T);
		i=RightSibling(i,T);
	}
	printf("%c ",Label_Node(n,T));
}
