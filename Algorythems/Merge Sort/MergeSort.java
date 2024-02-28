import java.util.Random;

public class MergeSort {
    public static void main(String[] args) { 
        Random rand = new Random();
        int[] numbers = new int[100000];

        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = rand.nextInt(1000000);
        }

        //most of the time we will take to pritnt arrays
        System.out.println("Unsorted List: ");
        printArray(numbers);

        mergeSort(numbers);

        System.out.println("Sorted List: ");
        printArray(numbers);
    }

    private static void mergeSort(int[] inputArray){    // mergeSort(int arr[], int l, int r){
        int inputLength = inputArray.length;   //this is the l < r situation 
        if (inputLength < 2) {
            return;
        }

        int midIndex = inputLength / 2;            // initialize 2 arrays
        int[] leftHalf = new int[midIndex];
        int[] rightHalf = new int[inputLength - midIndex];

        //fill leftHalf
        for (int i = 0; i < midIndex; i++) {          //poppulate them
            leftHalf[i] = inputArray[i];
        }

        //fill rightHalf
        for (int i = midIndex; i < inputLength; i++) {
            rightHalf[i - midIndex] = inputArray[i];
        }

        mergeSort(leftHalf);
        mergeSort(rightHalf);

        merge(inputArray, leftHalf, rightHalf);
    }

    private static void merge(int[] inputArray, int[] leftHalf, int[] rightHalf){
        int leftLength = leftHalf.length;
        int rightLength = rightHalf.length;
        int i = 0, j = 0, k = 0;

        while (i < leftLength && j < rightLength) {
            if (leftHalf[i] <= rightHalf[j]) {
                inputArray[k++] = leftHalf[i++];
            } else {
                inputArray[k++] = rightHalf[j++];
            }
        }
        //copy remaining elements
        //in this case we use k++ without using k so that k th element is added and then incremented
        while (i < leftLength) {
            inputArray[k++] = leftHalf[i++];
        }

        while (j < rightLength) {
            inputArray[k++] = rightHalf[j++];
        }
    }

    private static void printArray(int[] numbers) {
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i] + " ");
        }
        System.out.println();
    }
}
