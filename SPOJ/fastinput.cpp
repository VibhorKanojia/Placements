#include <iostream>
#include <cstdio>
#include <string>
#define gc getchar_unlocked
using namespace std;

void scanint(int &x){
	register int c = gc();
	x=0;
	for( ; (c<48||c>57) ; c=gc());			//if given adb43 as input on terminal, will skill 'adb' and return 43 as input received
	for( ; (c>47 && c<58) ; c=gc() ){
		x = (x<<1)+ (x<<3) + c-48; 	// x<<! => x*2 ; x<<3 => x*8 ; x*2+x*8 => x*10 
	}
}

void scanline(string &str){
	str="";
	register char s=gc();
	while(s != '\n'){
		str = str + s;
		s=gc(); 
	}
}

void scanword(string &str){
	str="";
	register char s=gc();
	while(s != ' ' && s!='\n'){
		str = str + s;
		s=gc(); 
	}
}
	
int main(){	
	int n,k;
	scanint(n);
	scanint(k);
	printf("%d %d\n",n,k);
	string st;
	scanword(st);
	cout<<st<<endl;
	scanline(st);
	cout<<st<<endl;
	return 0;            
}
