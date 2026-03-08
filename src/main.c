#include <stdio.h>

void inputClassScores(float scores[], int size, int classNum) {
		printf("\nВведите средние оценки для %d учеников %d класса:\n", size, classNum);
		for (int i = 0; i < size; i++) {
				printf("Ученик %d: ", i + 1);
				scanf("%f", &scores[i]);
		}
}

// Функция для сортировки массива по убыванию 
void sortDescending(float arr[], int size) {
		for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
						if (arr[j] < arr[j + 1]) {
								float temp = arr[j];
								arr[j] = arr[j + 1];
								arr[j + 1] = temp;
						}
				}
		}
}


float findFifthBest(float scores[], int size) {
		float temp[20];
		for (int i = 0; i < size; i++) {
				temp[i] = scores[i];
		}

		sortDescending(temp, size);

		return temp[4];
}

int main() {
		const int STUDENTS_PER_CLASS = 20;
		float classA[20], classB[20];

		printf("Программа сравнения 5-х лучших учеников\n");
		
		inputClassScores(classA, STUDENTS_PER_CLASS, 1);
		inputClassScores(classB, STUDENTS_PER_CLASS, 2);

		float fifthA = findFifthBest(classA, STUDENTS_PER_CLASS);
		float fifthB = findFifthBest(classB, STUDENTS_PER_CLASS);

		printf("РЕЗУЛЬТАТЫ:\n");
		printf("1-й класс (5-й лучший): %.2f\n", fifthA);
		printf("2-й класс (5-й лучший): %.2f\n", fifthB);
		

		if (fifthA > fifthB) {
				printf("В 1-м классе 5-й лучший ученик имеет бОльшую оценку!\n");
		} else if (fifthA < fifthB) {
				printf("Во 2-м классе 5-й лучший ученик имеет бОльшую оценку!\n");
		} else {
				printf("Оценки равны!\n");
		}

		return 0;
}