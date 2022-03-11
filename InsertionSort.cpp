/*
插入排序的基本思想：
	算法描述是一种简单直观的排序算法。它的工作原理是通过构建有序序列，
	对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
	插入排序在实现上，通常采用in-place排序（即只需用到O(1)的额外空间的排序），
	因而在从后向前扫描过程中，需要反复把已排序元素逐步向后挪位，为最新元素提供插入空间。

插入排序的算法描述：
	一般来说，插入排序都采用in-place在数组上实现。具体算法描述如下：
	从第一个元素开始，该元素可以认为已经被排序；
	取出下一个元素，在已经排序的元素序列中从后向前扫描；
	如果该元素（已排序）大于新元素，将该元素移到下一位置；
	重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
	将新元素插入到该位置后；
	重复步骤2~5。

	最佳情况：T(n) = O(n) 最坏情况：T(n) = O(n2) 平均情况：T(n) = O(n2)。
*/
#include"InsertionSort.h"

vector<int> InsertionSort(vector<int>&intput_vector)
{
	if (intput_vector.size() == 0)
	{
		return intput_vector;
	}
	int current;
	for (size_t i = 0; i < intput_vector.size() - 1; i++)
	{
		current = intput_vector[i + 1];//因为i+1所以i<..size()-1
		int preIndex = i;
		while (preIndex >= 0 && current < intput_vector[preIndex])
		{
			intput_vector[preIndex + 1] = intput_vector[preIndex];
			preIndex--;
		}
		intput_vector[preIndex + 1] = current;
	}
	return intput_vector;
}