#include <bits/stdc++.h>
#include <string>
using namespace std;

class Argument{
	public:
		int N;
		int K;
		float p;
		float q;
		float r;
		float t;
		Argument();
};
Argument::Argument(){
}
class State{
    public:
    	int N;                        //number of floors
    	int K;                        //number of elevators
    	vector<int> pos;							// = [0]*K  initial positions of all elevators
    	vector<int> BU;								// = [0]*N  # button up on each floor   (always 0 for top floor)
    	vector<int> BD;              	// button down on each floor (always 0 for first floor)
    	vector<vector<int> >BF;				//[K][N]  = [[0]*N for i in range(K)] -- floor buttons pressed inside elevator, for each elevator
    	vector<int> dirn;							//1 or 0 for up or down---dirn for all elevators
    	State(int N, int K):pos(K),BU(N), BD(N),BF(K),dirn(K){
    	    for(int l=0;l<K;l++)
                for(int i=0;i<N;i++){
                    BF[l].push_back(0);
                }
    	};
};
void simpleAgent(Argument args){
	State state(args.N,args.K);
	string ready;
  getline(cin,ready);

  cerr<<ready<<"ready"<<endl;

	vector<string> repeat;
	for(int i=0;i<args.N-1; i++){repeat.push_back("AU");repeat.push_back("AOU");}
		repeat.push_back("AOD");
	for(int i=0;i<args.N-1; i++){repeat.push_back("AD");repeat.push_back("AOD");}
		repeat.push_back("AOU");
    int i = 0;
    while(1){
		vector<string> actions;
		string suff="";
		stringstream sss;
		for(int k=0;k<args.K;k++){
			int kk=k+1;
			sss<< kk;sss>>suff;
			actions.push_back("AOU" + suff);
			//cerr<<(char)(k+1)<<" k+1 "<<k+1<<endl;
		}
        //actions = ['AOU' + str(k+1) for k in range(args.K)]
		string actionsOut="";
        for (int l=0;l< args.K;l++){
            if (i>(args.N/args.K+1)*l*2){
				string end="";
				int ll=l+1;
				stringstream ss;
				ss<< ll;ss>>end;
        actions[l] = repeat[(i - (args.N/args.K+1)*l*2 - 1) % repeat.size()] +end;//+ string(1,1);
                //cerr<<(char)(l+1)<<" l+1 "<<l+1<<endl;
			}
		}
		actionsOut= actions[0];
		for(int ll=1;ll<actions.size();ll++){
			actionsOut+= " "+ actions[ll];
		}
        i+=1;
		cout<<actionsOut<<'\n'<<flush;
		string updates;
  	getline(cin,updates);
		cerr<<updates<<"update"<<endl;
		istringstream iss(updates);
		vector<string> result;
		for(string s; iss >> s; )	result.push_back(s);
		cerr<<result[0]<<"res"<<endl;
		//take action according to updates received
	}
}


int main(int argc, char *argv[]){
	Argument args;
	//5,2,0.2,0.7,0.9,1
	sscanf(argv[1],"%d",&args.N);
	sscanf(argv[2],"%d",&args.K);
	sscanf(argv[3],"%f",&args.p);
	sscanf(argv[4],"%f",&args.q);
	sscanf(argv[5],"%f",&args.r);
	sscanf(argv[6],"%f",&args.t);

	cout<<"0\n"<<flush;

	simpleAgent(args);
	return 0;
}
