#include <iostream>
#include <sstream>
#include <vector>

void dispalyList(std::vector<int> list);
void bubbleSort1(std::vector<int>& list);
std::vector<int> bubbleSort12(std::vector<int> list);
void bubbleSort2(std::vector<int>& list);
void bubbleSort3(std::vector<int>& list);    

int main() {
    std::cout << "Enter space-separated integers (press Enter when done): ";

    std::string inputLine;
    std::getline(std::cin, inputLine);

    std::vector<int> integerList;

    // Use stringstream to extract integers from the input line
    std::istringstream inputStream(inputLine);
    int number;

    // Read integers from the stringstream and add them to the list
    while (inputStream >> number) {
        integerList.push_back(number);
    }

    std::cout << "Original list: ";

    dispalyList(integerList);

    std::vector<int> sortedList = bubbleSort12(integerList);  //only bubblesOrt12 will return a vector
    //bubbleSort1(integerList);
    //bubbleSort2(integerList);             //for other bubble sorts, use the function name
    //bubbleSort3(integerList);

    std::cout << "Sorted list: ";

    dispalyList(sortedList);   

    return 0;
}

//display the list
void dispalyList(std::vector<int> list) {
    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

// Bubble sort with no return value
void bubbleSort1(std::vector<int>& list){
    for (int i = 0; i < list.size() - 1; i++){
        for (int j = 0; j < list.size() - 1; j++){
            if (list[j] > list[j + 1]){
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

//bubble sort with return value return a vector
std::vector<int> bubbleSort12(std::vector<int> list){
    for (int i = 0; i < list.size() - 1; i++){
        for (int j = 0; j < list.size() - 1; j++){
            if (list[j] > list[j + 1]){
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    return list;
}


void bubbleSort2(std::vector<int>& list){
    for (int i = 0; i < list.size() - 1; i++){
        for (int j = 0; j < list.size() - 1 - i; j++){
            if (list[j] > list[j + 1]){
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void bubbleSort3(std::vector<int>& list){
    for (int i = 0; i < list.size() - 1; i++){
        bool swapped;
        for (int j = 0; j < list.size() - 1 - i; j++){
            swapped = false;
            if (list[j] > list[j + 1]){
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
    }
}