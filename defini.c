#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "defini.h"

int leonardo(int k) {
    if (k < 2) {
        return 1;
    }
    return leonardo(k - 1) + leonardo(k - 2) + 1;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int start, int end) {
    int i = start;
    int j = 0;
    int k = 0;

    while (k < end - start + 1) {
        if (k & 0xAAAAAAAA) {
            j = j + i;
            i = i >> 1;
        }
        else {
            i = i + j;
            j = j >> 1;
        }

        k = k + 1;
    }

    while (i > 0) {
        j = j >> 1;
        k = i + j;
        while (k < end) {
            if (arr[k] > arr[k - i]) {
                break;
            }
            swap(&arr[k], &arr[k - i]);
            k = k + i;
        }

        i = j;
    }
}
int getNextGap(int gap) {
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}
//Main ###########################################
int* smooth_sort(int arr[], int n) {
    // Create a new array to store the sorted elements
    int* sortedArray = (int*)malloc(sizeof(int) * n);
    if (sortedArray == NULL) {
        // Allocation failed
        perror("Memory allocation failed");
        exit(1);
    }

    // Copy the original array into the sortedArray
    for (int i = 0; i < n; i++) {
        sortedArray[i] = arr[i];
    }

    int p = n - 1;
    int q = p;
    int r = 0;

    while (p > 0) {
        if ((r & 0x03) == 0) {
            heapify(sortedArray, r, q);
        }

        if (leonardo(r) == p) {
            r = r + 1;
        }
        else {
            r = r - 1;
            q = q - leonardo(r);
            heapify(sortedArray, r, q);
            q = r - 1;
            r = r + 1;
        }

        swap(&sortedArray[0], &sortedArray[p]);
        p = p - 1;
    }

    for (int i = 0; i < n - 1; i++) {
        int j = i + 1;
        while (j > 0 && sortedArray[j] < sortedArray[j - 1]) {
            swap(&sortedArray[j], &sortedArray[j - 1]);
            j = j - 1;
        }
    }

    return sortedArray;
}


//Main ###########################################
int* CocktailSort(int a[], int n) {
    int* sortedArray = (int*)malloc(sizeof(int) * n);
    if (sortedArray == NULL) {
        // Allocation failed
        perror("Memory allocation failed");
        exit(1);
    }

    // Copy the original array into the sortedArray
    for (int i = 0; i < n; i++) {
        sortedArray[i] = a[i];
    }

    int swapped = 1;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; ++i) {
            if (sortedArray[i] > sortedArray[i + 1]) {
                swap(&sortedArray[i], &sortedArray[i + 1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (sortedArray[i] > sortedArray[i + 1]) {
                swap(&sortedArray[i], &sortedArray[i + 1]);
                swapped = 1;
            }
        }

        ++start;
    }

    return sortedArray;
}



//Main ###########################################
int* oddEvenSort(int arr[], int n) {
    int* sortedArray = (int*)malloc(sizeof(int) * n);
    if (sortedArray == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        sortedArray[i] = arr[i];
    }

    int isSorted = 0;

    while (!isSorted) {
        isSorted = 1;

        for (int i = 1; i <= n - 2; i = i + 2) {
            if (sortedArray[i] > sortedArray[i + 1]) {
                int temp = sortedArray[i];
                sortedArray[i] = sortedArray[i + 1];
                sortedArray[i + 1] = temp;
                isSorted = 0;
            }
        }

        for (int i = 0; i <= n - 2; i = i + 2) {
            if (sortedArray[i] > sortedArray[i + 1]) {
                int temp = sortedArray[i];
                sortedArray[i] = sortedArray[i + 1];
                sortedArray[i + 1] = temp;
                isSorted = 0;
            }
        }
    }

    return sortedArray;
}
//Main ###########################################
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int* quick_Sort(int arr[], int n) {
    int* sortedArray = (int*)malloc(sizeof(int) * n);
    if (sortedArray == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        sortedArray[i] = arr[i];
    }

    quickSort(sortedArray, 0, n - 1);

    return sortedArray;
}
//Main ###########################################
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int* insertion_Sort(int arr[], int n) {
    int* sortedArray = (int*)malloc(sizeof(int) * n);
    if (sortedArray == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        sortedArray[i] = arr[i];
    }

    insertionSort(sortedArray, n);

    return sortedArray;
}

int* RandTab(int* arr, int* size, int createNewArray) {
    srand(time(NULL));

    if (createNewArray) {
        *size = 100;
        arr = (int*)malloc(sizeof(int) * (*size));
        if (arr == NULL) {
            // Allocation failed
            perror("Memory allocation failed");
            exit(1);
        }
    } else {
        *size += 100;
        arr = (int*)realloc(arr, sizeof(int) * (*size));
        if (arr == NULL) {
            // Reallocation failed
            perror("Memory reallocation failed");
            exit(1);
        }
    }

    // Add 100 random integers between -100 and 100 to the array
    for (int i = (*size - 100); i < (*size); i++) {
        arr[i] = rand() % 201 - 100;  
    }

    return arr;
}

//##############################

void executePythonScript() {
    const char* pythonInterpreter = "python3";
    const char* pythonScript = "main.py";

    char command[100];
    snprintf(command, sizeof(command), "%s %s", pythonInterpreter, pythonScript);

    int result = system(command);

    if (result == 0) {
        printf("Python script executed successfully.\n");
    } else {
        printf("Error executing the Python script.\n");
    }
}

int readCoefficientsFromFile(double coeff[4][5]) {
    FILE *file = fopen("res.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1; 
    }

    double temp_a, temp_b, temp_c, temp_d;

    for (int sort = 0; sort < 5; sort++) {
        // Read the values for each sort
        if (fscanf(file, "Sort %*d:\n"
                        "a: %lf\n"
                        "b: %lf\n"
                        "c: %lf\n"
                        "d: %lf\n\n", &temp_a, &temp_b, &temp_c, &temp_d) != 4) {
            printf("Error reading the values for Sort %d from the file.\n", sort + 1);
            fclose(file);
            return 2; 
        }

        coeff[0][sort] = temp_a;
        coeff[1][sort] = temp_b;
        coeff[2][sort] = temp_c;
        coeff[3][sort] = temp_d;
    }

    fclose(file);

    return 0; 
}

//##############################
void calcTemp(){
	int* Array = NULL;
	int* sortedArray = NULL;
	int size = 0;
	double mat[100][5];
	int i;
	Array = RandTab(Array, &size, 1);

	clock_t start, end;
    double cpu_time_used;

    for (int i = 0; i < 100; i++){
    	Array = RandTab(Array, &size, 0);
    	// smooth sort
        start = clock();
        sortedArray = smooth_sort(Array, size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        mat[i][0] = cpu_time_used;
	    // CocktailSort
	    start = clock();
	    sortedArray = CocktailSort(Array, size);
	    end = clock();
	    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	    mat[i][1] = cpu_time_used;
	    // oddEvenSort
	    start = clock();
	    sortedArray = oddEvenSort(Array, size);
	    end = clock();
	    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	    mat[i][2] = cpu_time_used;
        // quick Sort
        start = clock();
        sortedArray = quick_Sort(Array, size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        mat[i][3] = cpu_time_used;
        // insertion Sort
        start = clock();
        sortedArray = insertion_Sort(Array, size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        mat[i][4] = cpu_time_used;
    }
writeDataToFile("data.txt", mat, 100);
executePythonScript();
plotData();
}

void writeDataToFile(const char* filename, double mat[][5], int rows) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        fprintf(file, "%lf %lf %lf %lf %lf\n", mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4]);
    }

    fclose(file);
    
}

void plotData() {
    double coeff[4][5];
    readCoefficientsFromFile(coeff);

    FILE* gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe == NULL) {
        perror("Failed to open Gnuplot pipe");
        exit(1);
    }

    fprintf(gnuplotPipe, "set title 'Sorting Algorithms Performance'\n");
    fprintf(gnuplotPipe, "set xlabel 'Elements'\n");
    fprintf(gnuplotPipe, "set ylabel 'Execution Time (seconds)'\n");
    fprintf(gnuplotPipe, "set xrange [0:100]\n");  // Adjust the range for 1000 elements
    fprintf(gnuplotPipe, "set yrange [0:0.2]\n");
    fprintf(gnuplotPipe, "plot 'data.txt' using 1 with lines title 'Smooth Sort', \
                       %.20lf*x**3 + %.20lf*x**2 + %.20lf*x + %.20lf with lines title 'Smooth Sort Fit', \
                       %.20lf*x**3 + %.20lf*x**2 + %.20lf*x + %.20lf with lines title 'Cocktail Sort Fit', \
                       %.20lf*x**3 + %.20lf*x**2 + %.20lf*x + %.20lf with lines title 'Odd-Even Sort Fit', \
                       'data.txt' using 5 with lines title 'quick Sort', \
                       %.20lf*x**3 + %.20lf*x**2 + %.20lf*x + %.20lf with lines title 'insertion Sort Fit', \
                       %.20lf*x**3 + %.20lf*x**2 + %.20lf*x + %.20lf with lines title 'Quick Sort Fit'\n",
            coeff[0][0],coeff[1][0],coeff[2][0],coeff[3][0],
            coeff[0][1],coeff[1][1],coeff[2][1],coeff[3][1],
            coeff[0][2],coeff[1][2],coeff[2][2],coeff[3][2],
            coeff[0][3],coeff[1][3],coeff[2][3],coeff[3][3],
            coeff[0][4],coeff[1][4],coeff[2][4],coeff[3][4]  );

    pclose(gnuplotPipe);
}