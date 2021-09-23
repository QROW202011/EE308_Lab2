#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>
using namespace std;

string str_dict[32]= {"auto","break","case","char","const","continue","default","do",
                       "double","else","enum","extern","float","for","goto","if",
                       "int","long","register","return","short","signed","sizeof","static",
                       "struct","switch","typedef","union","unsigned","void","volatile","while"};

vector <string> dict;

string file_name;
vector <string> store;
string str_store;
	


vector<string> split(string str,string separator){  
	vector<string> result;
	int cutAt;  
	while((cutAt = str.find_first_of(separator))!=str.npos){  
		if(cutAt>0){  
			result.push_back(str.substr(0,cutAt));
		}  
		str=str.substr(cutAt+1);  
	}  
	if(str.length()>0){  
		result.push_back(str);  
	}  
	return result;  
}

    

//
void print(vector <string> n){
	
    for (int i = 0; i < int(n.size()); i++)
	{
		cout << n[i]<< endl;
	}
}
void search();

int main(){
	int Keyword_num = 0;
	int Switch_num = 0;
	vector<int> Case_num_in_switch; 
	
	
	
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
    	vector <string> temp_word;
	    getline(infile,line);
	    temp_word = split(line," ");
        store.insert(store.end(),temp_word.begin(),temp_word.end());
    }
    cout << endl << "the number of n is "<< store.size() << endl;
    infile.close();
	print(store);
	
	//vector->string. 
	string str2;
    str2 = accumulate(store.begin(),store.end(),str2);
    cout << "str2 is :"<< str2;
	
	const char p = str_dict[i].c_str();//;
	
	cout << "compare char is:"<<str_dict.c_str()<<endl;
	
//	for(int j = 0;j<sizeof(str_dict)/sizeof(str_dict[0]);j++){
//		
//		const char *p = str_dict[i].c_str();   //big success string->char*->find function  
//		string::iterator one;
//		one = find(str2.begin(),str2.end(),*p);
//		cout<<*one<<endl;
//}
}




//string trimSpace(string s) {
//    if (s.empty()) {
//        return s;
//    }
//
//    //cout << s << endl;
//    string::size_type i = 0, j = 0;
//    while (i < s.size()) {
//        j = s.find_first_of(" ", i);
//        if (j > s.size())
//            break;
//        s.erase(j, 1);
//        i++;
//    }
//    return s;
//};
