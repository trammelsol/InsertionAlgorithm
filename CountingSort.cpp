/*
计数排序的基本思想：
	核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。 作为一种线性时间复杂度的排序，
	计数排序要求输入的数据必须是有确定范围的整数。
	计数排序(Counting sort)是一种稳定的排序算法。计数排序使用一个额外的数组C，
	其中第i个元素是待排序数组A中值等于i的元素的个数。然后根据数组C来将A中的元素排到正确的位置。
	它只能对整数进行排序。

计数排序的算法描述：
	找出待排序的数组中最大和最小的元素；
	统计数组中每个值为i的元素出现的次数，存入数组C的第i项；
	对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）；
	反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1。

	最佳情况：T(n) = O(n+k) 最差情况：T(n) = O(n+k) 平均情况：T(n) = O(n+k)。
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
	for (auto x : input_vector)//获取每个元素的个数在count中元素值为下标
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