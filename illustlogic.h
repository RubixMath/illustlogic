#include<iostream>
#include<fstream>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string>

using namespace std;
#define PROBLEM_FILE  "problem.txt"


//======CONSTANT===========
const int WIDTH=20;	//パズルの横サイズ
const int HEIGHT=20;	//パズルの縦サイズ

const int HINT_SIZE=10;	//各行各列のヒントのサイズ

const int GENE_LENGTH=WIDTH*HEIGHT;	//遺伝子長
const int POPULATION=100;	//各世代での個体数
const int MAX_GENERATION=10;	//世代数

const double RANGE_LOW	=-10;		//探索範囲の下限
const double RANGE_UP	=10;	//探索範囲の上限

const double INTERVAL=(RANGE_UP-RANGE_LOW)/pow(2,GENE_LENGTH);	//探索する幅

const double COPY_RATE		=0.5;	//そのまま次世代にコピーする割合
const double CROSS_RATE		=0.3;	//交叉率
const double MUTATION_RATE	=0.05;	//突然変異率
//========================


struct hint{
	int hint[HINT_SIZE];
	int size;
};

struct problem{
	struct hint width[WIDTH];
	struct hint height[HEIGHT];
};

struct field{
	bool square[HEIGHT][WIDTH];
};


struct individual{
	int gene[GENE_LENGTH];
	double fitness;	//適合度
};

struct generation{
	struct individual individual[POPULATION];
}current,next;


#include"initialize.cpp"
#include"expression.cpp"
#include"evaluate.cpp"
#include"random.cpp"

const struct problem originalProblem=ReadProblem();	//問題

#include"evolution.cpp"
