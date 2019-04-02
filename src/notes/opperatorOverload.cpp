#include <iostream>
#include <vector>
using namespace std;
struct printedVal{
	std::string name;
	int age;
	vector<int> vals;
};

        ostream& operator<<(ostream& os, printedVal& pv){
                        os<<pv.name<<endl;
                        os<<pv.age<<endl;
                        os<<"[ ";
                        for(int i = 0; i < pv.vals.size(); i++){
                                os<<pv.vals[i]<<" ";
                        }
                        os<<" ]"<<endl;
                        return os;
        }


class printVals{
	public:
		printVals(std::string _name, int _age, int _size){
			name = _name;
			age = _age;
			vals = vector<int>(_size);
			for(int i = 0; i < _size; i++){
				vals[i] = i;
			}

		}
		friend ostream& operator<<(ostream& os, printVals &pv){
			os<<pv.name<<endl;
			os<<pv.age<<endl;
			os<<"[ ";
			for(int i = 0; i < pv.vals.size(); i++){
				os<<pv.vals[i]<<" ";
			}
			os<<" ]"<<endl;
			return os;
		}
		
		vector<int> getVals(){return vals;}
	private:
		std::string name;
		int age;
		vector<int> vals;
};

int main(){

	printVals myPV("henry", 5, 6);
	cout<<myPV<<endl;
	printedVal myVal;
	myVal.name = "joe";
	myVal.age = 5;
	myVal.vals = myPV.getVals();
	cout << myVal;

	return 0;
}
