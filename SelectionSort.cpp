/*
* ѡ������Ļ���˼�룺
	�������ȶ��������㷨֮һ����Ϊ����ʲô���ݽ�ȥ����O(n2)��ʱ�临�Ӷȣ������õ�����ʱ��
	���ݹ�ģԽСԽ�á�Ψһ�ĺô����ܾ��ǲ�ռ�ö�����ڴ�ռ��˰ɡ������Ͻ���
	ѡ���������Ҳ��ƽʱ����һ�����뵽���������򷽷��˰ɡ�
	ѡ������(Selection-sort)��һ�ּ�ֱ�۵������㷨��
	������δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ�ã�Ȼ��
	�ٴ�ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ��
	�Դ����ƣ�ֱ������Ԫ�ؾ�������ϡ�

ѡ��������㷨������
	n����¼��ֱ��ѡ������ɾ���n-1��ֱ��ѡ������õ��������������㷨�������£�
	��ʼ״̬��������ΪR[1��n]��������Ϊ�գ�
	��i������(i=1,2,3��n-1)��ʼʱ����ǰ���������������ֱ�ΪR[1��i-1]��R(i��n������������ӵ�ǰ��������-ѡ���ؼ�����С�ļ�¼ R[k]���������������ĵ�1����¼R������ʹR[1��i]��R[i+1��n)�ֱ��Ϊ��¼��������1�������������ͼ�¼��������1��������������
	n-1�˽��������������ˡ�

	��������T(n) = O(n2) ��������T(n) = O(n2) ƽ�������T(n) = O(n2)��
*/

#include"SelectionSort.h"

vector<int> SelectionSort(vector<int>&intput_vector)
{
	if (intput_vector.size() == 0)
	{
		return intput_vector;
	}
	for (size_t i = 0; i < intput_vector.size(); i++)
	{
		int minIndex = i;
		for (size_t j = i; j < intput_vector.size(); j++)
		{
			if (intput_vector[j] < intput_vector[minIndex])
			{
				minIndex = j;
			}
		}
		int temp = intput_vector[minIndex];
		intput_vector[minIndex] = intput_vector[i];
		intput_vector[i] = temp;
	}
	return intput_vector;
}