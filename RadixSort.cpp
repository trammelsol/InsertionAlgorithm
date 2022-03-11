/*
��������Ļ���˼�룺
	Ҳ�ǷǱȽϵ������㷨����ÿһλ�������򣬴����λ��ʼ���򣬸��Ӷ�ΪO(kn),Ϊ���鳤�ȣ�
	kΪ�����е���������λ�������������ǰ��յ�λ������Ȼ���ռ����ٰ��ո�λ����Ȼ�����ռ���
	�������ƣ�ֱ�����λ����ʱ����Щ�����������ȼ�˳��ģ��Ȱ������ȼ������ٰ������ȼ�����
	���Ĵ�����Ǹ����ȼ��ߵ���ǰ�������ȼ���ͬ�ĵ����ȼ��ߵ���ǰ������������ڷֱ����򣬷ֱ��ռ���
	�������ȶ��ġ�

	�������������ַ�����
		MSD �Ӹ�λ��ʼ��������
		LSD �ӵ�λ��ʼ��������

����������㷨������
	ȡ�������е����������ȡ��λ����
	arrΪԭʼ���飬�����λ��ʼȡÿ��λ���radix���飻
	��radix���м����������ü�������������С��Χ�����ص㣩��

	��������T(n) = O(n * k) ��������T(n) = O(n * k) ƽ�������T(n) = O(n * k)��
*/
#include"RadixSort.h"

vector<int> RadixSort(vector<int>&input_vector)
{
	if (input_vector.size() < 2) return input_vector;
	int max = input_vector[0];
	for (auto x : input_vector)
	{
		if (x > max) max = x;
	}
	int maxDigit = 0;
	while (max != 0)
	{
		max /= 10;
		maxDigit++;
	}
	int mod = 10, div = 1;
	vector<vector<int>> bucketList;
	for (size_t i = 0; i < 10; i++)
	{
		vector<int>avector;
		bucketList.push_back(avector);
	}
	for (int i = 0; i < maxDigit; i++, mod *= 10, div *= 10)
	{
		for (int j = 0; j < input_vector.size(); j++)
		{
			int num = (input_vector[j] % mod) / div;
			bucketList[num].push_back(input_vector[j]);
		}
		int index = 0;
		for (int j = 0; j < bucketList.size(); j++)
		{
			for (int k = 0; k < bucketList[j].size(); k++)
				input_vector[index++] = bucketList[j][k];
			bucketList[j].clear();
		}
	}
	return input_vector;
}