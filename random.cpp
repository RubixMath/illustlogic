//標準化された乱数を生成する

double norm(void){

  return ((double) rand()/(double) RAND_MAX);

}



//確率pで1を、確率1-pで0を返す

bool IsHappen(double p){

	return (norm()<p);

}



//0からk-1までの乱数を1つ生成する

int MakeRandom(int k){

	return (k * norm());

}



//n[0],n[1],...,n[k-1]の割合で数字0,1,...,k-1を1つ発生させる

int MakeDistribution(int *n,int k){

	const int K=k;

	double p[K];//確率密度関数

	int sum=0,q;

	for(int i=0;i<K;i++){

		sum+=n[i];	

	}

	for(int i=0;i<K;i++){

		p[i]=(double) n[i]/(double)sum;

	}



	double r=norm();

	for(int i=0;i<K;i++){

		r-=p[i];

		if(r<0){

			q=i;

			break;

		}

	}

	return q;

}















