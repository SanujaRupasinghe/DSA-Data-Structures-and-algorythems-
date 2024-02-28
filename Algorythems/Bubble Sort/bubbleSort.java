import java.util.Scanner;

public class bubbleSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array: ");
        int size = sc.nextInt();
        System.out.print("size is ");
        System.out.println(size);

        int[] numbers = new int[size];
        System.out.println("Enter the elements of the array: ");

        for (int i = 0; i < size; i++) {
            numbers[i] = sc.nextInt();
        }
        sc.close();
        System.out.println("Before sorting: ");
        printArray(numbers, size);
        bubbleSort3(numbers, size);                          //choose 1 or 2 or 3 sorting algorithm
        System.out.println("After sorting: ");
        printArray(numbers, size);
    }


    static void printArray(int[] A, int size){
        for(int i = 0; i < size; i++){
            System.out.print(A[i] + " ");
        }
        System.out.println();
    }

    // no optimization iterate through sorted elements in the array also
    // worst case time complexity is O(n^2)
    // average case time complexity is O(n^2)
    // best case time complexity is O(n)
    static void bubbleSort1(int[] A, int size){
        for (int i = 0; i < size - 1; i++){
            for (int j = 0; j < size - 1; j++){
                if (A[j] > A[j + 1]){
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
        }
    }

    // optimization iterate through unsorted elements in the array only 
    // worst case time complexity is O(n^2)
    // average case time complexity is O(n^2)
    // best case time complexity is O(n)
    static void bubbleSort2(int A[], int size){
        for (int i = 0; i < size - 1; i++){
            for (int j = 0; j < size - 1 - i; j++){
                if (A[j] > A[j + 1]){
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
        }
    }

    // optimization iterate through unsorted elements in the array only and break the loop if no swapping is done 
    // so that we can reduce the time complexity
    // worst case time complexity is O(n^2)
    // average case time complexity is O(n^2)
    // best case time complexity is O(n)
    static void bubbleSort3(int A[], int size){
        boolean swapped;
        for (int i = 0; i < size - 1; i++){
            swapped = false;
            for (int j = 0; j < size - 1 - i; j++){
                if (A[j] > A[j + 1]){
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                    swapped = true;
                }
            }
            if (swapped == false){
                break;
            }
        }
    }

}


