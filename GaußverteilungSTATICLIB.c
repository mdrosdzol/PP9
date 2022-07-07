#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"GauﬂverteilungSTATICLIB.h"

int AMOUNT=100;

void evaluate_gaussian_values(char* fileName) {

    FILE* file = fopen(fileName, "r");
    if(file == NULL) exit(0);
    char buffer[100];
    char *ptr;

    double gaussian_values[AMOUNT], sum = 0, tmp, expected_value, std_deviation;

    int i;
    for(i = 0; i < AMOUNT; i++) {

        fgets(buffer, 100, file);
        gaussian_values[i] = strtod(buffer, &ptr);
        //fscanf(file, "%lf ", &tmp, &gaussian_values[i]);
        printf("%lf\n", gaussian_values[i]);
    }

    for(i = 0; i < AMOUNT; i++) sum += gaussian_values[i];
    expected_value = sum/AMOUNT;

    for(i = 0; i<AMOUNT; i++){
		std_deviation = std_deviation + pow((gaussian_values[i]-expected_value),2);
	}

	printf("Expected value: %f\nStd deviation: %f\n", expected_value, sqrt(std_deviation/100));
}

int main() {

    evaluate_gaussian_values("text.txt");
}
