#include<iostream>

//this code reverse a array 
//it users recursion to do it
//Given a pointer to the head of a singly-linked list, print each data value from the reversed list. If the given list is empty, do not print anything

void reversePrint(SinglyLinkedListNode* llist) {
    if (llist == NULL) {                             //base case check for the end of the list
        return;
    }
    reversePrint(llist->next);                       //recursive call to the next node
    cout << llist->data << endl;                     //print the data 
}


//add linked list to a vector and reverse it
//Given a pointer to the head of a singly-linked list, print each data value from the reversed list. If the given list is empty, do not print anything
void reversePrint(SinglyLinkedListNode* llist) {
    vector<int> arr;
    while (llist != NULL) {
        arr.push_back(llist->data);
        llist = llist->next;
    }
    for (int i = arr.size() - 1; i >= 0; i--) {
        cout << arr[i] << endl;
    }
}