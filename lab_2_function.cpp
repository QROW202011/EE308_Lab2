#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <sstream>
using namespace std;

string str_dict[32]= {"auto","break","case","char","const","continue","default","do",
                       "double","else","enum","extern","float","for","goto","if",
                       "int","long","register","return","short","signed","sizeof","static",
                       "struct","switch","typedef","union","unsigned","void","volatile","while"};

string Switch_case[2] ={"switch","case"}; //if=15 else=9,while =31,switch =25 for = 13
string if_else_elseif[2] ={"if","else"};
string keyword[2] ={"while","for"};
vector<string> dict;




string file_name;
vector <string> store;
string str_store;
vector <string> store2;
	
template <class T> void print(vector <T> n){
	
    for (int i = 0; i < n.size(); i++)
	{
		cout << n[i]<<" ";
	}
}

void vector_to_string(string n[],vector<string> a){
for(int i=0;i<sizeof(n)/sizeof(n[0]);i++){
		a.push_back(n[i]);
	}
}

int main(){
	int Keyword_num = 0;
	int Switch_num = 0;
	vector<int> switch_group;
	int Case_num = 0;
	
	
	ifstream infile;
    infile.open("code.txt",ios::in);
    string line;
    int i = 0;
    if (infile.fail()) {
        cout << "\nThe file named " << "Data.txt"
             << " was not successfully opened"
             << "\n Please check that the file currently exists."
             << endl;
        return 1;
    }
    cout << "\nThe file has been successfully opened for reading.\n";
    while (infile.good()) {
	    getline(infile,line);
	    int cutAt;
	    string::iterator p;
	    for(p = line.begin();p != line.end();p++){
		
	   	if(!((*p)>='a'&&(*p)<='z'||(*p)>='A'&&(*p)<='Z')){
	    		replace(line.begin(),line.end(),*p,' ');  
		}
	}
	
		while((cutAt = line.find_first_of(' '))!=line.npos){
			if(cutAt > 0){
				store.push_back(line.substr(0,cutAt));
			}
			line=line.substr(cutAt+1);			
		}
		if(line.length()>0){  
			store.push_back(line);    
		}   
	}
	infile.close();
	cout <<"file closed"<<endl;
	
	
	for(int i=0;i<sizeof(str_dict)/sizeof(str_dict[0]);i++){
		dict.push_back(str_dict[i]);
	}
	
	for(int i=0;i<dict.size();i++){//if=15 else=9,while =31,switch =25 for = 13 case =2
		 
		 for(int j=0;j<store.size();j++){
		 	if( dict[i] == store[j]){
		 		Keyword_num++;
			 }
		
	} 
	}
	int flag = 0; 
	for(int j=0;j<store.size();j++){ 
	if(store[j]==dict[25]&&flag==0){
			Switch_num++;
			flag = 1;
			
		
		}
		else if(flag ==1&&store[j]==dict[2]){
			Case_num++;
		 }
		else if((store[j]==dict[13]||store[j]==dict[15])&&flag==1){
			switch_group.push_back(Case_num);
			Case_num = 0;
			flag = 0;
		}
		else if(store[j]==dict[25]&&flag ==1){
			Switch_num++;
			switch_group.push_back(Case_num);
			Case_num = 0;
			
		}
		else{
		}
		} 
	
	cout <<"total num:"<<Keyword_num<<endl;
	cout <<"switch_num:"<< Switch_num << endl;
	cout <<"case num:";
	print(switch_group);
	
	infile.open("code.txt",ios::in);
	if (infile.fail()) {
        cout << "\nThe file named " << "Data.txt"
             << " was not successfully opened"
             << "\n Please check that the file currently exists."
             << endl;
        return 1;
    }
    cout << "\nThe file has been successfully opened for reading.\n";
    
    
    while (infile.good()) {
	    getline(infile,line);
	    int cutAt;
	    string::iterator p;
	    for(p = line.begin();p != line.end();p++){
		
	   	if(!(((*p)>='a'&&(*p)<='z'||(*p)>='A'&&(*p)<='Z')||(*p)=='{'||(*p)=='}')){
	    		replace(line.begin(),line.end(),*p,' '); 
				
		}
		
		
	}
	
		while((cutAt = line.find_first_of(' '))!=line.npos){
			if(cutAt > 0){
				store2.push_back(line.substr(0,cutAt));
			}
			line=line.substr(cutAt+1);			
		}
		if(line.length()>0){  
			store2.push_back(line);    
		}   
	}
	infile.close();
	
}
	
	
	
