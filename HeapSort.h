#ifndef _HEAPSORT_H
#define _HEAPSORT_H
#include<iostream>
#include<vector>
using namespace std;

vector<int> HeapSort(vector<int>&);
void buildMaxHeap(vector<int>&);
void adjustHeap(vector<int>&, size_t );
#endif//_HEAPSORT_H