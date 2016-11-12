#include "ty_toc_partition.hpp"
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<list>
#include<iostream>

using namespace std;

template<class _TCntrIt,
class _TPd>
_TCntrIt ty_toc_partition(_TCntrIt &it_begin, _TCntrIt &it_end, _TPd &predicate_ptr){
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
		cout << "enter data seq -1 finish" << endl;

		vector<int> case_cntr;
		int val;
		while (cin >> val){
			if (val == -1)
			{
				break;
			}
			case_cntr.push_back(val);
		}

		cout << "enter balance point" << endl;
		cin >> val;

		auto it_balance_point = ty_toc_partition(case_cntr.begin(), case_cntr.end(), [&val](vector<int>::iterator &it_elet){
			return *it_elet < val;
		});

		//output.
		for (auto elet : case_cntr){
			cout << elet << " ";
		}
		cout << endl;
		cout << "balance_point: " <<*it_balance_point << endl;
	}
};

int main(){
	Tester tester;
	tester.test();
	system("pause");
	return 0;
}