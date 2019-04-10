#include <iostream>


template <class T>
BinaryTree<T>::BinaryTree(){
	root = nullptr;
}

template <class T>
BinaryTree<T>::BinaryTree(int size, T * arr)
{
    root = nullptr;
    for(int i = 0; i < size; i++)    
    {
        addNode(arr[i]);
    }
}


template <class T>
void deleteTree(Node<T> * node){
    if(node == nullptr)return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

template <class T>
BinaryTree<T>::~BinaryTree(){
	deleteTree(root);	
}

template <class T>
void helperPrint(Node<T> * node){
	if(node == nullptr)return;
	helperPrint(node->left);
	std::cout<<node->val<<" ";
	helperPrint(node->right);
}

template <class T>
void BinaryTree<T>::print(){
	helperPrint(root);	
	std::cout<<std::endl;
}

template <class T>
void helperInsert(Node<T> * node, T val){
	Node<T> * value;
	if(node->val < val){
		if(node->right == nullptr){
			value = new Node<T>;
			value->val = val;
			value->left = nullptr;
			value->right = nullptr;
			node->right = value;
			return;
		}
		value = node->right;
	}else if(node->val > val){
		if(node->left == nullptr){
			value = new Node<T>;
			value->val = val;
			value->left = nullptr;
			value->right = nullptr;
			node->left = value;
			return;
		}
		value=node->left;
	}else if(node->val == val){
		return;
	}
	helperInsert(value, val);
}

template <class T>
void BinaryTree<T>::addNode(T val){
	if(root == nullptr){
		Node<T> * newNode = new Node<T>;
		newNode->val = val;
		newNode->left = nullptr;
		newNode->right = nullptr;
		root = newNode;
		return;
	}
	helperInsert(root, val);
}

template <class T>
void BinaryTree<T>::findNode(T val){
	if(root == nullptr){
		std::cout<<"empty"<<std::endl;
		return;
	}
	Node<T>* value = search(val);
	std::cout<<value->val<<std::endl;
}

template <class T>
Node<T> * getMinValue(Node<T> * node){
	if(node->left == nullptr)return node;
	return getMinValue(node->left);
}

template <class T>
Node<T>* deleteNodeHelper(Node<T> * node, T val){
	if(node == nullptr)return nullptr;
	else if(val < node->val)node->left = deleteNodeHelper(node->left, val);
	else if(val > node->val)node->right = deleteNodeHelper(node->right, val);
	else{
		if(node->left == nullptr && node->right == nullptr)node = nullptr;
		else if(node->left == nullptr){
			Node<T> * temp = node;
			node = node->right;
			delete temp;
		}else if(node->right == nullptr){
			Node<T> * temp = node;
			node = node->left;
			delete temp;
		}else{
			Node<T> * highestRight = getMinValue(node->right);
			node->val = highestRight->val;
			node->right = deleteNodeHelper(node->right, node->val);
		}
	}
	return node;
}


template <class T>
void BinaryTree<T>::deleteNode(T val){
	deleteNodeHelper(root, val);
}

template <class T>
Node<T>* helperSearch(Node<T>* node, T val){
	if(node == nullptr)return nullptr;
	if(node->val < val){return helperSearch(node->right, val);}
	if(node->val > val){return helperSearch(node->left, val);}
	if(node->val == val){return node;}
}

template <class T>
Node<T> * BinaryTree<T>::search(T val){
	return helperSearch(root, val);	
}










