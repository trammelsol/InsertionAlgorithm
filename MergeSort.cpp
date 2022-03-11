/*
* �鲢����Ļ���˼�룺
	��ѡ������һ�����鲢��������ܲ����������ݵ�Ӱ�죬�����ֱ�ѡ������õĶ࣬
	��Ϊʼ�ն���O(n log n����ʱ�临�Ӷȡ���������Ҫ������ڴ�ռ䡣
	�鲢�����ǽ����ڹ鲢�����ϵ�һ����Ч�������㷨��
	���㷨�ǲ��÷��η���Divide and Conquer����һ���ǳ����͵�Ӧ�á��鲢������һ���ȶ������򷽷���
	��������������кϲ����õ���ȫ��������У�����ʹÿ��������������ʹ�����жμ�����
	�������������ϲ���һ���������Ϊ2-·�鲢��
�鲢������㷨������
	�ѳ���Ϊn���������зֳ���������Ϊn/2�������У�
	�������������зֱ���ù鲢����
	����������õ������кϲ���һ�����յ���������

	��������T(n) = O(n) ��������T(n) = O(nlogn) ƽ�������T(n) = O(nlogn)��
*/
#include"MergeSort.h"
//��·�鲢�����㷨
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