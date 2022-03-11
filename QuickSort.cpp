/*
��������Ļ���˼�룺
	ͨ��һ�����򽫴��ż�¼�ָ��ɶ����������֣�����һ���ּ�¼�Ĺؼ��־�����һ���ֵĹؼ���С��
	��ɷֱ���������ּ�¼�������������Դﵽ������������
����������㷨������
	��������ʹ�÷��η�����һ������list����Ϊ�����Ӵ���sub-lists���������㷨�������£�
	������������һ��Ԫ�أ���Ϊ ����׼����pivot����
	�����������У�����Ԫ�رȻ�׼ֵС�İڷ��ڻ�׼ǰ�棬����Ԫ�رȻ�׼ֵ��İ��ڻ�׼�ĺ��棨��ͬ�������Ե���һ�ߣ���
	����������˳�֮�󣬸û�׼�ʹ������е��м�λ�á������Ϊ������partition��������
	�ݹ�أ�recursive����С�ڻ�׼ֵԪ�ص������кʹ��ڻ�׼ֵԪ�ص�����������

��������T(n) = O(nlogn) ��������T(n) = O(n2) ƽ�������T(n) = O(nlogn)
*/

#include"QuickSort.h"

int partition(vector<int>& input_vector, size_t start, size_t end)
{
	swap(input_vector[start], input_vector[start + rand() % (end - start + 1)]);
	int pivot = input_vector[start];
	while (start < end)
	{
		while (start < end)
		{
			if (pivot < input_vector[end])
				end--;
			else
			{
				input_vector[start++] = input_vector[end];
				break;
			}
		}
		while (start < end)
		{
			if (input_vector[start] < pivot)
				start++;
			else
			{
				input_vector[end--] = input_vector[start];
				break;
			}
		}
	}
	input_vector[start] = pivot;
	return start;
}
vector<int> QuickSort(vector<int>& input_vetor, size_t start, size_t end)
{
	if (end - start < 1) //�ݹ��
	{
		return input_vetor;
	}
	size_t mi = partition(input_vetor, start, end);
	if (mi > start)
	{
		QuickSort(input_vetor, start, mi - 1);
	}
	if (mi < end)
	{
		QuickSort(input_vetor, mi, end);
	}
	return input_vetor;
}