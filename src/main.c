#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int addition(int nums[], int args) {
    int result = nums[1];
    for (int i = 2; i < args; i++) {
        result += nums[i];
    }
    return result;
}

int subtraction(int nums[], int args) {
    int result = nums[1];
    for (int i = 2; i < args; i++) {
        result -= nums[i];
    }
    return result;
}

int multiplication(int nums[], int args) {
    int result = nums[1];
    for (int i = 2; i < args; i++) {
        result *= nums[i];
    }
    return result;
}

int division(int nums[], int args) {
    int result = nums[1];
    for (int i = 2; i < args; i++) {
        if (nums[i] == 0) {
            printf("Error: Division by zero!\n");
            return 0;
        }
        result /= nums[i];
    }
    return result;
}

int main(int argc, char *argv[]) {
    assert(argc > 2 && "argc > 2");

    int *nums = malloc(argc * sizeof(int));
    if (nums == NULL) {
        return 1;
    }

    for (int i = 0; i < argc; i++) {
        nums[i] = atoi(argv[i]);
    }

    int choice;
    while (1) {
        printf("\nCalculator made on C:\n");
        printf("\t1.Addition\n");
        printf("\t2.Subtraction\n");
        printf("\t3.Multiplication\n");
        printf("\t4.Division\n");
        printf("Enter: ");

        if (scanf("%d", &choice) != 1) {
            break; 
        }

        int result = 0;
        switch (choice) {
            case 1: result = addition(nums, argc); break;
            case 2: result = subtraction(nums, argc); break;
            case 3: result = multiplication(nums, argc); break;
            case 4: result = division(nums, argc); break;
            default: 
                printf("Invalid choice!\n");
                continue;
        }

        printf("\nResult: %d\n", result);
    }

    free(nums);
    return 0;
}

