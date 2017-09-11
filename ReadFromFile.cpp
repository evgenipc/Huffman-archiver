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
#include<iostream>
#include<fstream>
#include"ReadFromFile.h"
#include"Queue.h"
#include"pQueue.h"
#include<string>
#include"CompressToFile.h"
int* hash; //256 different byte values
std::string* codes;
HuffTrie tree;
BitChunk omg;


void writeByteToChunk(int, BitChunk&);
void ReadFromFile(char* directory)
{
	//hash keeps frequency
	hash = new int[256](); //256 different byte values
	codes = new std::string[256];
	Queue<int> included;
	PQueue<HuffNode> priority;

	std::ifstream file(directory, std::ios::in | std::ios::binary);
	if (file.is_open())
	{
		std::cout << "Calculating frequency..." << std::endl;
		unsigned int byte = 0;
		while (true)
		{
			byte = 0;
			file.read((char*)&byte, 1);

			if (file.eof())
				break;

			 // If first found for the first time add to queue
			if (hash[byte] == 0)
				included.enqueue(byte);

			hash[byte] += 1;
			//std::cout << (unsigned char)byte << std::endl;
		}
	}
	file.close();
	while (!included.isEmpty())
	{
		priority.enqueue(HuffNode(included.getFront(), hash[included.getFront()]),hash[included.getFront()]);
		included.dequeue();
	}

	HuffTrie tree(priority);

	std::cout << "Generating codes..." << std::endl;
	tree.generateCodes(codes);



}

