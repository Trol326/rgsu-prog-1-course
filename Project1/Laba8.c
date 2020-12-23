//#include <stdlib.h>
//#include <stdio.h>
//#include <locale.h>
//
//// ����� ����� ������ ������ �������� �������
//void swap(int *a, int *b)
//{
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//// ���������� ���������
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
//	printf("\n������  ��������������� ���������: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//}
//
//// ���������� ��������������(��������� ����������)
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
//	printf("\n������ ��������������� ��������������: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//}
//
//// ���������� ���������
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
//	printf("\n������ ��������������� ���������: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//}
//
//// ���������� ���������
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
//	printf("\n������ ��������������� ���������: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//}
//
//// ���������� �������
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
//	printf("\n������ ��������������� �������: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//}
//
//// ������� ����������
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
//// ���������� ��������
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
//// ������������� ����������
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
//	printf("������� ���������� ��������� ");
//	scanf_s("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		printf("�������� %d-�� ��������: ", i+1);
//		scanf_s("%d", &array[i]);
//	}
//
//	// ����������� ���������� � � ���������
//    //BubleSort(array, n);  // - ����� ���������� ���������
//	//ShakerSort(array, n); // - ����� ��������� ����������
//	//CombSort(array, n); // - ����� ���������� ���������
//
//	// ������� ���������� � � ��������� 
//	//InsertionSort(array, n); // - ����� ���������� ���������
//	//SelectionSort(array, n); // - ����� ���������� �������
//
//
//	// ����������� ����������
////(��-�� �� ������������� ����� ���������������� ������� ������ �� � ����� ������, � � ����, ����� ����� ������)
//
//	/*QuickSort(array, 0, n-1); // - ����� ������� ����������
//	printf("\n������ ��������������� ������� �����������: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", array[i]);*/
//
//		/*MergeSort(array,n); // - ����� ���������� ��������
//	printf("\n������ ��������������� ����������� ��������: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", array[i]);*/
//
//		/*HeapSort(array, n); // - ����� ������������� ����������
//	printf("\n������ ��������������� ������������� �����������: ");
//	for (i = 0; i < n; i++)
//		printf("%d ", array[i]);*/
//}