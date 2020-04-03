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

/** 在线处理 **/
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

/** 在线处理 **/
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
			/** 记录可能存在的左边位置 **/
			temp = i;
		}
		/** 记录全部数据是否全为负数 **/
		if(A[i] >= 0)
			bAllBeNegative = false;
		thisSum += A[i];
		/** 当前和为0，并且截止到当前全为非正数的情况，则记录下0的位置 
			这里应该只是返回值对了，其实记录的位置会是比较靠后的位置————题上没有明确说负数和0的情况怎么办，姑且不管了
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
