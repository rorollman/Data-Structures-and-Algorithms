#include <iostream>

using namespace std;

struct TreeNode {
   int value;
   TreeNode* left;
   TreeNode* right;
};

class MyBST {
public:
   MyBST () { root = NULL; }
   ~MyBST ();
   bool Find(int x);   
   void Insert(int x);
   void PreorderTraversal();
   void PostorderTraversal();
   void InorderTraversal();

private:
   TreeNode* root;
   
   void FreeHelper(TreeNode* node);
   bool FindHelper(TreeNode* node, int x);
   //void InsertHelper(TreeNode* node, int x);  // use this one if you want to implement InsertHelper without passing a pointer by reference. 
   void InsertHelper(TreeNode*& node, int x);
   void Preorder(TreeNode* node);
   void Postorder(TreeNode* node);
   void Inorder(TreeNode* node);
}; 

MyBST::~MyBST() {
   FreeHelper(root);
}

void MyBST::FreeHelper(TreeNode* node) {
   if (node != NULL) {
      FreeHelper(node->left);
      FreeHelper(node->right);
      delete node;
   }
}

bool MyBST::FindHelper(TreeNode* node, int x) {
   // TODO
    if (node == NULL) {
        return false;
    }
    else if (node->value == x) {
        return true;
    }
    if (x < node->value) {
        return FindHelper(node->left, x);
    }
    else  {
        return FindHelper(node->right, x);
    }
}


bool MyBST::Find(int x) {
   return FindHelper(root, x);
}

//void MyBST::InsertHelper(TreeNode* node, int x) {  // use this one if you want to implement InsertHelper without passing a pointer by reference. 
void MyBST::InsertHelper(TreeNode*& node, int x) {
   // TODO 
    if (!node) {
        node = new TreeNode;
        node->value = x;
        node->right = NULL;
        node->left = NULL;
        return;
    }
    if (x < node->value) {
        InsertHelper(node->left, x);
    }
    else if (x > node->value) {
        InsertHelper(node->right, x);
    }
    else {
        cout << endl << x << " already exists. No new node has been inserted.\n";
    }
}

// use this one if you want to implement InsertHelper without passing a pointer by reference. 
/*
void MyBST::Insert(int x) {
   if (root != NULL) {
      InsertHelper(root, x);
   } else {
      root = new TreeNode;
	  root->value = x;
	  root->right = NULL;
	  root->left = NULL;
   }
}
*/

void MyBST::Insert(int x) {
   InsertHelper(root, x);
}


void MyBST::Preorder(TreeNode* node) {
   // TODO
    if (node != NULL) {
        cout << node->value << " ";
        Preorder(node->left);
        Preorder(node->right);
    }
}

void MyBST::PreorderTraversal() {
   Preorder(root);
   cout << endl;
}


void MyBST::Postorder(TreeNode* node) {
   // TODO
    if (node != NULL) {
        Postorder(node->left);
        Postorder(node->right);
        cout << node->value << " ";
    }
}

void MyBST::PostorderTraversal() {
   Postorder(root);
   cout << endl;
}


void MyBST::Inorder(TreeNode* node) {
   // TODO
    if (node != NULL) {
        Inorder(node->left);
        cout << node->value << " ";
        Inorder(node->right);
    }
}

void MyBST::InorderTraversal() {
   Inorder(root);
   cout << endl;
}


int main() 
{ 
   MyBST test_tree;
   
   int user_input = 0;
	
   while (user_input != -1) {
      cout << "Inserting a new node...." << endl;
      cout << "Please enter an integer between 0 and 99 as a value to insert, ";
      cout << "or enter -1 to stop inserting and see the resulting tree: ";
      cin >> user_input;
      if (user_input >= 0 && user_input <= 99)
         test_tree.Insert(user_input);
      else if (user_input != -1)
         cout << "Invalid input value (" << user_input << ") !" << endl;
   }

   cout << "Preorder Traversal: ";
   test_tree.PreorderTraversal();
   cout << "Postorder Traversal: ";
   test_tree.PostorderTraversal();
   cout << "Inorder Traversal: ";
   test_tree.InorderTraversal();

   user_input = 0;
	
   while (user_input != -1) {
      cout << "Searching a value...." << endl;
      cout << "Please enter an integer between 0 and 99 as a value to search, ";
      cout << "or enter -1 to stop searching: ";
      cin >> user_input;

      if (user_input >= 0 && user_input <= 99) {
         if(test_tree.Find(user_input))
            cout << user_input << " is in this BST." << endl;
         else {
            cout << user_input << " is not in this BST." << endl;
         }
      }
      else if (user_input != -1)
         cout << "Invalid input value (" << user_input << ") !" << endl;
   }
   
   return 0;
}  
