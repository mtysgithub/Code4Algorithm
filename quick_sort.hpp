#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

class QuickSort{
public:

	vector<int> &sort(vector<int> &par){
		do_sort(par, 0, par.size() - 1);
		return par;
	}

private:
	void do_sort(vector<int> &arr, int left, int right){
		if (left >= right){
			return;
		}
		int balance_point = partition(arr, left, right);
		do_sort(arr, left, balance_point - 1);
		do_sort(arr, balance_point + 1, right);
	}

	int partition(vector<int> &arr, int left, int right){

		/* use most right element to be a balance point*/
		/* if do not, choose balance point fisrt, and then switch to top right.*/
		int bp_idx = right; 
		int bp_val = arr[bp_idx]; 

		int miner_range_right = left - 1; //alway point to top right of miner range.
		int higer_range_right = left;
		for (int max = right - 1; higer_range_right <= max; ++higer_range_right){
			int ready_elet_idx = higer_range_right;
			if (arr[ready_elet_idx] < bp_val){
				++miner_range_right;
				swap(arr, miner_range_right, ready_elet_idx);
				/*for now. [miner_range_right + 1, higer_range_right] is >= bp_val*/
			}
		}
		swap(arr, miner_range_right + 1, right); //move balance point to top left of range.
		return miner_range_right + 1;
	}

	void swap(vector<int> &arr, int left, int right){
		int tmpVar = arr[right];
		arr[right] = arr[left];
		arr[left] = tmpVar;
	}
};


int main()
{
	int t_case_2_arr[] = {3, 4, 1, 6, 2, 9};
	QuickSort sorter;
	vector<int> t_case_2 = vector<int>(t_case_2_arr, t_case_2_arr + sizeof(t_case_2_arr) / sizeof(t_case_2_arr[0]));
	vector<int> t_ret_2 = sorter.sort(t_case_2);
	for (int j = 0; j < t_ret_2.size(); ++j)
	{
		cout << t_ret_2[j] << endl;
	}

	system("pause");
	return 0;
}