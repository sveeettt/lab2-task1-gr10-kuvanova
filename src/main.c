#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_SIZE 20

int compare(const void *a, const void *b) {
		float fa = *(float*)a;
		float fb = *(float*)b;
		if (fa < fb) return 1;
		if (fa > fb) return -1;
		return 0;
}


float findKthBest(float grades[], int n, int k) {
		
		float *temp = (float*)malloc(n * sizeof(float));
		if (temp == NULL) {
				printf("Ошибка выделения памяти!\n");
				return -1;
		}

		for (int i = 0; i < n; i++) {
				temp[i] = grades[i];
		}

		qsort(temp, n, sizeof(float), compare);

		float result = temp[k-1];

		free(temp);
		return result;
}


void generateGrades(float grades[], int n, int classNum) {
		printf("Класс %d: ", classNum);
		for (int i = 0; i < n; i++) {
			  grades[i] = (rand() % 101) / 10.0;  
				printf("%.1f ", grades[i]);
		}
		printf("\n");
}

// Функция для вывода отсортированных оценок
void printSorted(float grades[], int n, int classNum) {
		
		float *temp = (float*)malloc(n * sizeof(float));
		for (int i = 0; i < n; i++) {
				temp[i] = grades[i];
		}

		qsort(temp, n, sizeof(float), compare);

		printf("Класс %d (по убыванию): ", classNum);
		for (int i = 0; i < n; i++) {
				printf("%.1f ", temp[i]);
		}
		printf("\n");

		free(temp);
}

int main(int argc, char *argv[]) {
		int n = DEFAULT_SIZE;

		if (argc > 1) {
				n = atoi(argv[1]);
		}

		if (n < 5) {
				printf("Ошибка: в классе должно быть минимум 5 учеников!\n");
				printf("Использование: %s [количество учеников]\n", argv[0]);
				printf("Пример: %s 20\n", argv[0]);
				return 1;
		}

		printf("==========================================================\n");
		printf("   Вариант 33: Сравнение 5-х лучших учеников\n");
		printf("==========================================================\n");
		printf("Количество учеников в каждом классе: %d\n", n);
		printf("(оценки генерируются случайно от 0.0 до 10.0)\n\n");


		srand(time(NULL));
	
		float *class1 = (float*)malloc(n * sizeof(float));
		float *class2 = (float*)malloc(n * sizeof(float));

		if (class1 == NULL || class2 == NULL) {
				printf("Ошибка выделения памяти!\n");
				return 1;
		}

		
		printf("--- Исходные данные (сгенерированные оценки) ---\n");
		generateGrades(class1, n, 1);
		generateGrades(class2, n, 2);

		
		printf("\n--- Оценки, отсортированные по убыванию ---\n");
		printSorted(class1, n, 1);
		printSorted(class2, n, 2);

		
		float fifth1 = findKthBest(class1, n, 5);
		float fifth2 = findKthBest(class2, n, 5);

		
		printf("\n--- Результаты ---\n");
		printf("5-й лучший ученик 1-го класса: %.2f\n", fifth1);
		printf("5-й лучший ученик 2-го класса: %.2f\n", fifth2);


		if (fifth1 > fifth2) {
				printf(" В 1-м классе у пятого из самых успевающих учеников ");
				printf("средняя оценка БОЛЬШЕ (%.2f > %.2f)\n", fifth1, fifth2);
		} else if (fifth1 < fifth2) {
				printf(" Во 2-м классе у пятого из самых успевающих учеников ");
				printf("средняя оценка БОЛЬШЕ (%.2f > %.2f)\n", fifth2, fifth1);
		} else {
				printf("В обоих классах у пятых учеников оценки РАВНЫ (%.2f)\n", fifth1);
		}
		printf("==========================================================\n");

		
		free(class1);
		free(class2);

		return 0;
}