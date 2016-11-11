#include "ty_toc_partition.hpp"
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<list>
#include<iostream>

using namespace std;

template<class _TCntrIt,
class _Pd>
_TCntrIt ty_toc_partition(_TCntrIt &it_begin, _TCntrIt &it_end, _Pd predicate_ptr){
	auto it_last_faild = it_end;
	auto it_step = it_begin;

	//find last elet return false by predicate_ptr().
	while (it_step != it_end){

		bool ret = predicate_ptr(it_step);
		if (false == ret) it_last_faild = it_step;
		++it_step;
	}

	if (it_last_faild != it_end){
		//move to end.
		it_step = it_last_faild;
		while (it_step != it_end){

			// switch it
			auto it_tmp = *it_step;
			*it_step = *it_last_faild;
			*it_last_faild = it_tmp;

			++it_step;
		}

		//split it.
		it_step = it_begin;
		auto it_minRg_right = it_end;
		it_step = it_begin;
		while (it_step != it_end){

			if (false == predicate_ptr(it_step)){
				//switch to top right of smaller range.
				it_minRg_right = (it_minRg_right != it_end) ? (it_minRg_right + 1) : (it_begin);

				auto val_tmp = *it_step;
				*it_step = *it_minRg_right;
				*it_minRg_right = val_tmp;
			}
			++it_step;
		}

		return (it_minRg_right != it_end) ? (it_minRg_right + 1) : (it_begin);
	}
	else{
		return it_begin;
	}
}

class Tester{
public:
	void test(){
		cout << "enter data seq" << endl;

		vector<int> case_cntr;
		int val;
		while (cin >> val){
			case_cntr.push_back(val);
		}

		cout << "enter balance point" << endl;
		cin >> val;

		ty_toc_partition(case_cntr.begin(), case_cntr.end(), [&val](vector<int>::iterator &it_elet){
			return *it_elet < val;
		});

		//output.
		cout << "sorted:" << endl;
		for (auto elet : case_cntr){
			cout << elet << " ";
		}
		cout << endl;
	}
};

int main(){

	Tester tester;
	tester.test();
	return 0;
}