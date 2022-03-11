/*
* 归并排序的基本思想：
	和选择排序一样，归并排序的性能不受输入数据的影响，但表现比选择排序好的多，
	因为始终都是O(n log n）的时间复杂度。代价是需要额外的内存空间。
	归并排序是建立在归并操作上的一种有效的排序算法。
	该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。归并排序是一种稳定的排序方法。
	将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。
	若将两个有序表合并成一个有序表，称为2-路归并。
归并排序的算法描述：
	把长度为n的输入序列分成两个长度为n/2的子序列；
	对这两个子序列分别采用归并排序；
	将两个排序好的子序列合并成一个最终的排序序列

	最佳情况：T(n) = O(n) 最差情况：T(n) = O(nlogn) 平均情况：T(n) = O(nlogn)。
*/
#include"MergeSort.h"
//二路归并排序算法
vector<int> MergeSort(vector<int>&input_vetror)
{
	if (input_vetror.size() < 2)
	{
		return input_vetror;
	}
	size_t mid = input_vetror.size() / 2;
	vector<int>left_vector(input_vetror.begin(), input_vetror.begin() + mid);
	vector<int>right_vector(input_vetror.begin() + mid, input_vetror.end());
	return merge(MergeSort(left_vector), MergeSort(right_vector));
}
vector<int> merge(vector<int> left,vector<int> right)
{
	vector<int> reusult;
	for (size_t i = 0, j = 0, k = 0; (j < left.size() || k < right.size());)
	{
		if ((j < left.size()) && (!(k < right.size()) || (left[j] <= right[k])))
		{
			reusult.push_back(left[j++]);
		}
		if ((k < right.size()) && (!(j < left.size()) || (right[k] < left[j])))
		{
			reusult.push_back(right[k++]);
		}
	}
	return reusult;
}