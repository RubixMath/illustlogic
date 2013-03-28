double FitnessOfIndividual(struct individual a){

  struct problem b=IndividualToProblem(a);

	return -DistanceProblem(b,originalProblem);
	//最小値を求めるためにマイナスをかけてある

}


//適合度を計算する

void CalculateFitness(struct generation *a){

	for(int i=0;i<POPULATION;i++){
		(*a).individual[i].fitness=FitnessOfIndividual((*a).individual[i]);

	}

	return;

}



//世代aの個体を適合度順に並べる

void SortIndividual(struct generation *a){

	struct individual tmp;

	//バブルソート(暇があれば書き換え)

	for(int i=0;i<POPULATION;i++){

		for(int j=i+1;j<POPULATION;j++){

			if((*a).individual[i].fitness<(*a).individual[j].fitness){

				tmp=(*a).individual[i];

				(*a).individual[i]=(*a).individual[j];

				(*a).individual[j]=tmp;

			}		

		}	

	}

	return;

}





//==================選択=====================

//ランキング選択

int ranking_n[POPULATION];



//ranking_nはmain部で指定

void DesignateRanking(void){

	for(int i=0;i<POPULATION;i++){

		ranking_n[i]=i+1;

	}

}



struct individual ranking_choose(struct generation a){

	int choice=MakeDistribution(ranking_n,POPULATION);

	return a.individual[choice];

}



//ランダム選択

struct individual random_choose(struct generation a){

	int choice=MakeRandom(POPULATION);

	return a.individual[choice];

}

//=========================================





//==================交叉=====================

//二点交叉

void crossover(struct individual *a,struct individual *b){

	int rnd1=MakeRandom(GENE_LENGTH);

	int rnd2=MakeRandom(GENE_LENGTH);



	int lower=min(rnd1,rnd2);	//交叉範囲の下限

	int upper=max(rnd1,rnd2);	//交叉範囲の上限



	int tmp;

	for(int i=lower;i<=upper;i++){

		tmp=(*a).gene[i];

		(*a).gene[i]=(*b).gene[i];

		(*b).gene[i]=tmp;			

	}

	return;

}

//=========================================





//=================突然変異===================

//遺伝子を反転させる

void mutation(struct individual *a){

	for(int i=0;i<GENE_LENGTH;i++){

		if(IsHappen(MUTATION_RATE)){

			if((*a).gene[i]){

				(*a).gene[i]=0;

			}else{

				(*a).gene[i]=1;

			}	

		}

	}

	return;

}

//=========================================





//===========次世代の計算========================

struct generation Evolution(struct generation current){

	struct generation next;

	

	int num_copy=POPULATION*COPY_RATE;	//そのままコピーする個体の数



	//上位num_copy個体をそのままコピーする

	for(int i=0;i<num_copy;i++){

		next.individual[i]=current.individual[i];

	}



	//残りの個体をルーレット選択する

	for(int i=num_copy;i<POPULATION;i++){

		next.individual[i]=ranking_choose(current);

	}



	//交叉

	for(int i=num_copy;i<POPULATION;i++){

		if(IsHappen(CROSS_RATE)){

			int partner=num_copy+MakeRandom(POPULATION-num_copy);

			crossover(&next.individual[i],&next.individual[partner]);

		}	

	}



	//突然変異

	for(int i=num_copy;i<POPULATION;i++){

		mutation(&next.individual[i]);

	}





	CalculateFitness(&next);

	SortIndividual(&next);



	return next;

}

//===========================================
