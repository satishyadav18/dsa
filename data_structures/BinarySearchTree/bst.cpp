#include <iostream>

#include <climits>

using namespace std;

struct Node {
    Node * lchild;
    int data;
    Node * rchild;
};

class BST {
    Node * root;

    public:
        BST() {
            cout << "Constructor called!" << endl;
            root = nullptr;
        }

        ~BST() {
            cout << "Destructor called!" << endl;
            destroyTree(root);
        }

    void destroyTree(Node * r) {
        if (r != nullptr) {
            destroyTree(r -> lchild);
            destroyTree(r -> rchild);
            delete r;
        }
    }

    Node * getRoot();
    void insert(int);
    void preorderTraversal(Node * );
    void inorderTraversal(Node * );
    void postorderTraversal(Node * );
    bool search(int);
    int minValue(Node * ); // used inside remove function
    Node * remove(Node * , int);
    int findSmallestElement(Node * );
    int findLargestElement(Node * );
    int totalNodes(Node * );
    int totalInternalNodes(Node * );
    int totalExternalNodes(Node * );
    int height(Node * );
};

Node * BST::getRoot() {
    return root;
}

int BST::minValue(Node * r) {
    int minV = r -> data;
    while (r -> lchild != nullptr) {
        minV = r -> lchild -> data;
        r = r -> lchild;
    }
    return minV;
}

Node * BST::remove(Node * root, int key) {
    if (root == nullptr) {
        return root;
    }
    if (key < root -> data) {
        root -> lchild = remove(root -> lchild, key);
    } else if (key > root -> data) {
        root -> rchild = remove(root -> rchild, key);
    } else {
        if (root -> lchild == nullptr) {
            Node * temp = root -> rchild;
            delete root;
            return temp;
        } else if (root -> rchild == nullptr) {
            Node * temp = root -> lchild;
            delete root;
            return temp;
        } else {
            root -> data = minValue(root -> rchild);
            root -> rchild = remove(root -> rchild, root -> data);
        }
    }
    return root;
}

void BST::preorderTraversal(Node * r) {
    if (r == nullptr) {
        return;
    }
    cout << r -> data << " ";
    preorderTraversal(r -> lchild);
    preorderTraversal(r -> rchild);
}

void BST::inorderTraversal(Node * r) {
    if (r == nullptr) {
        return;
    }
    inorderTraversal(r -> lchild);
    cout << r -> data << " ";
    inorderTraversal(r -> rchild);
}

void BST::postorderTraversal(Node * r) {
    if (r == nullptr) {
        return;
    }
    postorderTraversal(r -> lchild);
    postorderTraversal(r -> rchild);
    cout << r -> data << " ";
}

bool BST::search(int value) {
    Node * temp = root;
    while (temp != nullptr) {
        if (value == temp -> data) {
            return true;
        } else if (value < temp -> data) {
            temp = temp -> lchild;
        } else {
            temp = temp -> rchild;
        }
    }
    return false;
}

void BST::insert(int value) {
    Node * curr = new Node;
    curr -> lchild = nullptr;
    curr -> data = value;
    curr -> rchild = nullptr;

    if (root == nullptr) {
        root = curr;
        return;
    }

    Node * temp = root;
    Node * parent = nullptr;

    while (temp != nullptr) {
        parent = temp;
        if (value < temp -> data) {
            temp = temp -> lchild;
        } else if (value > temp -> data) {
            temp = temp -> rchild;
        } else {
            cout << "Data is not unique!" << endl;
            delete curr; // Clean up the allocated memory
            return;
        }
    }

    if (value < parent -> data) {
        parent -> lchild = curr;
    } else {
        parent -> rchild = curr;
    }
}

int BST::findSmallestElement(Node * r) {
    if (r == nullptr) {
        return INT_MIN;
    }
    int smallest = findSmallestElement(r -> lchild);
    return (smallest == INT_MIN) ? r -> data : smallest;
}

int BST::findLargestElement(Node * r) {
    if (r == nullptr) {
        return INT_MIN;
    }
    int largest = findLargestElement(r -> rchild);
    return (largest == INT_MIN) ? r -> data : largest;
}

int BST::totalNodes(Node * r) {
    if (r == nullptr) {
        return 0;
    }
    return (totalNodes(r -> lchild) + totalNodes(r -> rchild) + 1);
}

int BST::totalInternalNodes(Node * r) {
    if (r == nullptr || (r -> lchild == nullptr && r -> rchild == nullptr)) {
        return 0;
    }
    return (totalInternalNodes(r -> lchild) + totalInternalNodes(r -> rchild) + 1);
}

int BST::totalExternalNodes(Node * r) {
    if (r == nullptr) {
        return 0;
    }
    if (r -> lchild == nullptr && r -> rchild == nullptr) {
        return 1;
    }
    return (totalExternalNodes(r -> lchild) + totalExternalNodes(r -> rchild));
}

int BST::height(Node * r) {
    if (r == nullptr) {
        return 0;
    }
    int leftHeight = height(r -> lchild);
    int rightHeight = height(r -> rchild);
    return (leftHeight > rightHeight ? (leftHeight + 1) : (rightHeight + 1));
}

int main() {
    BST tree;
    int choice;

    int height;
    int totalExternalNodesCount;
    int totalInternalNodesCount;
    int totalNodesCount;
    int largestEle;
    int smallestEle;

    cout << "1- insert, 2-preorderTraversal, 3-inorderTraversal, 4-postorderTraversal, 5- search, 6-remove, 7-findSmallestElement, 8-findLargestElement, 9-totalNodes, 10-totalInternalNodes, 11-totalExternalNodes, 12- height, 13-EXIT" << endl;

    do {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int data;
            cout << "Enter data: ";
            cin >> data;
            tree.insert(data);
            break;
        case 2:
            tree.preorderTraversal(tree.getRoot());
            cout << endl;
            break;
        case 3:
            tree.inorderTraversal(tree.getRoot());
            cout << endl;
            break;
        case 4:
            tree.postorderTraversal(tree.getRoot());
            cout << endl;
            break;
        case 5:
            int key;
            cout << "Enter data to be searched: ";
            cin >> key;
            if (tree.search(key)) {
                cout << "Found" << endl;
            } else {
                cout << "Not found" << endl;
            }
            break;
        case 6:
            int key2;
            cout << "Enter data to be removed: ";
            cin >> key2;
            tree.remove(tree.getRoot(), key2);
            break;
        case 7:
            smallestEle = tree.findSmallestElement(tree.getRoot());
            if (smallestEle == INT_MIN) {
                cout << "Tree is empty!" << endl;
            } else {
                cout << "Smallest element is: " << smallestEle << endl;
            }
            break;
        case 8:
            largestEle = tree.findLargestElement(tree.getRoot());
            if (largestEle == INT_MIN) {
                cout << "Tree is empty!" << endl;
            } else {
                cout << "Largest element is: " << largestEle << endl;
            }
            break;
        case 9:
            totalNodesCount = tree.totalNodes(tree.getRoot());
            cout << "Total No. of nodes are: " << totalNodesCount << endl;
            break;
        case 10:
            totalInternalNodesCount = tree.totalInternalNodes(tree.getRoot());
            cout << "Total No. of internal nodes are: " << totalInternalNodesCount << endl;
            break;
        case 11:
            totalExternalNodesCount = tree.totalExternalNodes(tree.getRoot());
            cout << "Total No. of external nodes are: " << totalExternalNodesCount << endl;
            break;
        case 12:
            height = tree.height(tree.getRoot());
            cout << "Height of tree is: " << height << endl;
            break;
        case 13:
            break;
        default:
            cout << "Wrong Choice!" << endl;
            break;
        }
    } while (choice != 13);

    return 0;
}
