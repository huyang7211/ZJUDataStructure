#include "Unit1MaxSubseqSum.h"




/**  -2, 11, -4, 13, -5, -2  **/

int MaxSubseqSum2Plus(int A[],int N,int &left,int &right)
{
	int thisSum = 0, maxSum = 0;
	left = 0,right = 0;
	bool bAllBeNegative = true;
	for(int i = 0; i < N; ++i)
	{
		thisSum = 0;
		if(A[i] >= 0)
			bAllBeNegative = false;
		for (int j = i; j < N; ++j)
		{
			thisSum += A[j];	
			if (thisSum > maxSum)
			{
				maxSum = thisSum;
				left = i;
				right = j;
			}
		
		}

	}
	if (bAllBeNegative)
	{
		left = 0;
		right = N - 1;
	}
	return maxSum;
}

int MaxSubseqSum3(int A[],int N)
{
	return devideAndConquer(A,0,N-1);
}

int devideAndConquer(int A[],int left,int right)
{
	int iMaxLeftSum = 0, iMaxRightSum = 0;
	
	int iCenter = -1;

	int iCenterLeftMax = 0, iCenterRightMax = 0;

	if(left == right)
	{
		A[left] > 0 ? iMaxLeftSum = A[left] : iMaxLeftSum = 0;
		return iMaxLeftSum;
	}
	int thisLeftSum = 0,thisRightSum = 0;
	iCenter = (right + left) /2;
	iMaxLeftSum = devideAndConquer(A,left,iCenter);
	iMaxRightSum = devideAndConquer(A,iCenter+1,right);

	for (int i = iCenter; i >= left; --i)
	{
		thisLeftSum += A[i];
		if(thisLeftSum > iCenterLeftMax)
			iCenterLeftMax = thisLeftSum;
	}
	for(int i = iCenter+1; i <= right; ++i)
	{
		thisRightSum += A[i];
		if(thisRightSum > iCenterRightMax)
			iCenterRightMax = thisRightSum;
	}
	int iTotolSum = iCenterRightMax + iCenterLeftMax;
	if(iTotolSum > iMaxLeftSum && iTotolSum >iMaxRightSum)
		return iTotolSum;
	else if(iMaxLeftSum > iTotolSum && iMaxLeftSum > iMaxRightSum)
		return iMaxLeftSum;
	else 
		return iMaxRightSum;
	

}

/** ���ߴ��� **/
int MaxSubseqSum4(int A[],int N)
{
	int thisSum = 0,maxSum = 0;
	for (int i = 0; i < N; ++i)
	{
		if(thisSum < 0)
			thisSum = 0;
		thisSum += A[i];
		if(thisSum > maxSum)
			maxSum = thisSum;
	}
	return maxSum;
}

/** ���ߴ��� **/
int MaxSubseqSum4Plus(int A[],int N,int &left,int &right)
{
	int thisSum = 0,maxSum = 0;
	int temp = 0;
	int posZeroAndNegative = -1;
	bool bAllBeNegative = true;
	for (int i = 0; i < N; ++i)
	{
		if(thisSum < 0)
		{
			thisSum = 0;
			/** ��¼���ܴ��ڵ����λ�� **/
			temp = i;
		}
		/** ��¼ȫ�������Ƿ�ȫΪ���� **/
		if(A[i] >= 0)
			bAllBeNegative = false;
		thisSum += A[i];
		/** ��ǰ��Ϊ0�����ҽ�ֹ����ǰȫΪ����������������¼��0��λ�� 
			����Ӧ��ֻ�Ƿ���ֵ���ˣ���ʵ��¼��λ�û��ǱȽϿ����λ�á�����������û����ȷ˵������0�������ô�죬���Ҳ�����
		**/
		if(thisSum == 0 && !bAllBeNegative)
		{
			posZeroAndNegative = i;
		}
		if(thisSum > maxSum)
		{
			maxSum = thisSum;
			left = temp;
			right = i; 
		}
	}
	if(bAllBeNegative == true)
	{
		left = 0;
		right = N - 1;
	}
	if (maxSum == 0 && !bAllBeNegative)
	{
		left = posZeroAndNegative;
		right = posZeroAndNegative;
	}
	return maxSum;
}
