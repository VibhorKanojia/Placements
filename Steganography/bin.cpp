#include <iostream>
#include <fstream>
using namespace std;

ofstream myfile ("bomb_new.txt");
ofstream outfile ("bomb_comp.txt");	

void convertBits(string & line, int c){
	int bitcount = 0;
	while (c >= 1){
		int temp = c & 1;
		//cout<<temp;
		myfile << temp;
		c = c/2;
		bitcount++;
	}
	while (bitcount < 8){
		myfile<<0;
		bitcount++;
	}
	cout<<endl;
}

int main(){
	ifstream inpfile ("pushing.mp3", ios::binary);
	unsigned char c;
	if (inpfile.is_open()){
		while (inpfile.get((char&)c)){          
    		if (myfile.is_open()){
    			string line;
    			cout<<(int)c<<endl;
    			convertBits(line, (int)c);
    			//myfile<<line;
    		}
    	}
    	inpfile.close();
    }
	myfile.close();

	ifstream inputfile("bomb_new.txt");
	unsigned char c1;
	unsigned char c2;
	if (inputfile.is_open()){
		inputfile.get((char&) c2);
		outfile<<c2;
		while(inputfile.get((char&) c1)){
			if (c1 != c2){
				outfile<<c1;
				c2=c1;
			}
		}
	}
	outfile.close();
	return 0;
}