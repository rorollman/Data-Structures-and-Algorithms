#ifndef _LISTNODE_H_
#define _LISTNODE_H_

using namespace std;

struct Node {
   int value;
   Node *next;
};

class ListNode{
public:
   ListNode() { head = nullptr; }   // Constructor
   ~ListNode();                     // Destructor
   Node* GetHeadNode();             // Get the first node in the list
   void Display();
   void AddNode(int x);             // Append a node the end of the list

private:
   Node* head;
};

// Destructor
ListNode::~ListNode() {

}

// Append a node to the end of the list
void ListNode::AddNode(int x) {
    Node *newNode;
    Node *nodeptr;
    
    newNode = new Node;
    newNode->value = x;
    newNode->next = nullptr;
    
    if (!head) {
        head = newNode;
    }
    else {
        nodeptr = head;
        
        while (nodeptr->next) {
            nodeptr = nodeptr->next;
        }
        nodeptr->next = newNode;
    }
}

// Return the head node pointer
Node* ListNode::GetHeadNode() {
   return head;
}

// Display all the elements in the linked list
void ListNode::Display() {
   if (head == nullptr) {
      cout << "List is empty" << endl;
   } else {
      Node *current = head;
      while (current != nullptr) {
         cout << current->value << ' ';
         current = current->next;
      }
   }
   cout << endl;
}

#endif
