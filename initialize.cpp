//individualの初期化
void Initialize(struct individual *a){
  for(int i=0;i<GENE_LENGTH;i++){
		(*a).gene[i]=0;	
	}
	return;
}

//generationの初期化
void Initialize(struct generation *a){
	for(int i=0;i<POPULATION;i++){
		Initialize(&((*a).individual[i]));
	}
	return;
}

//hintの初期化
void Initialize(struct hint *a){
	for(int i=0;i<HINT_SIZE;i++){
		(*a).hint[i]=0;
	}
	(*a).size=0;
	return;
}

//problemの初期化
void Initialize(struct problem *a){
	for(int i=0;i<WIDTH;i++){
		Initialize(&((*a).width[i]));
	}
	for(int i=0;i<HEIGHT;i++){
		Initialize(&((*a).height[i]));	
	}
	return;
}

//fieldの初期化
void Initialize(struct field *a){

	for(int i=0;i<HEIGHT;i++){

		for(int j=0;j<WIDTH;j++){

			(*a).square[i][j]=0;

		}

	}

	return;

}
