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
#ifndef READFROMFILE_H
#define READFROMFILE_H
#include"HuffmanTrie.h"
#include<string>
#include"bitChunck.h"

void ReadFromFile(char*);

extern int* hash;
extern HuffTrie tree;
extern std::string* codes;
extern BitChunk omg;

#endif // !READFROMFILE_H

