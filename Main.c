#include "Main.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Human
{
	float weight;
	float height;
};

float BodyMassIndexCalculate(float height, float weight) {
	float value;
	value = weight / (height*height);
	return value;
}

int MaximumOfNumbers(int CountOfNumbers) {
	int value = 0;
	int number;

	for (int i = 0; i < CountOfNumbers; i++) {
		printf("Enter the number:\n");
		scanf("%i/n", &number);
		if (number > value) value = number;
	}
	return value;
}

void Exchange(int* a, int* b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void randomizerWithRand(int countOfNumbers) {
	srand(time(NULL));
	for (int i = 0; i < countOfNumbers; i++) {
		printf("%d\n", rand() % countOfNumbers + 1);
	}
}

void randomizer(int firstNumber, int lastNumber) {
	int randomNumber = firstNumber;
	for (int i = firstNumber; i <= lastNumber; i++) {
		
		randomNumber = (2 * randomNumber + 3) % lastNumber;
		printf("%d\n", randomNumber);
	}
}

int Truncate(int number, int rank) {
	return number / rank;
}

int AmorphousNumber(int number, int number2) {
	int value = number;
	for (int i = 10; i < number; i = i * 10) {
		value =number - Truncate(number, i)*i;
		if (number2 == value) return 1;
	}
	return 0;
}

void SearchAmorphusNumbers(int number) {
	for (int i = 0; i <= number; i++) {
		
			if (AmorphousNumber(i*i,i) == 1) printf("Amorphus number: %i\n", i);
		
	}
}

int Calculate(int number, int count) {
	if (number == 20) {
		count++;
		return count;
	}
	if (number + 1 <= 20) {
		count = Calculate(number + 1, count);
	}
	
	if (number * 2 <= 20) {
		count = Calculate(number * 2, count);

	}
	return count;
}

int BinarySearch(int* array, int index, int maxIndex, int minIndex, int request) {
	
	if (array[index] == request) return index;
	else
	{
		if (maxIndex - index == 1 || index - minIndex == 1) return -1;
		if (array[index] < request) {
			return BinarySearch(array, (maxIndex + index) / 2, maxIndex, index,request);
		}
		if (array[index] > request) {
			return BinarySearch(array, (minIndex + index) / 2, index, minIndex, request);
		}
	}
	return -1;
}

void fillInTheArray(int* array, int length) {
	for (int i = 0; i < length; i++)
	{
		array[i] = i;
	}
}

void fillInTheArrayRandom(int* array, int length) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % 10 + 1;
	}
}

void ShakersSort(int* array, int minIndex, int maxIndex) {
	for (int i = minIndex; i < maxIndex-1; i++) {
		if (array[i] > array[i + 1]) Exchange(&array[i], &array[i + 1]);
		
	}
	for (int i = maxIndex-1; i > minIndex; i--) {
		if (array[i] < array[i - 1]) Exchange(&array[i], &array[i - 1]);

	}

	if (maxIndex - minIndex > 1) ShakersSort(array, minIndex + 2, maxIndex - 2);
}

int main() {
	
	//3
	int sizeOfArray;
	int request;
	printf("Enter size of array:\n");
	scanf("%i", &sizeOfArray);
	printf("Enter your request:\n");
	scanf("%i", &request);
	int array[100];

	fillInTheArray(&array, sizeOfArray);
	printf("Index your request: %i\n", BinarySearch(&array,sizeOfArray/2, sizeOfArray-1, 0, request));

	//2

	int arrayRandom[100];

	fillInTheArrayRandom(&arrayRandom, sizeOfArray);
	ShakersSort(&arrayRandom,0, sizeOfArray);


	/*int sum = 1;
	while (sum!=0)
	{
		printf("Enter your number:\n");
		scanf("%i", &sum);
		printf("result %i\n", Calculate(sum, 0));
	}
	*/
	
//First
	/*struct Human Human;
	int a;
	int b;
	int c;

	//inner
	printf("I'll calculate your body mass index\n");
	printf("How tall are you?\n");
	scanf("%f", &Human.height);
	printf("Your height: %f\n", Human.height);
	printf("What's your weight?\n");
	scanf("%f", &Human.weight);
	printf("Your weight: %f\n", Human.weight);

	//viewer
	printf("your body mass index: %f\n", BodyMassIndexCalculate(Human.height,Human.weight));

	//12

	printf("I'll calculate the largest of the three numbers\n");

	printf("The largest of the four numbers: %i\n", MaximumOfNumbers(3));

	//13
	printf("randomizer With Rand()\n");
	randomizerWithRand(100);
	printf("randomizer\n");
	randomizer(1, 100);

	//14
	printf("I'll search amorphus numbers\n");
	printf("Enter the number :\n");
	scanf("%i", &c);
	SearchAmorphusNumbers(c);

	//Third
	printf("I'll change two numbers\n");
	printf("Enter the number a:\n");
	scanf("%i", &a);
	printf("Enter the number b:\n");
	scanf("%i", &b);
	Exchange(&a,&b);
	printf("I did exchenge a: %i\n", a);
	printf("And b: %i\n", b);*/

	

	return 0;
}