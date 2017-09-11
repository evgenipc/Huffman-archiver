/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Evgeni Dimov
* @idnumber 45137
* @task 2
* @compiler VC
*
*/
#ifndef HUFFMANTRIE_H
#define HUFFMANTRIE_H
#include<iostream>
#include"ReadFromFile.h"
#include"pQueue.h"
#include"bitChunck.h"

struct HuffNode {
	int data;
	int frequency;
	HuffNode* left;
	HuffNode* right;
	HuffNode* parent;
	HuffNode() :left(nullptr), right(nullptr), parent(nullptr), data(0), frequency(0) {}
	HuffNode(int a, int b) :left(nullptr), right(nullptr), parent(nullptr), data(a), frequency(b) {}
	bool operator<(const HuffNode& rhs) const
	{
		if (data < rhs.data)
			return true;
		else
			return false;
	}
};

class HuffTrie
{
private:
	
	HuffNode* root;
	int size;

public:
	HuffTrie() { root = nullptr; size = 0; }
	HuffTrie(PQueue<HuffNode>& frequency)
	{
	
		
		root = nullptr;
		
		while (!frequency.isEmpty())
		{
			int priority = 0;
			HuffNode* right = &frequency.getFront();
			priority += frequency.getFrontPri();
			frequency.dequeue();
			if (frequency.isEmpty())
			{
				root = right;
				break;
			}
			HuffNode* left = &frequency.getFront();
			priority += frequency.getFrontPri();
			frequency.dequeue();

			HuffNode* parent = new HuffNode();
			parent->left = left;
			parent->right = right;
			parent->data = -1;
			parent->frequency = priority;
	
			frequency.enqueue(*parent,priority);
		}
	}
	~HuffTrie() { del(root); }
	HuffTrie& operator=(const HuffTrie& other)
	{
		if (this != &other)
		{
			this->root = other.root;
			this->size = other.size;
		}
		return *this;
	}
	
	int getSize() { return size; }
	void decodeChunk(std::ofstream& file,std::ifstream& chetene,BitChunk& chunk)
	{
		decodeChunkPrivate(file,chetene,chunk, root);
	}
	void print()
	{
		printPrivate(root, 1);
	}
	void generateCodes(std::string* codes)
	{
		std::string code;
		//std::cout << "-------------" << std::endl;
		generateCodesPrivate(root,codes,code);
		//std::cout << "-------------" << std::endl;
	}
private:
	void decodeChunkPrivate(std::ofstream& file,std::ifstream& chetene , BitChunk& chunk, HuffNode* tree)
	{
		unsigned char a;
		chetene.read((char*)&a, 1);
		chunk.addChar(a);

		for (int i = 1; i <=chunk.getSet(); ++i)
		{
			if (i == chunk.getSet())
			{
				chunk.del();
				i = -1;
				chetene.read((char*)&a, 1);
				if (chetene.eof())
					break;
				chunk.addChar(a);
				continue;
			}
			if (!tree->right)
			{
				file <<(unsigned char)tree->data;
				//std::cout << (unsigned char)tree->data;
				if (chunk[i] == 0)
					break;
				tree = root;
				continue;
			}
			
			if (!chunk[i])
				tree = tree->left;
			else
				tree = tree->right;
		}
	}

	void generateCodesPrivate(HuffNode* tree,std::string* codes, std::string str)
	{
		if (tree) 
		{
			//compare char of the leaf node and the given char
			if ( !tree->left && !tree->right)
			{
				
				//std::cout << str.c_str() <<" "<<tree->data<<" " <<tree->data <<std::endl;
				codes[tree->data] = str;
			}
			else
				generateCodesPrivate(tree->left,codes,str + "0");
				generateCodesPrivate(tree->right,codes,str + "1");
			}
		}
	
	void printPrivate(HuffNode* tree, int depth)
	{
		if (!tree)
			return;
		printf("%*d \n", depth, tree->frequency);
		printPrivate(tree->left, ++depth);

		printPrivate(tree->right, depth);
	}

	void del(HuffNode*& root)
	{
		if (root) {
			del(root->left);
			del(root->right);
			delete root;
		}
	}
};

#endif // !HUFFMANTRIE_H
