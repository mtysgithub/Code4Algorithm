#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<unordered_set>
#include<iostream>
using namespace std;

class Tester{
protected:
	typedef Tester T;
public:

	typedef class UnOrderedSet_Data{
	public:
		typedef UnOrderedSet_Data _USet_Data;

	public:
		class HashFuncObject{
		public:
			size_t operator() (const _USet_Data& pra) const{

				return hash<int>()((int)(pra.val));

				//full random is incorrect.
				//return hash<int>()((int)(this));
			}
		};

		bool operator == (const _USet_Data &pra) const{
			return val == pra.val;
		}

	public:
		int val;

	}USet_Data;

	void test_unorderedset(){
		unordered_set<USet_Data, USet_Data::HashFuncObject> set_;
		USet_Data case1;

		if (set_.max_size() != set_.size()){
			
			case1.val = 0;
			auto it = set_.insert(case1);
		}

		cout << "set: " << endl;
		//for (UnOrderedSet_Data::USetDef::iterator it = set_.begin(); it != set_.end(); ++it)
		for (auto ele_t : set_)
		{
			cout << ele_t.val << endl;
			//cout << (*it).val << " ";
		}
		cout << endl;

		//The case show that hash address is the find() only want to look for.
		//And hash function must the same result when two instance return true by find().
		USet_Data case2;
		case2.val = case1.val;
		auto it_find = set_.find(case2);
		cout << "found that: " << ((it_find != set_.end()) ? (to_string(it_find->val)) : ("")) <<  endl;
	}
};

int main(){
	Tester tester;
	tester.test_unorderedset();

	system("pause");
	return 0;
}