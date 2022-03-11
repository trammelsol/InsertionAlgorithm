// Vs2022_Test1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
#include"QuickSort.h"//快速排序头文件
#include"BubbleSort.h"//冒泡排序头文件
#include"SelectionSort.h"//选择排序头文件
#include"InsertionSort.h"//插入排序头文件
#include"ShellSort.h"//希尔排序头文件
#include"MergeSort.h"//归并排序头文件
#include"HeapSort.h"//堆排序头文件
#include"CountingSort.h"//计数排序头文件
#include"RadixSort.h"//基数排序头文件
*/
#include"BucketSort.h"//桶排序头文件

int main()
{
    vector<int> nums;
    for (int temp = 0; cin >> temp;)
    {
        nums.push_back(temp);
        if (cin.get() == '\n')
            break;
    }

    cout << "输入元素个数为：" << nums.size() << endl;

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << "    ";
    cout << "进行排序并输出" << endl;
    /*
    QuickSort(nums,0,nums.size()-1);//快速排序
    BubbleSort(nums);//冒泡排序
    SelectionSort(nums);//选择排序
    InsertionSort(nums);//插入排序
    ShellSort(nums);//希尔排序
    nums = MergeSort(nums);//归并排序
    HeapSort(nums);//堆排序
    CountingSort(nums);//计数排序
    RadixSort(nums);//基数排序
    */
    nums = BucketSort(nums, 12);//桶排序
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << "    ";
    system("pause");
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
