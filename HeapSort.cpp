/*
堆排序的基本思想：
	堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。堆积是一个近似完全二叉树的结构，
	并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。

堆排序的算法描述：
	将初始待排序关键字序列(R1,R2….Rn)构建成大顶堆，此堆为初始的无序区；
	将堆顶元素R[1]与最后一个元素R[n]交换，此时得到新的无序区(R1,R2,……Rn-1)和新的有序区(Rn),
	且满足R[1,2…n-1]<=R[n]；
	由于交换后新的堆顶R[1]可能违反堆的性质，因此需要对当前无序区(R1,R2,……Rn-1)调整为新堆，
	然后再次将R[1]与无序区最后一个元素交换，得到新的无序区(R1,R2….Rn-2)和新的有序区(Rn-1,Rn)。
	不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。

	最佳情况：T(n) = O(nlogn) 最差情况：T(n) = O(nlogn) 平均情况：T(n) = O(nlogn)。
*/
#include"HeapSort.h"
size_t len;

vector<int> HeapSort(vector<int> &input_vector)
{
	len = input_vector.size();
	if (len < 1) return input_vector;
	//1、构建一个大顶堆
	buildMaxHeap(input_vector);
	while (len > 0)
	{
		swap(input_vector[0], input_vector[len - 1]);
		len--;
		adjustHeap(input_vector, 0);
	}
	return input_vector;
}
void buildMaxHeap(vector<int>& input_vector)//Floyd快速建堆算法
{
	for (int i = len / 2 - 1; i >= 0; i--) //从堆的最后一个内部节点开始调整
	{
		adjustHeap(input_vector, i);
	}
}
void adjustHeap(vector<int>& input_vector, size_t i)//完成自上而下的过滤
{
	int maxIndex = i;
	//如果有左子树，且左子树大于父节点则将最大指针指向左子树（如果一个节点有左孩子则它的秩为：2*i(v)+1）
	if (i * 2 + 1 < len && input_vector[i * 2 + 1] > input_vector[maxIndex])
		maxIndex = i * 2 + 1;
	//如果有右子树，且右子树大于父节点则将最大指针指向右子树（如果一个节点有右孩子则它的秩为：2*i(v)+2）
	if (i * 2 + 2 < len && input_vector[i * 2 + 2] > input_vector[maxIndex])
		maxIndex = i * 2 + 2;
	//基于堆序性如果父节点不是最大值，执行交换操作
	if (maxIndex != i)
	{
		swap(input_vector[i], input_vector[maxIndex]);
		adjustHeap(input_vector, maxIndex);
	}
}