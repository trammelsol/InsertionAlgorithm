/*
ð������Ļ���˼�룺
	���ظ����߷ù�Ҫ��������У�һ�αȽ�����Ԫ�أ�������ǵ�˳�����Ͱ����ǽ���������
	�߷����еĹ������ظ��ؽ���ֱ��û������Ҫ������Ҳ����˵�������Ѿ�������ɡ�
	����㷨��������������ΪԽС��Ԫ�ػᾭ�ɽ������������������еĶ��ˡ�

ð��������㷨������
	�Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
	��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԣ�����������Ԫ��Ӧ�û�����������
	������е�Ԫ���ظ����ϵĲ��裬�������һ����
	�ظ�����1~3��ֱ��������ɡ�

	��������T(n) = O(n) ��������T(n) = O(n2) ƽ�������T(n) = O(n2)��
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