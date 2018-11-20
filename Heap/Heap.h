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

void HeapInit(Heap* hp,HPDataType* arr, int n);
void HeapPush(Heap* hp, HPDataType data);
void HeapPop(Heap* hp);
void HeapDestroy(Heap* hp);
int HeapSize(Heap* hp);
int HeapCapacity(Heap* hp);
HPDataType HeapTop(Heap* hp);
void HeapPrint(Heap* hp);