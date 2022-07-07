#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include"GauﬂverteilungHLib.h"
#include"GauﬂverteilungSTATICLIB.h"

char* fileName;

void openFile() {

    FILE* file = fopen(fileName, "w");

    if(file == NULL) exit(0);

    printf("File opened!\n");

    int expected_value, std_deviation, amount_of_values;

    printf("\nExpected value: ");
    scanf(" %d", &expected_value);

    printf("\nStd deviation: ");
    scanf(" %d", &std_deviation);

    printf("\nAmount of values: ");
    scanf(" %d", &amount_of_values);

    print_gaussian_dist(expected_value, std_deviation, amount_of_values, file);
    fclose(file);
    exit(0);
}

void analyseValues() {

    evaluate_gaussian_values(fileName);
}

int main(int argc, char* argv[]) {

    char inputKey;
    while((inputKey = getopt(argc, argv, "h v e: f:")) != -1) {

        switch(inputKey) {

            case 'v':

                printf("Version: 1.0-SNAPSHOT");
                break;

            case 'f':
                fileName = optarg;
                openFile();
                break;

            case 'e':
                fileName = optarg;
                analyseValues();
                break;

            case 'h':
            default:
               printf("\nNutze:\nh - zur Anzeige dieser Hilfe\nv - um die Version einzusehen\nf:<file> - um eine Output-File festzulegen\ne - um die Werte zu Analysieren\n");
                break;
        }
    }


}
