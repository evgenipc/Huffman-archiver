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

#ifndef BITCHUNCK_H
#define BITCHUNCK_H
#include<iostream>
#include<string>
#include<fstream>

class BitChunk
{
private:

	bool* bits;
	int capacity;
	int set;

public:
	BitChunk() {
		bits = new bool[8];

		set = 0;
		capacity = 8;
	}
	BitChunk(unsigned char chr)
	{
		bits = new bool[8];
		set = 0;
		capacity = 8;


	}
	bool operator[](int idx) {
		return bits[idx];
	}
	bool isFull()
	{
		if (set == capacity)
			return true;
		else
			return false;
	}
	void addChar(unsigned char chr)
	{
		if (isFull())
			resize();
		bits[set+7] = chr & 1;
		bits[set+6] = chr >> 1 & 1;
		bits[set+5] = chr >> 2 & 1;
		bits[set+4] = chr >> 3 & 1;
		bits[set+3] = chr >> 4 & 1;
		bits[set+2] = chr >> 5 & 1;
		bits[set+1] = chr >> 6 & 1;
		bits[set] = chr >> 7 & 1;
		set += 8;

	}
	void fillOut()
	{
		while (set != capacity)
		{
			bits[set++] = 0;
		}
	}
	void deserialize(std::ofstream& file)
	{
		unsigned int count = 0;
		for (int i = 0; i < capacity; i+=8)
		{
			count = 0;
			for (int j = 0; j < 8; j++)
			{
				count += bits[i + j] * pow(2, 8 - j-1);
			}
			unsigned char result = count;
			file.write((char*)&result, 1);

		}
	}
	void print()
	{
		std::cout << "----------Chunk-----------" << std::endl;
		for (int i = 0; i < capacity; i++)
		{
			std::cout << bits[i];
			if ((i + 1) % 8 == 0)
				std::cout << " ";
		}
		std::cout<<std::endl;
		std::cout << "-----------------------" << std::endl;
	}
	void addBit(int bit)
	{
		if (isFull())
			resize();

			if (bit == 0)
				bits[set] = false;
			else
				bits[set] = true;
			++set;

	}
	int getSet() {
		return set;
	}
	
	void del()
	{
		delete[] bits;
		bits = new bool[8];
		set = 0;
		capacity = 8;

	}
private:
	void resize()
	{
		bool* tmp = new bool[capacity + 8];
		for (int i = 0; i < set; ++i)
		{
			tmp[i] = bits[i];
		}
		capacity += 8;
		delete[] bits;
		bits = tmp;
	}
};


#endif // !BITCHUNCK_H
