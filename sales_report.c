#include <stdio.h>

#define NUM_MONTHS 12

// All of my Function prototypes
void loadSalesData(float sales[], const char *filename);
void printMonthlyReport(float sales[]);
void printSummaryReport(float sales[]);
void printMovingAverage(float sales[]);
void PrintSalesHightoLow(float sales[]);

int main() {
    float sales[NUM_MONTHS];
    const char *filename = "sample_input.txt"; //Input File

    //Function Calls
    loadSalesData(sales, filename);
    printMonthlyReport(sales);
    printSummaryReport(sales);
    printMovingAverage(sales);
    PrintSalesHightoLow(sales); 

    return 0; // Indicates Program works! Yippee!
}
//Helps with opening file
void loadSalesData(float sales[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file: %s\n", filename);
        return;
    }

    // storing monthly sales into a sales list
    for (int i = 0; i < NUM_MONTHS; i++) {
        fscanf(file, "%f", &sales[i]);
    }
    fclose(file);
}
// Printing the monthly sales report using the data in the sales list
void printMonthlyReport(float sales[]) {
    const char *months[NUM_MONTHS] = {
       "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
       "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    printf("Monthly Sales Report:\n");
    printf("Month   Sales\n");
    
    // Print each month with sales
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%s\t$%.2f\n", months[i], sales[i]); // This is used to print the month name with a tab, and sales amount with two decimal places  
    }
}
// Finds and outputs the min/max/average sales values
void printSummaryReport(float sales[]) {
    float min = sales[0], max = sales[0], total = 0;
    int minMonth = 0, maxMonth = 0;

    // Loop to find min, max, and total
    for (int i = 0; i < NUM_MONTHS; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
        total += sales[i];
    }

    float avg = total / NUM_MONTHS;
    const char *months[NUM_MONTHS] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    printf("\nSummary:\n");
    printf("Min Sales: $%.2f (%s)\n", min, months[minMonth]);
    printf("Max Sales: $%.2f (%s)\n", max, months[maxMonth]);
    printf("Average: $%.2f\n", avg);
}
// Finds and outputs the six-month moving averages from the sales data
void printMovingAverage(float sales[]) {
    printf("\nSix-Month Moving Average:\n");

    // Loop for moving averages within the six months
    for (int i = 0; i <= NUM_MONTHS - 6; i++) {
        float sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        float avg = sum / 6;
        const char *months[NUM_MONTHS] = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };
        printf("%s - %s: $%.2f\n", // prints start month - end month: average
               months[i], 
               months[i + 5], 
               avg);
    }
}

// Prints monthly sales from highest to lowest 
void PrintSalesHightoLow(float sales[]) {
    float sortedSales[NUM_MONTHS];
    const char *months[NUM_MONTHS] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    const char *sortedMonths[NUM_MONTHS];

    // Copy sales and months into temp arrays for sorting
    for (int i = 0; i < NUM_MONTHS; i++) {
        sortedSales[i] = sales[i];
        sortedMonths[i] = months[i];
    }

    // Sort sales and track months
    for (int i = 0; i < NUM_MONTHS - 1; i++) {
        for (int j = i + 1; j < NUM_MONTHS; j++) {
            if (sortedSales[i] < sortedSales[j]) {
                float tempSale = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = tempSale;

                const char *tempMonth = sortedMonths[i];
                sortedMonths[i] = sortedMonths[j];
                sortedMonths[j] = tempMonth;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month   Sales\n");

    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%s\t$%.2f\n", sortedMonths[i], sortedSales[i]);
    }
}
