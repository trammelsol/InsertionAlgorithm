/*
������Ļ���˼�룺
	������Heapsort����ָ���ö��������ݽṹ����Ƶ�һ�������㷨���ѻ���һ��������ȫ�������Ľṹ��
	��ͬʱ����ѻ������ʣ����ӽ��ļ�ֵ����������С�ڣ����ߴ��ڣ����ĸ��ڵ㡣

��������㷨������
	����ʼ������ؼ�������(R1,R2��.Rn)�����ɴ󶥶ѣ��˶�Ϊ��ʼ����������
	���Ѷ�Ԫ��R[1]�����һ��Ԫ��R[n]��������ʱ�õ��µ�������(R1,R2,����Rn-1)���µ�������(Rn),
	������R[1,2��n-1]<=R[n]��
	���ڽ������µĶѶ�R[1]����Υ���ѵ����ʣ������Ҫ�Ե�ǰ������(R1,R2,����Rn-1)����Ϊ�¶ѣ�
	Ȼ���ٴν�R[1]�����������һ��Ԫ�ؽ������õ��µ�������(R1,R2��.Rn-2)���µ�������(Rn-1,Rn)��
	�����ظ��˹���ֱ����������Ԫ�ظ���Ϊn-1�����������������ɡ�

	��������T(n) = O(nlogn) ��������T(n) = O(nlogn) ƽ�������T(n) = O(nlogn)��
*/
#include"HeapSort.h"
size_t len;

vector<int> HeapSort(vector<int> &input_vector)
{
	len = input_vector.size();
	if (len < 1) return input_vector;
	//1������һ���󶥶�
	buildMaxHeap(input_vector);
	while (len > 0)
	{
		swap(input_vector[0], input_vector[len - 1]);
		len--;
		adjustHeap(input_vector, 0);
	}
	return input_vector;
}
void buildMaxHeap(vector<int>& input_vector)//Floyd���ٽ����㷨
{
	for (int i = len / 2 - 1; i >= 0; i--) //�Ӷѵ����һ���ڲ��ڵ㿪ʼ����
	{
		adjustHeap(input_vector, i);
	}
}
void adjustHeap(vector<int>& input_vector, size_t i)//������϶��µĹ���
{
	int maxIndex = i;
	//������������������������ڸ��ڵ������ָ��ָ�������������һ���ڵ���������������Ϊ��2*i(v)+1��
	if (i * 2 + 1 < len && input_vector[i * 2 + 1] > input_vector[maxIndex])
		maxIndex = i * 2 + 1;
	//������������������������ڸ��ڵ������ָ��ָ�������������һ���ڵ����Һ�����������Ϊ��2*i(v)+2��
	if (i * 2 + 2 < len && input_vector[i * 2 + 2] > input_vector[maxIndex])
		maxIndex = i * 2 + 2;
	//���ڶ�����������ڵ㲻�����ֵ��ִ�н�������
	if (maxIndex != i)
	{
		swap(input_vector[i], input_vector[maxIndex]);
		adjustHeap(input_vector, maxIndex);
	}
}