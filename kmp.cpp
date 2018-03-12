/*kmp算法是基于最长公共前缀后缀的字符串模式匹配算法*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int kmp(const string &str,const string &pattern){
	if (pattern.size()>str.size())
		return -1;
	if (pattern.size()==0)
		return 0;

    /*先维护next数组*/
	vector<int> nextPos(pattern.size(),-1);
	for(int i=1;i<pattern.size();i++){
		int next = nextPos[i-1];
		while(pattern[next+1]!=pattern[i]){
			if (next==-1){
				next = -2;
				break;
			}
			next = nextPos[next];
		}
		nextPos[i] = next + 1;
	}

	/*开始进行匹配*/
	int i = 0, j = 0;
	while(i<str.size() && j<pattern.size()){
		if (str[i]==pattern[j]){
			i++;
			j++;
			continue;
		}
		if (j==0){
			i++;
			continue;
		}
		j = nextPos[j-1] + 1;
	}
    if (j==pattern.size())
    	return i-pattern.size();
    else
    	return -1;
}
int main(int argc,char* argv[])
{
	cout<<kmp("abcdabc","cd")<<endl;
}