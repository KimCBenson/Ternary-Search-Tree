// Created by Christopher Eichert
// Resources used:
// https://www.baeldung.com/cs/ternary-search-tree
// https://www.geeksforgeeks.org/ternary-search-tree/
#include <string>

using namespace std;

const int MAX = 100;

class TernarySearchTree {
public:
	struct Node {
		Node(char newData) : data(newData) {}
		char data;
		bool isTerminal = false;
		Node* left = nullptr;
		Node* middle = nullptr;
		Node* right = nullptr;
	};

	int GetCount() {
		return count;
	}

	//Override helper function
	Node* InsertWord(string word) {
		return InsertWord(root, word, 0);
	}

	//Override helper function
	bool SearchForWord(string word) {
		return SearchForWord(root, word, 0);
	}

	//Override helper function
	void InOrderWalk() {
		char word[MAX];
		InOrderWalk(root, word, 0);
	}

private:
	/// <summary>
	/// Creates a new node
	/// </summary>
	/// <param name="data"></param>
	/// <returns></returns>
	Node* CreateNode(char data) {
		Node* newNode = new Node(data);
		return newNode;
	}

	/// <summary>
	/// Inserts a node into the proper place
	/// </summary>
	/// <param name="node"></param>
	/// <param name="word"></param>
	Node* InsertWord(Node* node, string word, int stringIndex) {

		//If TST is empty, insert first word vertically
		if (root == nullptr) {
			root = CreateNode(word[stringIndex]);
			root->middle = InsertWord(root->middle, word, stringIndex + 1);
			return root;
		}

		//Bootstrap case
		if (node == NULL)
			node = CreateNode(word[stringIndex]);

		//Base case
		if (stringIndex == word.length() + 1)
			return node;

		//if word is smaller than current insert left
		if (word[stringIndex] < node->data)
			node->left = InsertWord(node->left, word, stringIndex);

		//else if word is greater than current insert right
		if (word[stringIndex] > node->data)
			node->right = InsertWord(node->right, word, stringIndex);
		//else insert equal to current
		else {
			//If the next character is null, mark this node as terminal
			if (stringIndex == word.length()) {
				count++;
				node->isTerminal = true;
			}
			else
				node->middle = InsertWord(node->middle, word, stringIndex + 1);
		}
		return node;
	}

	/// <summary>
	/// Returns whether a word is in the TST or not
	/// </summary>
	/// <returns></returns>
	bool SearchForWord(Node* node, string word, int stringIndex) {
		//Bootstrap Case
		if (node == NULL)
			return false;

		//If the value at string index is less than the value of the current node,
		//go to the left node
		if (word[stringIndex] < node->data)
			return SearchForWord(node->left, word, stringIndex);

		//If value at string index is greater than the current node,
		//go to the right node
		if (word[stringIndex] > node->data)
			return SearchForWord(node->right, word, stringIndex);

		//If we reach the end of the word and it is terminal, return true
		if (stringIndex == word.length() && node->isTerminal)
			return true;

		//Search vertically down the word
		return SearchForWord(node->middle, word, stringIndex + 1);
	}

	void InOrderWalk(Node* node, char* word, int stringIndex) {
		//Base case
		if (node == NULL) return;

		//Explore left subtree
		InOrderWalk(node->left, word, stringIndex);
		
		//Cache character and if node is terminal display word
		word[stringIndex] = node->data;
		if (node->isTerminal) {
			//Add null to end of C-string to complete
			word[stringIndex + 1] = '\0';
			//Output string
			cout << word << endl;
		}

		//Explore middle subtree
		InOrderWalk(node->middle, word, stringIndex + 1);

		//Explore right subtree
		InOrderWalk(node->right, word, stringIndex);
	}

	int count = 0;
	Node* root = nullptr;
};
