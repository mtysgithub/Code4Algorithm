/*
 * https://arena.topcoder.com/#/u/practiceCode/1574/4457/4830/2/1574
 * Created by _mTy 2016/11/07
 */
#include <cstdio>
#include<cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class AccessChanger{
public:
	vector<string> convert(vector<string> program){

		const string comment_tk = "//";
		const string arrow_tk = "->";
		const string point_tk = ".";

		for (int i = 0; i < program.size(); ++i){
			string str_item = program[i];
			int comment_tk_pos = str_item.find(comment_tk, 0);
			if (comment_tk_pos == string::npos) comment_tk_pos = str_item.length() - 1; /*bug. string::npos 是个不确定的值 只能判等，不能判大小于*/

			while(1){
				int arrow_tk_pos = str_item.find(arrow_tk, 0);
				if ((arrow_tk_pos == string::npos) || ((arrow_tk_pos >= comment_tk_pos))){
					break;
				}

				str_item.replace(arrow_tk_pos, 2, point_tk);
				--comment_tk_pos;
			} 
			program[i]= str_item;
		}

		return program;
	}
};