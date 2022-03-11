/*
��������Ļ���˼�룺
	�������ڽ����������ֵת��Ϊ���洢�ڶ��⿪�ٵ�����ռ��С� ��Ϊһ������ʱ�临�Ӷȵ�����
	��������Ҫ����������ݱ�������ȷ����Χ��������
	��������(Counting sort)��һ���ȶ��������㷨����������ʹ��һ�����������C��
	���е�i��Ԫ���Ǵ���������A��ֵ����i��Ԫ�صĸ�����Ȼ���������C����A�е�Ԫ���ŵ���ȷ��λ�á�
	��ֻ�ܶ�������������

����������㷨������
	�ҳ��������������������С��Ԫ�أ�
	ͳ��������ÿ��ֵΪi��Ԫ�س��ֵĴ�������������C�ĵ�i�
	�����еļ����ۼӣ���C�еĵ�һ��Ԫ�ؿ�ʼ��ÿһ���ǰһ����ӣ���
	�������Ŀ�����飺��ÿ��Ԫ��i����������ĵ�C(i)�ÿ��һ��Ԫ�ؾͽ�C(i)��ȥ1��

	��������T(n) = O(n+k) ��������T(n) = O(n+k) ƽ�������T(n) = O(n+k)��
*/

#include"CountingSort.h"

vector<int> CountingSort(vector<int>& input_vector)
{
	vector<int>::iterator biggest = max_element(std::begin(input_vector), std::end(input_vector));
	int maxVal = *biggest;
	int len = input_vector.size();
	if (len < 1) return input_vector;
	vector<int> count(maxVal + 1, 0);
	vector<int>temp(input_vector);
	for (auto x : input_vector)//��ȡÿ��Ԫ�صĸ�����count��Ԫ��ֵΪ�±�
		count[x]++;
	for (int i = 1; i <= maxVal; i++)
		count[i] += count[i - 1];
	for (int i = len - 1; i >= 0; i--)
	{
		input_vector[count[temp[i]] - 1] = temp[i];
		count[temp[i]]--;
	}
	return input_vector;
}