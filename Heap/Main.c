#include "Heap.h"

void TestHeap()
{
	int arr[] = {53,17,78,9,45,65,88,22,33};
	Heap hp;
	HeapInit(&hp,arr,sizeof(arr)/sizeof(arr[0]));
	HeapPrint(&hp);

	HeapPush(&hp, 10);
	HeapPrint(&hp);

	HeapPush(&hp, 100);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
}
int main()
{
	TestHeap();
	return 0;
}