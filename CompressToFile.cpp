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
#include"CompressToFile.h"
#include"ReadFromFile.h"
#include"pQueue.h"
#include"HuffmanTrie.h"
#include <fstream>
void writeByteToChunk(int byte, BitChunk& chunk)
{
	int len = codes[byte].size();
	chunk.addBit(1);
	for (int i = 0; i < len; i++)
	{
		chunk.addBit(codes[byte][i] - '0');
	}
}

void WriteToFile(char* in,char* out)
{
	std::ifstream read(in, std::ios::in | std::ios::binary);
	std::ofstream myfile(out, std::ios::binary | std::ios::ate);

	read.clear();
	read.seekg(0);
	
		if (myfile.is_open())
		{
			std::cout << "Compressing to file..." << std::endl;
			int pos = 0;
			for (int i = 0; i < 256; ++i)
			{
				if (hash[i] > 0)
					++pos;
			}
			pos = pos * 2 * sizeof(int);
			myfile.write((char*)&pos, sizeof(int));

			for (int i = 0; i < 256; ++i)
			{
				if (hash[i] > 0)
				{

					myfile.write((char*)&i, sizeof(int));
					myfile.write((char*)&(hash[i]), sizeof(int));
				}
			}

			while (true)
			{
				int byte = 0;
				read.read((char*)&byte, 1);

				if (read.eof())
					break;
				writeByteToChunk(byte, omg);
				if (omg.isFull())
				{
					omg.deserialize(myfile);
					omg.del();
				}
			}
			omg.fillOut();
			omg.deserialize(myfile);
			myfile.close();
		}
		else std:: cout << "Unable to open file";
}

void deCompress(char* from, char* to)
{
	std::cout << "Decompressing..." << std::endl;
	PQueue<HuffNode> opashka;
	std::ifstream file(from, std::ios::in | std::ios::binary);
	std::ofstream filec(to, std::ios::ate);
	if (file.is_open())
	{
		int pos = 0;
		file.read((char*)&pos, sizeof(int));
		while (pos > 0)
		{
			unsigned int a = 0, b = 0;
			file.read((char*)&a, sizeof(int));

			if (file.eof())
				break;

			file.read((char*)&b, sizeof(int));

			if (file.eof())
				break;

			opashka.enqueue(HuffNode(a, b), b);
			pos = pos - 8;
		}

	}
	HuffTrie durvo(opashka);
	BitChunk chunka;

	durvo.decodeChunk(filec,file, chunka);
	chunka.del();

	}



	