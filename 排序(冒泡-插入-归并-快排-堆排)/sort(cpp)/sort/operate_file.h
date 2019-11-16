#pragma once
#include "includes.h"

void Readfile(string (*s)[3],string filename);
void Writefile(string (*s)[3],string filename);
List Read_data_to_List(string filename);
void Read_data_to_array(string filename,int* a,int N);
