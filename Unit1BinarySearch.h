#define MAXSIZE 10
#define NotFound 0

typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};
Position BinarySearch( List L, ElementType X )
{
	int low = 1,high = L->Last;
	int mid = 0;
	while (low <= high)
	{
		mid = (low + high )/2;
		if(X == L->Data[mid])
			return mid;
		else if(X < L->Data[mid])
		{
			high = mid-1;

		}
		else
		{
			low = mid + 1;
		}
	}
	/** no found  **/
	return NotFound;

}