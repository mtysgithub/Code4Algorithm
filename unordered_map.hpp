#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<iostream>
#include <unordered_map>

using namespace std;

typedef class UnOrderedMap_Tester{

public:
	typedef class KeyDataDef{
	protected:
		typedef KeyDataDef _Kdd;

	public:
		_Kdd(int key){
			_key = key;
		}

		bool operator== (const _Kdd &pra) const{
			return _key == pra._key;
		}

		class HashFuncObject{
		public:
			size_t operator() (const _Kdd pra) const{
				return hash<int>()(pra._key);
			}
		};

	public:
		int _key;

	}Kdd;

	class ValDataDef{
	public:
		ValDataDef(int val){
			_val = val;
		}
		int _val;
	};

public:
	typedef unordered_map<KeyDataDef, ValDataDef, KeyDataDef::HashFuncObject> UMap_Def;

public:
	void test_unorderedmap(){
		UMap_Def map_;
		map_.insert(pair<KeyDataDef, ValDataDef>(KeyDataDef(0), ValDataDef(100)));
		map_.insert(pair<KeyDataDef, ValDataDef>(KeyDataDef(1), ValDataDef(200)));

		cout << "unordered_map: " << endl;
		for (auto ele_t : map_)
		{
			cout << "[" << (ele_t.first)._key << " ," << (ele_t.second)._val << "]" << endl;
		}
		cout << endl;

		KeyDataDef key(0);
		auto it = map_.find(key);
		cout << "find: " << "[" << (it->first)._key << " ," << (it->second)._val << "]" << endl;

		it = map_.erase(it);
		cout << "after erase(): " << "[" << (it->first)._key << " ," << (it->second)._val << "]" << endl;
	}
};

int main(){

	UnOrderedMap_Tester tester;
	tester.test_unorderedmap();

	system("pause");
	return 0;
}