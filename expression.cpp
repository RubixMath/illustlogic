/*
problem.txtの書き方について:
最初数行はHEIGHT方向のヒントの値を表す(1行毎に"*"で仕切っている)
HEIGHT方向のヒントの最後は"@"
その後はWIDTH方向のヒントが同様に書かれている
*/

//上手く書きなおす

struct problem ReadProblem(void){
  string buf;
	struct problem tmp;
	#define TYPE_H 1
	#define TYPE_W 2
	
	ifstream ifs(PROBLEM_FILE);
	int hint_type=TYPE_H;
	int hint_num=0,height_num=0,width_num=0,ibuf;
	stringstream ss;

	while(ifs>>buf){
		if(buf=="*"){
			if(hint_type==TYPE_H){
				tmp.height[height_num++].size=hint_num;
			}else if(hint_type==TYPE_W){
				tmp.width[width_num++].size=hint_num;
			}
			hint_num=0;
		}else if(buf=="@"){
			if(hint_type=TYPE_H){
				hint_type=TYPE_W;	//読み込みをWIDTH方向に
			}else if(hint_type=TYPE_W){
				break;				//ループから抜け出す
			}
		}else{
			if(hint_type==TYPE_H){
				ss<<buf;
				ss>>tmp.height[height_num].hint[hint_num++];
			}else if(hint_type==TYPE_W){
				ss<<buf;
				ss>>tmp.width[width_num].hint[hint_num++];
			}
			ss.clear(stringstream::goodbit);	//stringstreamの状態を初期化
		}
	}
	return tmp;
}





//problem aを表示する
void ShowProblem(struct problem a){
	cout<<"[size:"<<HEIGHT<<"*"<<WIDTH<<"]"<<endl;

	for(int i=0;i<HEIGHT;i++){
		for(int j=0;j<a.height[i].size;j++){
			cout<<a.height[i].hint[j]<<" ";
		}
		cout<<endl;
	}

	cout<<"@"<<endl;

	for(int i=0;i<WIDTH;i++){
		for(int j=0;j<a.width[i].size;j++){
			cout<<a.width[i].hint[j]<<" ";
		}
		cout<<endl;	
	}

	return;
}


//field aから図を描く
void ShowField(struct field a){
	cout<<"[size:"<<HEIGHT<<"*"<<WIDTH<<"]"<<endl;
	for(int i=0;i<HEIGHT;i++){
		for(int j=0;j<WIDTH;j++){
			cout<<(a.square[i][j]?	"*":" ");
		}
		cout<<endl;
	}

	return;
}

