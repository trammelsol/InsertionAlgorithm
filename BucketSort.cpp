/*
Ͱ����Ļ���˼�룺
	Ͱ�����Ǽ�������������档�������˺�����ӳ���ϵ����Ч���Ĺؼ����������ӳ�亯����ȷ����
	Ͱ���� (Bucket sort)�Ĺ�����ԭ�������������ݷ��Ӿ��ȷֲ��������ݷֵ�����������Ͱ�
	ÿ��Ͱ�ٷֱ������п�����ʹ�ñ�������㷨�����Եݹ鷽ʽ����ʹ��Ͱ���������

Ͱ������㷨������
	��Ϊ����һ��BucketSize����Ϊÿ��Ͱ���ܷ��ö��ٸ���ͬ��ֵ�����統BucketSize==5ʱ����Ͱ���Դ��
	��1,2,3,4,5���⼸�����֣������������ޣ������Դ��100��3����
	�����������ݣ����Ұ�����һ��һ���ŵ���Ӧ��Ͱ��ȥ��
	��ÿ�����ǿյ�Ͱ�������򣬿���ʹ���������򷽷���Ҳ���Եݹ�ʹ��Ͱ����
	�Ӳ��ǿյ�Ͱ����ź��������ƴ��������
	ע�⣬����ݹ�ʹ��Ͱ����Ϊ����Ͱ������Ͱ����Ϊ1ʱҪ�ֶ���СBucketSize������һѭ��Ͱ��������
	�����������ѭ���������ڴ������

	��������T(n) = O(n+k) ��������T(n) = O(n+k) ƽ�������T(n) = O(n2)��
*/

#include"BucketSort.h"

vector<int> BucketSort(vector<int>& input_vector, int bucketSize)
{
	if (input_vector.size() < 2)return input_vector;
	int max = input_vector[0], min = input_vector[0];
	//�ҵ������Сֵ
	for (size_t i = 1; i < input_vector.size(); i++)
	{
		if (input_vector[i] > max) max = input_vector[i];
		if (input_vector[i] < min) min = input_vector[i];
	}
	int bucketCount = (max - min) / bucketSize + 1;//������ = �����ֵ-��Сֵ��/ ��Ͱ������ - 1��
	vector<vector<int>>bucketArr;
	vector<int>resultArr;
	for (size_t i = 0; i < bucketSize; i++)//����Ͱ�ṹ
	{
		vector<int> a_vector;
		bucketArr.push_back(a_vector);
	}
	for (size_t i = 0; i < input_vector.size(); i++)//��ʼ��Ͱ�ṹ
	{
		(bucketArr[(input_vector[i] - min) / bucketCount]).push_back(input_vector[i]);
	}
	for (size_t i = 0; i < bucketSize; i++)
	{
		if (bucketArr[i].size() == 0) continue;
		sort(bucketArr.begin(), bucketArr.end());
	}
	for (vector<int> tempList : bucketArr) {
		for (int i : tempList) {
			resultArr.push_back(i);
		}
	}
	return resultArr;
}