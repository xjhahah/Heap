#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _arr;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* arr, int n);
void HeapPush(Heap* hp, HPDataType data);
void HeapPop(Heap* hp);
void HeapDestroy(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapCapacity(Heap* hp);
int HeapEmpty(Heap* hp);
void HeapSort(HPDataType* arr, int n);
void HeapPrint(Heap* hp);
