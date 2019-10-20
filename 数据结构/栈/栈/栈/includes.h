#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

struct node
{
	string address;
	string number;
	string time;
	node* next;
};