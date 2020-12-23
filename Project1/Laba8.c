//#include <stdlib.h>
//#include <stdio.h>
//#include <locale.h>
//
//// Метод чтобы удобно менять элементы местами
//void swap(int *a, int *b)
//{
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//// Сортировка пузырьком
//void BubleSort(int arr[], int n)
//{
//	int i;
//	for (i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//				swap(&arr[j], &arr[j + 1]);
//		}
//	}
//
//	printf("\nМассив  отсортированный пузырьком: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//}
//
//// Сортировка перемешиванием(шейкерная сортировка)
//void ShakerSort(int arr[], int n)
//{
//	int p, i;
//	for (p = 1; p <= n / 2; p++)
//	{
//		for (i = p - 1; i < n - p; i++)
//			if (arr[i] > arr[i + 1])
//				swap(&arr[i], &arr[i + 1]);
//		for (i = n - p - 1; i >= p; i--)
//			if (arr[i] < arr[i - 1])
//				swap(&arr[i], &arr[i - 1]);
//	}
//
//	printf("\nМассив отсортированный перемешиванием: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//}
//
//// Сортировка расчёской
//int newgap(int gap)
//{
//	gap = (gap * 10) / 13;
//	if (gap == 9 || gap == 10)
//		gap = 11;
//	if (gap < 1)
//		gap = 1;
//	return gap;
//}
//void CombSort(int arr[], int n)
//{
//	int gap = n;
//	int i;
//	for (;;)
//	{
//		gap = newgap(gap);
//		int swapped = 0;
//		for (i = 0; i < n - gap; i++)
//		{
//			int j = i + gap;
//			if (arr[i] > arr[j])
//			{
//				swap(&arr[i], &arr[j]);
//				swapped = 1;
//			}
//		}
//		if (gap == 1 && !swapped)
//			break;
//	}
//
//	printf("\nМассив отсортированный расчёской: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//}
//
//// Сортировка вставками
//void InsertionSort(int arr[], int n)
//{
//	int newElement, location, i;
//
//	for (i = 1; i < n; i++)
//	{
//		newElement = arr[i];
//		location = i - 1;
//		while (location >= 0 && arr[location] > newElement)
//		{
//			arr[location + 1] = arr[location];
//			location = location - 1;
//		}
//		arr[location + 1] = newElement;
//	}
//
//	printf("\nМассив отсортированный вставками: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//}
//
//// Сортировка выбором
//void SelectionSort(int arr[], int n)
//{
//	int min, i;
//	
//	for (i = 0; i < n - 1; i++)
//	{
//		min = i;
//		for (int j = i + 1; j < n; j++) 
//		{
//			if (arr[j] < arr[min])
//				min = j;       
//		}
//		swap(&arr[i], &arr[min]);
//	}
//
//	printf("\nМассив отсортированный выбором: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//}
//
//// Быстрая сортировка
//void QuickSort(int arr[], int first, int last)
//{
//	if (first < last)
//	{
//		int left = first, right = last, middle = arr[(left + right) / 2];
//		do
//		{
//			while (arr[left] < middle) left++;
//			while (arr[right] > middle) right--;
//			if (left <= right)
//			{
//				swap(&arr[left], &arr[right]);
//				left++;
//				right--;
//			}
//		}while (left <= right);
//		QuickSort(arr, first, right);
//		QuickSort(arr, left, last);
//	}
//}
//
//// Сортировка слиянием
//void MergeSort(int arr[], int n)
//{
//	int step = 1;  
//	int *temp = (int*)malloc(n * sizeof(int)); 
//	while (step < n)
//	{
//		int index = 0;
//		int l = 0;
//		int m = l + step;
//		int r = l + step * 2;
//		do
//		{
//			m = m < n ? m : n;
//			r = r < n ? r : n;
//			int i1 = l, i2 = m;
//			for (; i1 < m && i2 < r; )
//			{
//				if (arr[i1] < arr[i2])
//				{
//					temp[index++] = arr[i1++];
//				}
//				else
//				{
//					temp[index++] = arr[i2++];
//				}
//			}
//			while (i1 < m) 
//				temp[index++] = arr[i1++]; 
//			while (i2 < r) 
//				temp[index++] = arr[i2++]; 
//			l += step * 2;
//			m += step * 2;
//			r += step * 2;
//		}while (l < n); 
//		for (int i = 0; i < n; i++)
//			arr[i] = temp[i];
//		step *= 2;
//	}
//}
//
//// Пирамидальная сортировка
//void SiftDown(int arr[], int root, int bottom)
//{
//	int maxChild; 
//	int done = 0; 
//	while ((root * 2 <= bottom) && (!done))
//	{
//		if (root * 2 == bottom)
//			maxChild = root * 2;
//		else if (arr[root * 2] > arr[root * 2 + 1])
//			maxChild = root * 2;
//		else
//			maxChild = root * 2 + 1;
//
//		if (arr[root] < arr[maxChild])
//		{
//			int temp = arr[root];
//			arr[root] = arr[maxChild];
//			arr[maxChild] = temp;
//			root = maxChild;
//		}
//		else
//			done = 1;
//	}
//}
//void HeapSort(int arr[], int n)
//{
//	for (int i = (n / 2) - 1; i >= 0; i--)
//		SiftDown(arr, i, n - 1);
//
//	for (int i = n - 1; i >= 1; i--)
//	{
//		int temp = arr[0];
//		arr[0] = arr[i];
//		arr[i] = temp;
//		SiftDown(arr, 0, i - 1);
//	}
//}
//
//void main()
//{
//	setlocale(LC_ALL, "Rus");
//	int array[100], n, i;
//	printf("Введите количество элементов ");
//	scanf_s("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		printf("Значение %d-го элемента: ", i+1);
//		scanf_s("%d", &array[i]);
//	}
//
//	// Пузырьковая сортировка и её улучшения
//    //BubleSort(array, n);  // - вызов сортировки пузырьком
//	//ShakerSort(array, n); // - вызов шейкерной сортировки
//	//CombSort(array, n); // - вызов сортировки расчёской
//
//	// Простые сортировки и её улучшения 
//	//InsertionSort(array, n); // - вызов сортировки вставками
//	//SelectionSort(array, n); // - вызов сортировки выбором
//
//
//	// Эффективные сортировки
////(из-за их рекурсивности вывод отсортированного массива сделан не в самом методе, а в коде, сразу после вызова)
//
//	/*QuickSort(array, 0, n-1); // - вызов быстрой сортировки
//	printf("\nМассив отсортированный быстрой сортировкой: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", array[i]);*/
//
//		/*MergeSort(array,n); // - вызов сортировки слиянием
//	printf("\nМассив отсортированный сортировкой слиянием: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", array[i]);*/
//
//		/*HeapSort(array, n); // - вызов пирамидальной сортировки
//	printf("\nМассив отсортированный пирамидальной сортировкой: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", array[i]);*/
//}