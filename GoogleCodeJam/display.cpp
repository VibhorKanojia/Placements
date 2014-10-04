#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
#define debug 0		
using namespace std;

struct data{
	int number;
	string display;
};


string working="uuuuuuu";
vector<struct data> ans_vector;

stack<struct data> values;
stack<string> states;
stack<string>temp2;
stack<struct data> temp1;
stack<struct data> temp3;


map<int,string> convertor;

void initialize_map(){
	convertor.insert(pair<int,string>(9,"1111011"));
	convertor.insert(pair<int,string>(8,"1111111"));
	convertor.insert(pair<int,string>(7,"1110000"));
	convertor.insert(pair<int,string>(6,"1011111"));
	convertor.insert(pair<int,string>(5,"1011011"));
	convertor.insert(pair<int,string>(4,"0110011"));
	convertor.insert(pair<int,string>(3,"1111001"));
	convertor.insert(pair<int,string>(2,"1101101"));
	convertor.insert(pair<int,string>(1,"0110000"));
	convertor.insert(pair<int,string>(0,"1111110"));
}

bool andString(string str1, string str2){
	string res="";
	string temp="";
	
	for (int i = 0 ; i < 7 ; i++){
		if (str1[i]=='1' && str2[i]=='1' && working[i] !='n'){
			res = res+"1";
			temp=temp+"y";
		}
		else if (str1[i]=='1' && str2[i]=='0' && working[i] !='y'){
			res = res+"0";
			temp = temp + "n";
		}
		else if (str1[i]=='0' && str2[i]=='0'){
			res = res+"0";
			temp = temp + working[i];
		}
		
		else if (str1[i]=='0' && str2[i]=='1'){
			working[i] = 'y';
			return false;
		}
		else {
			return false;
		}	
	}
	working = temp;
	return true;
}

string finalAnd(string str1,string str2){
	//cout<<"working is "<<str2<<" bingo!!"<<endl;
	
	string res="";
	for (int i = 0 ; i < 7 ; i++){
		if (str1[i]=='1' && str2[i] == 'y'){
			res = res+"1";
		}
		else if (str1[i] == '1' && str2[i] =='u'){
			return "";
		}
		else{
			res = res+"0";
		}
	}
	return res;
}

int glob_flag = 0;
int pass_flag = 0;

void initialize(){
	ans_vector.clear();
	glob_flag = 0;
	pass_flag = 0;
	working="uuuuuuu";
	
	int size1 = values.size();
	for (int i = 0 ; i < size1; i++){
		values.pop();
	}
	
	//cout<<"values size after "<<values.size()<<endl;
	int size2 = states.size();
	for (int i = 0 ; i < size2; i++){
		states.pop();
	}

	
	for (int i = 0 ; i < 10 ; i++){
		struct data mydata;
		mydata.number = i;
		mydata.display = convertor[i];
		values.push(mydata);
	}
}


void fill_stack(int num_states){
	for (int i = 0 ; i < num_states ; i++){
		string S;
		cin>>S;
		//cout<<"state is "<<S<<endl;
		temp2.push(S);
	}
	
	for (int i=0 ; i < num_states ; i++){
		states.push(temp2.top());
		temp2.pop();
	}
}



int comparator(data mydata, string c_state){
	if (debug) cout<<"working before "<<working<<endl;
	bool result = andString(mydata.display,c_state);
	if (debug) cout<<"working after "<<working<<endl;
	if (result){
		//if (pass_flag == 1){
		//	return 1;
		//}	
		if (debug) cout<<"matched"<<endl;
		
		if (mydata.number == 0 && glob_flag == 0){
			if (debug) cout<<"pass flag set to 1"<<endl;
			pass_flag =1;
		}
		values.pop();
		states.pop();
		if (values.empty()){
			values = temp3;
		}
		
		if (glob_flag == 0){
			temp1 = values;
		}
		glob_flag =1;
		if (states.size() == 0 && mydata.number ==0){
			/*
			if (debug) cout<<"entered here"<<endl;
			if (ans_vector.size() == 0){
				struct data enter;
				enter.number = 9;
				enter.display = working;
				ans_vector.push_back(enter);
			}
			else if (ans_vector[0].number != 9){
				struct data enter;
				enter.number = 9;
				enter.display = working;
				ans_vector.push_back(enter);
			}
			*/ 
			pass_flag =1;
			//values = temp1;
			//return 1;
		}
	}
	else{
		working ="uuuuuuu";
		if (glob_flag == 0){
			if (debug) cout<<"Not matched with 0"<<endl;
			if (mydata.number == 0){
				pass_flag = 1;
				return 1;
			}
			values.pop();
			if (values.empty()){
				values = temp3;
			}
			temp1 = values;
			glob_flag = 0;
		}
		
		else if (glob_flag == 1){
			if (debug) cout<<"Not matched with 1"<<endl;
			if(pass_flag == 1){
				return 1;
			}
			states = temp2;
			values = temp1;
			glob_flag = 0;
		}
	}
	return 0;
}

int algorithm(){
	while(true){
		data current = values.top();
		if (states.empty()){
			if (ans_vector.size() == 0){
				if (debug)cout<<"entered with 0 "<<temp1.size()<<endl;
				struct data enter;
				enter.number = current.number;
				enter.display = working;
				ans_vector.push_back(enter);
				values = temp1;
				current = values.top();
				working="uuuuuuu";
			}
			else if (ans_vector[0].number != current.number){
				struct data enter;
				enter.number = current.number;
				enter.display = working;
				ans_vector.push_back(enter);
				values = temp1;
				current = values.top();
				working="uuuuuuu";
			}
			else{
				return 1;
			}
			if (debug) cout<<ans_vector.size()<<endl;
			states = temp2;
			glob_flag = 0;
		}
		string cur_state = states.top();
		if (debug) cout<<"current state"<<cur_state<<endl;
		if (debug) cout<<"current number, value"<<current.number<<" "<<current.display<<endl;	
		int endit =comparator(current, cur_state);
		if (endit == 1){
			return 1;
		}
	}
}



int main(){
	
	initialize_map();
	int case_num = 1;	
	int testcases;
	cin >> testcases;

	while (testcases--){
		initialize();
		int num_states;
		cin >> num_states;
		fill_stack(num_states);
		temp2 = states;
		temp3 = values;
		algorithm();
		
		if (ans_vector.size() != 1){
			if (debug){
				for (int i = 0 ; i < ans_vector.size(); i++){
					cout<<ans_vector[i].display<<" ";
				}
				cout<<endl;
			}
			int another_fucking_flag = 0;
			//cout<<"size is "<<ans_vector.size()<<endl;
			for (int i = 0 ; i < ans_vector.size() - 1; i++){
				if (finalAnd(convertor[ans_vector[i].number], ans_vector[i].display) != finalAnd(convertor[ans_vector[i+1].number], ans_vector[i+1].display)){
				//	cout<<"another fucking flag set"<<endl;
				//	cout<<finalAnd(convertor[ans_vector[i].number], ans_vector[i].display)<<endl;
				//	cout<<finalAnd(convertor[ans_vector[i+1].number], ans_vector[i+1].display)<<endl;
					another_fucking_flag =1;
					break;
				}	
			}
			
			if (another_fucking_flag == 0){
				cout<<"Case #"<<case_num<<": "<<finalAnd(convertor[ans_vector[0].number], ans_vector[0].display)<<endl;
			}
			else {
				cout<<"Case #"<<case_num<<": ERROR!"<<endl;
			}
			/*
			int myflag = 0;
			for (int i = 0 ; i < ans_vector.size(); i++){
				if (ans_vector[i].display != "nnnnnnn"){
					myflag =1;
				}
			}
			if (myflag == 0){
				cout<<"Case #"<<case_num<<": 0000000"<<endl;
			}
			else {
				cout<<"Case #"<<case_num<<": ERROR!"<<endl;
			}
			*/
			
		}
		else if (ans_vector.size() !=0){
			string finalanswer = finalAnd(convertor[ans_vector[0].number], ans_vector[0].display);
			if (finalanswer == ""){
				cout<<"Case #"<<case_num<<": ERROR!"<<endl;
			}
			else{
				cout<<"Case #"<<case_num<<": "<<finalAnd(convertor[ans_vector[0].number], ans_vector[0].display)<<endl;
			}
		}
		case_num++;
	}
	
return 0;
}





