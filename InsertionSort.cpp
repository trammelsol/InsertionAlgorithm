/*
��������Ļ���˼�룺
	�㷨������һ�ּ�ֱ�۵������㷨�����Ĺ���ԭ����ͨ�������������У�
	����δ�������ݣ��������������дӺ���ǰɨ�裬�ҵ���Ӧλ�ò����롣
	����������ʵ���ϣ�ͨ������in-place���򣨼�ֻ���õ�O(1)�Ķ���ռ�����򣩣�
	����ڴӺ���ǰɨ������У���Ҫ������������Ԫ�������Ųλ��Ϊ����Ԫ���ṩ����ռ䡣

����������㷨������
	һ����˵���������򶼲���in-place��������ʵ�֡������㷨�������£�
	�ӵ�һ��Ԫ�ؿ�ʼ����Ԫ�ؿ�����Ϊ�Ѿ�������
	ȡ����һ��Ԫ�أ����Ѿ������Ԫ�������дӺ���ǰɨ�裻
	�����Ԫ�أ������򣩴�����Ԫ�أ�����Ԫ���Ƶ���һλ�ã�
	�ظ�����3��ֱ���ҵ��������Ԫ��С�ڻ��ߵ�����Ԫ�ص�λ�ã�
	����Ԫ�ز��뵽��λ�ú�
	�ظ�����2~5��

	��������T(n) = O(n) ������T(n) = O(n2) ƽ�������T(n) = O(n2)��
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
		current = intput_vector[i + 1];//��Ϊi+1����i<..size()-1
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