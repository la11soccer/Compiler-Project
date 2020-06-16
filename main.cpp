#include <iostream>
#include <fstream>
#include <vector>
#include <istream>
#include <algorithm>
#include <sstream>
#include <map>
#include <iterator>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
	string line = "";
	string currentLine = "";
	ifstream fileStream(argv[1]);
	int registers[100];
	for (int i = 0; i < 100; i++)
	{
		registers[i] = 0;
	}
	//vector to store instructions from file
	vector<string> program;
	//map to map Labels to their indexes to be used when LBL found in instructions
	map<string, int> mapper;
	cout << "Program read in: \n";
	while (std::getline(fileStream, line)) // add each instruction to a vector
	{		
		program.push_back(line);
		cout << line << "\n";
	}		
	for (int i = 0; i < program.size(); i++)//run through the instructions to find where the LBLs are
	{
		//cout << "inside the for loop for adding lbls to map \n";
		string temp, temp2;
		stringstream ss;
		ss << program.at(i);
		ss >> temp;
		if (temp == "LBL") // if it is a label insert label name and index into map
		{
			ss >> temp2;
			mapper.insert(pair<string, int>(temp2, i));		
			//cout << temp2 << ' ' << i << "\n";
		}
	}
	/*for (auto itr = mapper.cbegin(); itr != mapper.cend(); itr++)
	{
		std::cout << itr->first << "\n";

	}*/
	

	//vector<string> instructions;//vector to break the instruction into
	string instruction, label;
	int var1, var2, var3, answer, input1, input2;
	cout << "Running Program: \n";
	for (int i = 0; i< program.size(); i++)
	{
		//create stringstream to read in instruction variable by variable
		stringstream ss;
		ss << program.at(i);
		ss >> instruction;
		if (instruction == "INP")
		{
			ss >> var1;//read in the index where the number should go
			cin >> input1; // this should be read in from command line
			registers[var1] = input1; //set register 1 to number given by user
			

		}
		else if (instruction == "ADD")
		{
			ss >> var1;//register where addition will go
			ss >> var2;//add values at registers inputs read from file and store at register from file
			ss >> var3;
			answer = registers[var2] + registers[var3];
			registers[var1] = answer;
			
		}
		else if (instruction == "IFL")
		{
			//read in correct variables from instruction
			ss >> var1;
			ss >> var2;
			ss >> label;
			//if that value at first input register is smaller the value at second input register find
			//the the index of LBL in map and set i to it
			if (registers[var1] < registers[var2])
			{
				i = mapper[label];//move i to where the jump is
			}
		}
		else if (instruction == "PRT")
		{
			//Print the value at register requested from file
			ss >> var1;
			//cout << "PRT statement"<<var1 << ' ';
			input1 = registers[var1];
			cout << input1 << "\n";
		}
		else if (instruction == "SET")
		{
			//if instruction is SET, set the correct values to indexes in registers
			ss >> var1;
			ss >> var2;
			registers[var1] = var2;
			//cout << registers[var1];
		}
		else if (instruction == "LBL")
		{
			//if instruction is LBL do nothing, we already have lbl indexes in mapper
		}
		else if (instruction == "JMP")
		{
			//if the instruction is JMP, find the index of the instruction using mapper and set i to that index
			ss >> label;
			i = mapper[label]; 
		}
		else
		{

		}

	}
	/*
	cout << "-----";
	for (int j = 0; j < program.size(); j++)
	{
		cout << program.at(j) << "\n";
		//cout << registers[j] << "\n";
	}*/
}