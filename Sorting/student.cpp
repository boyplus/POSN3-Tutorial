#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Student{
public:
	int id,score;
	string name;
	Student(int id,string name,int score){
		this->id = id;
		this->name = name;
		this->score = score;
	}
};
bool cmp(Student& left,Student& right){
	if(left.score == right.score){
		if(left.name == right.name){
			return left.id < right.id;
		} else{
			return left.name < right.name;
		}
	} else{
		return left.score < right.score;
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int id,score;
	string name;
	vector<Student> vec;
	for(int i=0;i<n;i++){
		cin >> id >> name >> score;
		vec.push_back(Student(id,name,score));
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i=0;i<n;i++){
		cout << vec[i].id << " " << vec[i].name << " " << vec[i].score << "\n";
	}
    return 0;
}
/*
5
80 boy 100
44 boy 100
60 toei 30
90 hello 120
100 ching 20
*/