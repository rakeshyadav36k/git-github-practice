/**
 * Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task is to return the head of the linked list representing the sum of these two numbers.

For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.
 */

//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    struct Node* reverse(struct Node* head){
        if(!head || !head->next){
            return head;
        }
        struct Node* temp = reverse(head->next);
        head->next->next=head;
        head->next = NULL;
        return temp;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        struct Node* temp = num1;
        struct Node* temp1 = num2;
        while(temp && temp->data==0){
            temp=temp->next;
        }
        temp = reverse(temp);
        while(temp1 && temp1->data==0){
            temp1=temp1->next;
        }
        temp1 = reverse(temp1);
        int carry = 0;
        struct Node* h1 = temp;
        struct Node* h2 = temp1;
        struct Node* dummy = new Node(0);
        struct Node* h3 = dummy;
        while(h1!=NULL && h2!=NULL){
            int sum = h1->data+h2->data+carry;
            carry = sum/10;
            sum = sum%10;
            h3->next = new Node(sum);
            h3 = h3->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        while(h1!=NULL){
            int sum = h1->data+carry;
            carry = sum/10;
            sum = sum%10;
            h3->next = new Node(sum);
            h3 = h3->next;
            h1 = h1->next;
        }
        while(h2!=NULL){
            int sum = h2->data+carry;
            carry = sum/10;
            sum = sum%10;
            h3->next = new Node(sum);
            h3 = h3->next;
            h2 = h2->next;
        }
        while(carry){
            h3->next = new Node(carry);
            carry = 0;
        }
        if(!dummy->next){
            return dummy;
        }
        return reverse(dummy->next);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}
