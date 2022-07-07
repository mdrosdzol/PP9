#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void print_gaussian_dist(int expected_value, int std_deviation, int amount_of_values, FILE *output_stream) {


    double first_random, secound_random, ep = 1.0, random_num, std_num1, std_num2;
    int tmp = 0, i;

    amount_of_values = amount_of_values < 100 ? 100 : amount_of_values;

    for(i = 0; i < amount_of_values; i++) {

        if(tmp != 0) {

            std_num1 = std_num2;
            tmp=0;
        } else {


            while(ep>=1.0) {
                first_random = (double)rand() / RAND_MAX * 2 - 1;
                secound_random = (double)rand() / RAND_MAX * 2 - 1;
                ep = pow(first_random, 2) + pow(secound_random, 2);
            }

            ep = sqrt((-2.0*log(ep)) / ep);
            std_num1 = first_random * ep;
            std_num2 = secound_random * ep;
            tmp=1;
        }
        fprintf(output_stream, "%f \n", expected_value + std_deviation * std_num1);
    }
}
