#ifndef SCHEDULE_BST_H
#define SCHEDULE_BST_H

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
template <class T> class BSTItrIn;
template <class T> class BSTItrPre;
template <class T> class BSTItrPost;
template <class T> class BSTItrLevel;
template <class T> class iteratorBST;
template <class T> class BST;

template <class T>
class BinaryNode {
    T element;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode(const T& theElement, BinaryNode* lt, BinaryNode* rt): element(theElement), left(lt), right(rt) { }
    friend class BST<T>;
    friend class BSTItrIn<T>;
    friend class BSTItrPre<T>;
    friend class BSTItrPost<T>;
    friend class BSTItrLevel<T>;
    friend class iteratorBST<T>;
};

template <class T>
class BST {
    BinaryNode<T> *root;
    const T ITEM_NOT_FOUND;

    const T& elementAt(BinaryNode<T>* t) const;
    bool insert(const T& x, BinaryNode<T>* & t) const;
    bool remove(const T& x, BinaryNode<T>* & t) const;
    BinaryNode<T>* findMin( BinaryNode<T>* t) const;
    BinaryNode<T>* findMax( BinaryNode<T>* t) const;
    BinaryNode<T>* find(const T& x, BinaryNode<T>* t) const;
    void makeEmpty(BinaryNode<T>* & t) const;
    void printTree(BinaryNode<T>* t) const;
    BinaryNode<T>* clone(BinaryNode<T>* t) const;
    friend class BSTItrIn<T>;
    friend class BSTItrPre<T>;
    friend class BSTItrPost<T>;
    friend class BSTItrLevel<T>;
    friend class iteratorBST<T>;
public:
    explicit BST(const T& notFound);
    BST(const BST& rhs);

    BST();

    ~BST( );
    const T& findMin( ) const;
    const T& findMax( ) const;
    const T& find(const T& x) const;
    bool isEmpty( ) const;
    void printTree( ) const;
    void makeEmpty( );
    bool insert(const T& x);
    bool remove(const T& x);
    const BST& operator= (const BST& rhs);
    iteratorBST<T> begin() const;
    iteratorBST<T> end() const;
};

// Note that all "matching" is based on the < method.

template <class T>
BST<T>::BST(const T& notFound): root(NULL), ITEM_NOT_FOUND(notFound)
{ }

template <class T>
BST<T>::BST(const BST<T>& rhs): root(NULL), ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND) {
    *this = rhs;
}

template <class T>
BST<T>::~BST( ) {
    makeEmpty( );
}

template <class T>
bool BST<T>::insert(const T& x) {
    return insert(x, root);
}

template <class T>
bool BST<T>::remove(const T& x) {
    return remove(x, root);
}

template <class T>
const T& BST<T>::findMin( ) const {
    return elementAt(findMin(root));
}

template <class T>
const T& BST<T>::findMax( ) const {
    return elementAt(findMax(root));
}

template <class T>
const T& BST<T>::find(const T& x) const {
    return elementAt(find(x, root));
}

template <class T>
void BST<T>::makeEmpty( ) {
    makeEmpty(root);
}

template <class T>
bool BST<T>::isEmpty( ) const {
    return root == NULL;
}


template <class T>
void BST<T>::printTree( ) const {
    if(isEmpty())
        cout << "Empty tree" << endl;
    else
        printTree(root);
}

template <class T>
const BST<T>& BST<T>::operator= (const BST<T>& rhs) {
    if(this != &rhs) {
        makeEmpty( );
        root = clone(rhs.root);
    }
    return *this;
}

template <class T>
iteratorBST<T> BST<T>::begin() const {
    iteratorBST<T> it;
    it.setBST(root);
    return it;
}

template <class T>
iteratorBST<T> BST<T>::end() const {
    iteratorBST<T> it;
    it.setBST(NULL);
    return it;
}


// private methods

template <class T>
const T& BST<T>::elementAt(BinaryNode<T>* t) const {
    if(t == NULL)
        return ITEM_NOT_FOUND;
    else
        return t->element;
}

template <class T>
bool BST<T>::insert(const T& x, BinaryNode<T>* & t) const {
    if (t == NULL) {
        t = new BinaryNode<T>(x, NULL, NULL);
        return true;
    }
    else if( x < t->element )
        return insert( x, t->left );
    else if( t->element < x )
        return insert( x, t->right );
    else
        return false;  // Duplicate; do nothing
}

template <class T>
bool BST<T>::remove(const T& x, BinaryNode<T>* & t) const {
    if(t == NULL)
        return false;   // Item not found; do nothing
    if(x < t->element)
        return remove(x, t->left);
    else if(t->element < x)
        return remove(x, t->right);
    else if(t->left != NULL && t->right != NULL) {     // Two children
        t->element = findMin(t->right)->element;
        return remove(t->element, t->right);
    }
    else {
        BinaryNode<T>* oldNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete oldNode;
        return true;
    }
}

template <class T>
BinaryNode<T>* BST<T>::findMin(BinaryNode<T>* t) const {
    if(t == NULL)
        return NULL;
    if(t->left == NULL)
        return t;
    return findMin(t->left);
}

template <class T>
BinaryNode<T>* BST<T>::findMax(BinaryNode<T>* t) const {
    if(t != NULL)
        while(t->right != NULL)
            t = t->right;
    return t;
}

template <class T>
BinaryNode<T>* BST<T>::find(const T& x, BinaryNode<T>* t) const
{
    if(t == NULL)
        return NULL;
    else if(x < t->element)
        return find(x, t->left);
    else if(t->element < x)
        return find(x, t->right);
    else
        return t;    // Match
}

template <class T>
void BST<T>::makeEmpty(BinaryNode<T>* & t) const {
    if(t != NULL) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = NULL;
}

template <class T>
void BST<T>::printTree(BinaryNode<T>* t) const {
    if(t != NULL) {
        printTree(t->left);
        cout << t->element << endl;
        printTree(t->right);
    }
}

template <class T>
BinaryNode<T>* BST<T>::clone( BinaryNode<T>* t ) const {
    if(t == NULL)
        return NULL;
    else
        return new BinaryNode<T>(t->element, clone(t->left), clone(t->right));
}



//----------- iterators ---------

// Postorder iterator
template <class T>
class BSTItrPost {
    stack<BinaryNode<T> *> itrStack;
    stack<bool> visitStack;
    void slideDown(BinaryNode<T>* n);
public:
    BSTItrPost(const BST<T> &bt);
    void advance();
    const T& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class T>
BSTItrPost<T>::BSTItrPost (const BST<T>& bt) {
    if (!bt.isEmpty())
        slideDown(bt.root);
}

template <class T>
void BSTItrPost<T>::advance () {
    itrStack.pop();
    visitStack.pop();
    if ((!itrStack.empty()) && (visitStack.top() == false)) {
        visitStack.pop();
        visitStack.push(true);
        slideDown(itrStack.top()->right);
    }
}

template <class T>
void BSTItrPost<T>::slideDown(BinaryNode<T>* n) {
    while (n) {
        itrStack.push(n);
        if (n->left) {
            visitStack.push(false);
            n = n->left;
        } else if (n->right) {
            visitStack.push(true);
            n = n->right;
        } else {
            visitStack.push(true);
            break;
        }
    }
}


// Preorder iterator
template <class T>
class BSTItrPre {
    stack<BinaryNode<T> *> itrStack;
public:
    BSTItrPre(const BST<T>& bt);
    void advance();
    const T& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class T>
BSTItrPre<T>::BSTItrPre (const BST<T>& bt)
{
    if (!bt.isEmpty())
        itrStack.push(bt.root);
}

template <class T>
void BSTItrPre<T>::advance()
{
    BinaryNode<T>* actual = itrStack.top();
    BinaryNode<T>* next = actual->left;
    if (next)
        itrStack.push(next);
    else {
        while (!itrStack.empty()) {
            actual = itrStack.top();
            itrStack.pop();
            next = actual -> right;
            if (next) {
                itrStack.push(next);
                break;
            }
        }
    }
}


//Inorder iterator
template <class T>
class BSTItrIn {
    stack<BinaryNode<T> *> itrStack;
    void slideLeft(BinaryNode<T> *n);
public:
    BSTItrIn(const BST<T>& bt);
    void advance();
    const T& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class T>
BSTItrIn<T>::BSTItrIn (const BST<T>& bt) {
    if (!bt.isEmpty())
        slideLeft(bt.root);
}

template <class T>
void BSTItrIn<T>::slideLeft(BinaryNode<T>* n) {
    while (n) {
        itrStack.push(n);
        n = n->left;
    }
}

template <class T>
void BSTItrIn<T>::advance() {
    BinaryNode<T> * actual = itrStack.top();
    itrStack.pop();
    BinaryNode<T> * next = actual->right;
    if (next)
        slideLeft(next);
}


//Bylevel iterator
template <class T>
class BSTItrLevel {
    queue<BinaryNode<T> *> itrQueue;
public:
    BSTItrLevel(const BST<T> &bt);
    void advance();
    const T& retrieve() const { return itrQueue.front()->element; }
    bool isAtEnd() const { return itrQueue.empty(); }
};

template <class T>
BSTItrLevel<T>::BSTItrLevel (const BST<T>& bt) {
    if (!bt.isEmpty())
        itrQueue.push(bt.root);
}

template <class T>
void BSTItrLevel<T>::advance() {
    BinaryNode<T>* actual = itrQueue.front();
    itrQueue.pop();
    BinaryNode<T>* next = actual->left;
    if (next)
        itrQueue.push(next);
    next = actual->right;
    if (next)
        itrQueue.push(next);
}


// another inorder iterator
template <class T>
class iteratorBST {
    stack<BinaryNode<T> *> itrStack;
    void slideLeft(BinaryNode<T>* n);
    void setBST(BinaryNode<T>* root);
    friend class BST<T>;
public:
    iteratorBST<T>& operator ++(int);
    T operator*() const;
    bool operator==(const iteratorBST<T>& it2) const;
    bool operator!=(const iteratorBST<T>& it2) const;
};

template <class T>
void iteratorBST<T>::slideLeft(BinaryNode<T>* n) {
    while (n) {
        itrStack.push(n);
        n = n->left;
    }
}

template <class T>
void iteratorBST<T>::setBST(BinaryNode<T>* root) {
    if (root!=NULL)
        slideLeft(root);
}

template <class T>
iteratorBST<T>& iteratorBST<T>::operator++ (int) {
    BinaryNode<T>* actual = itrStack.top();
    itrStack.pop();
    BinaryNode<T>* next = actual->right;
    if (next)
        slideLeft(next);
    return *this;
}

template <class T>
T iteratorBST<T>::operator*() const {
    return itrStack.top()->element;
}

template <class T>
bool iteratorBST<T>::operator== (const iteratorBST<T>& it2) const {
    return itrStack == it2.itrStack;
}

template <class T>
bool iteratorBST<T>::operator!= (const iteratorBST<T>& it2) const {
    return itrStack != it2.itrStack;
}


#endif