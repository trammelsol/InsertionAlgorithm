/*
桶排序的基本思想：
	桶排序是计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。
	桶排序 (Bucket sort)的工作的原理：假设输入数据服从均匀分布，将数据分到有限数量的桶里，
	每个桶再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排

桶排序的算法描述：
	人为设置一个BucketSize，作为每个桶所能放置多少个不同数值（例如当BucketSize==5时，该桶可以存放
	｛1,2,3,4,5｝这几种数字，但是容量不限，即可以存放100个3）；
	遍历输入数据，并且把数据一个一个放到对应的桶里去；
	对每个不是空的桶进行排序，可以使用其它排序方法，也可以递归使用桶排序；
	从不是空的桶里把排好序的数据拼接起来。
	注意，如果递归使用桶排序为各个桶排序，则当桶数量为1时要手动减小BucketSize增加下一循环桶的数量，
	否则会陷入死循环，导致内存溢出。

	最佳情况：T(n) = O(n+k) 最差情况：T(n) = O(n+k) 平均情况：T(n) = O(n2)。
*/

#include"BucketSort.h"

vector<int> BucketSort(vector<int>& input_vector, int bucketSize)
{
	if (input_vector.size() < 2)return input_vector;
	int max = input_vector[0], min = input_vector[0];
	//找到最大最小值
	for (size_t i = 1; i < input_vector.size(); i++)
	{
		if (input_vector[i] > max) max = input_vector[i];
		if (input_vector[i] < min) min = input_vector[i];
	}
	int bucketCount = (max - min) / bucketSize + 1;//区间跨度 = （最大值-最小值）/ （桶的数量 - 1）
	vector<vector<int>>bucketArr;
	vector<int>resultArr;
	for (size_t i = 0; i < bucketSize; i++)//构造桶结构
	{
		vector<int> a_vector;
		bucketArr.push_back(a_vector);
	}
	for (size_t i = 0; i < input_vector.size(); i++)//初始化桶结构
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