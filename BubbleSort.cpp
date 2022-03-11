/*
冒泡排序的基本思想：
	它重复地走访过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。
	走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。
	这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。

冒泡排序的算法描述：
	比较相邻的元素。如果第一个比第二个大，就交换它们两个；
	对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
	针对所有的元素重复以上的步骤，除了最后一个；
	重复步骤1~3，直到排序完成。

	最佳情况：T(n) = O(n) 最差情况：T(n) = O(n2) 平均情况：T(n) = O(n2)。
*/

#include"BubbleSort.h"

vector<int> BubbleSort(vector<int>&intput_vector)
{
	if (intput_vector.size() == 0)
	{
		return intput_vector;
	}
	for (size_t i = 0; i < intput_vector.size(); i++)
	{
		for (size_t j = 0; j < intput_vector.size() - 1 - i; j++)
		{
			if (intput_vector[j] > intput_vector[j + 1])
			{
				int temp = intput_vector[j];
				intput_vector[j] = intput_vector[j + 1];
				intput_vector[j + 1] = temp;
			}
		}
	}
	return intput_vector;
}