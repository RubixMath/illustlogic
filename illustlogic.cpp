#include"illustlogic.h"



int main(){

  //読み込んだ問題はstruct problem originalProblem(illustlogic.hの末尾にある)

	
	srand((unsigned) time(NULL));	//乱数の初期化

	Initialize(&current);	//現世代の初期化
	Initialize(&next);		//次世代の初期化


	DesignateRanking();			//ランキング選択の比率を作成する

	struct field tmp_best;

	for(int i=0;i<MAX_GENERATION;i++){
		cout	<<	"=====generation ["	<<	i	<<	"]====="	<<endl;
		tmp_best=IndividualToField(current.individual[0]);
		ShowField(tmp_best);
		cout<<"fitness:"<<current.individual[0].fitness<<endl;
		
		next=Evolution(current);		//進化
		current=next;
	}



	return 0;

}
