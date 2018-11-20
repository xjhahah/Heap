#include "Heap.h"

//向下调整
void Swap(HPDataType* left, HPDataType* right)
{
	HPDataType tmp;
	tmp = *left;
	*left = *right;
	*right = tmp;
}
void AdjustDown(HPDataType* arr, int n,int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选左右孩子中较大的
		if (child + 1 < n && arr[child + 1] > arr[child])
		{
			//如果右孩子大于做孩子，标记有右孩子，更新child
			++child;
		}
		//
		else if (arr[child] > arr[parent])
		{
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* hp, HPDataType* arr, int n)
{
	int i = 0;
	assert(hp&&arr);
	hp->_arr = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_capacity = hp->_size = n;
	for (; i < n; ++i)
	{
		hp->_arr[i] = arr[i];
	}
	//调整堆为小堆
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_arr, hp->_size, i);
	}

}
//向上调整
void AdjustUp(HPDataType* arr, int n, int child)
{
	assert(arr);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[parent] < arr[child])
		{
			Swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void HeapPush(Heap* hp, HPDataType data)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_arr = (HPDataType*)realloc(hp->_arr, sizeof(HPDataType)*hp->_capacity);
	}
	hp->_arr[hp->_size++] = data;
	//向上调整
	AdjustUp(hp->_arr, hp->_size,hp->_size-1);
}
void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->_arr[0], &hp->_arr[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_arr, hp->_size, 0);
}
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->_arr);
	hp->_arr = NULL;
	hp->_size = hp->_capacity = 0;
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
int HeapCapacity(Heap* hp)
{
	assert(hp);
	return hp->_capacity;
}
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_arr[0];
}
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_arr[i]);
	}
	printf("\n");
}