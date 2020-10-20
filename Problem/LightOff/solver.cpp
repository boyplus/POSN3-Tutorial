#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include <chrono>
using namespace std;
int main(int argc, char** argv){
	int first = 1,last = 10;
	string name = argv[1];
	if(argc == 4){
		first = atoi(argv[2]);
		last = atoi(argv[3]);
	}
	string s = "g++ "+name+".cpp"+" -o "+name;
	char compile2[s.length()+1];
	strcpy(compile2, s.c_str());
	system(compile2);
	cout << "Compile complete" << endl;

	for(int i=first;i<=last;i++){
		auto begin = std::chrono::high_resolution_clock::now();

		string s = "./"+name+" < "+to_string(i)+".in" +" > "+to_string(i)+".out";
		char ss[s.length()+1];
		strcpy(ss, s.c_str());
		system(ss);
		auto end = std::chrono::high_resolution_clock::now();
		double elapsed = (std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin)).count()*1e-6;

		cout << "complete test case " << i << " takes " << elapsed << " ms" << endl;
	}
	return 0;
}