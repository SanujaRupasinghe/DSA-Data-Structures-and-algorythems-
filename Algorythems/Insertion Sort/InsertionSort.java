import java.util.Random;

public class InsertionSort {

    public static void main(String[] args) {
        // rand is a instance of the class Random Provided by Java.utils package
        Random rand = new Random();   
        int size = 10;

        // create integer array with 10 elements
        int[] numbers = new int[size];                  
        
        // insert random values from 0 to 100 inside the 'numbers' array
        for (int i = 0; i < numbers.length; i++){     
            numbers[i] = rand.nextInt(100);   
        }

        System.out.println("Before : ");
        printArray(numbers);

        //do insertion sort
        insertionSort(numbers);                  

        System.out.println("After : ");
        printArray(numbers);
    }

    /* this method in InsertionSort class will
     * loop over the number arrays and print each number 
     * line by line
     */
    private static void printArray(int[] numbers){
        for (int i = 0; i < numbers.length; i++){
            System.err.print(numbers[i] + ", ");
        }
        System.err.println();
    }


    // do insertion sort here
    private static void insertionSort(int[] unsortedArray){
        // we are initializing sortedArray inside unsortedArray 
        // the first element itself is 1 element sorted array so we loop from 2 nd element index number 1
        for (int i = 1; i < unsortedArray.length; i++){
            int currentVal = unsortedArray[i];
            int j = i-1;

            //stop loop  when we reach the begining of the array or array element <= current value 
            //which we selected and stored in the current value variable
            while(j >= 0 && unsortedArray[j] > currentVal){      
                unsortedArray[j+1] = unsortedArray[j];
                // we have decreased the value of j
                j--;
            }
            // now we have to increased the value of j
            unsortedArray[j+1] = currentVal;
        }
    }
}