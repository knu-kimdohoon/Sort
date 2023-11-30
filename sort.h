#pragma once
int compareCharLength(void* argu1, void* argu2) {
	char* a, * b;
	a = (char*)argu1, b = (char*)argu2;
	int k = strlen((char*)argu1) - strlen((char*)argu2);
	//printf("%s[%d] - %s[%d] = %d\n", a, strlen(a), b, strlen(b), k);
	//argu1이 argu2보다 더 길면 음수를 출력한다. 
	return -1*(strlen((char*)argu1) - strlen((char*)argu2));
}

int compareCharLength_forQuickSort(void* argu1, void* argu2) {
	char* a, * b;
	a = (char*)argu1, b = (char*)argu2;
	int k = strlen((char*)argu1) - strlen((char*)argu2);
	//printf("%s[%d] - %s[%d] = %d\n", a, strlen(a), b, strlen(b), k);
	//argu1이 argu2보다 더 길면 음수를 출력한다. 
	return (strlen((char*)argu1) - strlen((char*)argu2));
}

int compareCharSequence(void* argu1, void* argu2) {
	char* a;
	char* b;
	
	a = (char*)argu1;
	b = (char*)argu2;
	//printf("%c\n%c", a[0], b[0]);
	//printf("%c[%d] - %c[%d] = %d\n", a[0], a[0], b[0], b[0], a[0] - b[0]);
	return -1*((int)a[0] - (int)b[0]);
}

void selectionSort_c(char* list[], int n) {
	int i = 0, j = 0;
	int smallest = 0;
	char* temp;
	for (i = 0; i < n - 1; i++) {
		smallest = i;
		for (j = i + 1; j < n; j++) {
			if (compareCharSequence(list[j], list[smallest]) > 0) smallest = j;
			else if (compareCharSequence(list[j], list[smallest]) < 0) continue;
			else if (compareCharSequence(list[j], list[smallest]) == 0 && compareCharLength(list[j], list[smallest]) > 0) smallest = j;
			else if (compareCharSequence(list[j], list[smallest]) == 0 && compareCharLength(list[j], list[smallest]) < 0) continue;
			else continue;
		}
		temp = list[i];
		list[i] = list[smallest];
		list[smallest] = temp;
	}
}

// 1. heap 구현
// 2. heap으로 heapsort하기
void heapSort_c(char* list[], int n) {

}

void insertionSort(char* list[], int n) {
	int i = 0, j = 0;
	char* hold;
	for (i = 1; i < n; i++) {
		hold = list[i];
		for (j = i; j > 0 && compareCharSequence((void*)hold, (void*)list[j-1])>0; j--)
			list[j] = list[j - 1];
		list[j] = hold;
	}
}

void bubbleSort(char* list[], int n) {
	int i = 0, j=0;
	char* temp;
	int sorted = false;

	for (i = 0; i < n && !sorted; i++) {
		for (j = n - 1, sorted = true; j > i; j--) {
			if (compareCharLength((void*)list[j], (void*)list[j - 1]) > 0) {
				sorted = false;
				temp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = temp;
			}
		}
	}
}

void swap(char* argu1, char* argu2) {
	char* temp;
	temp = argu1;
	argu1 = argu2;
	argu2 = temp;
}

void quickSort(char* list[], int left, int right) {
	//printf("left : %d right : %d", left, right);
	int i = 0, j = 0;
	char* pivot='\0';
	int len = 0, len1 = 0;
	if (left < right) {
		i = left, j = right;
		pivot = list[left];
		do {
			do
			{
				i++;
				len = compareCharLength_forQuickSort(list[i], pivot);
				//compareCharLength 가 음수면 list[i]가 pivot보다 길이가 길다
			}
			while (len < 0);
			do
			{
				j--;
				len1 = compareCharLength_forQuickSort(list[j], pivot);
				//compareCharLength 가 양수면 list[i]가 pivot보다 길이가 짧다
			}
			while ( len1 > 0);
			if (i < j) 
				swap(list[i], list[j]);
		} while (i < j);
		swap(list[left], list[j]);

		quickSort(list, left, j - 1);
		quickSort(list, j + 1, right);
	}
}