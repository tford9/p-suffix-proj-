// Naive Suffix Array Algorithm
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

char txt[] = "1b1ananas$";

struct suffix
{
    int index;
    char *suff;
    std::vector<std::string> p_suff;
};
int p_cmp(suffix a, suffix b){
	int which = 1;
	int length = a.p_suff.size();

	if(length > b.p_suff.size()){
		length = b.p_suff.size();
		which = 0;
	}

	for(int i = 0; i < length; i++){
		string checking = a.p_suff[i];
		cout << checking << endl;
		if((a.p_suff[i]) > (b.p_suff[i])) return 0;
		else if((a.p_suff[i]) >(b.p_suff[i])) return 1;
	}
	return which;
}
int cmp(suffix a, suffix b) {return strcmp(a.suff, b.suff) < 0? 1 : 0;}

void suffix_sort(int n, suffix* suffixes){std::sort(suffixes, suffixes+n, cmp);}
void param_suffix_sort(int n, suffix* suffixes){std::sort(suffixes, suffixes+n, p_cmp);}
string match(char *s,int n){
    for(int i = 0; i<n;i++){
        if (s[i] == s[n]){
        	return std::to_string(n-i);
        }
    }
    return std::to_string(0);
}

void parameterize(char *suff, std::vector<std::string>* p_suff, int n)
{
    for(int i = 0; i < n; i++)
    {
        (*p_suff)[i] = (match(suff,i));
    }
}
 
void suffix_constructor(char *txt, int n, suffix* suffixes)
{
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);
        suffixes[i].p_suff.resize(strlen(suffixes[i].suff));
    }
}

void suffix_array(int n, suffix *suffixes, int *SA){
	suffix *sorted_suffixes = new suffix[n];
	std::copy(suffixes,suffixes+n,sorted_suffixes);

	suffix_sort(n, sorted_suffixes);

    for (int i = 0; i < n; i++){
        SA[i] = sorted_suffixes[i].index;
    }
}

 void prev(suffix *suffixes, int n){
	 for (int i = 0; i < n-1;i++){
		parameterize(suffixes[i].suff, &suffixes[i].p_suff, strlen(suffixes[i].suff));
		for(int j = 0; j<strlen(suffixes[i].suff)-1; j++){
			cout << suffixes[i].p_suff[j];
		}
        cout << endl;
	 }
 }
// void prev_array(suffix *suffixes,int *index, int n){
//	 for (int i = 0; i < n-1;i++){
//	 		parameterize(suffixes[i].suff,suffixes[i].p_suff, strlen(suffixes[i].suff));
//	 		for(int j = 0; j<strlen(suffixes[i].suff); j++){
//	 			cout << suffixes[i].p_suff[j];
//	 		}
//	 		cout << endl;
//	 	 }
// }

 void param_suffix_array(int n, suffix* suffixes, int *PSA){

    suffix *sorted_suffixes = new suffix[n];
    std::copy(suffixes,suffixes+n,sorted_suffixes);

    param_suffix_sort(n, sorted_suffixes);

    for (int i = 0; i < n; i++){
        PSA[i] = sorted_suffixes[i].index;
    }
}
int main()
{
    int n = strlen(txt);
    suffix* suffixes = new suffix[n];
    int SA[n];
    int PSA[n];
    suffix_constructor(txt, n, suffixes);
    suffix_array(n, suffixes, SA);
    prev(suffixes, n);
    // param_suffix_array(n, suffixes, PSA);
	cout << "____Suffix Array________Suffixes_______Prev" << endl;

    // for(int i = 0; i < n; i++){
    // 	cout << "    " <<SA[i]+1 << PSA[i]+1 << "                    " << suffixes[SA[i]].suff << "   ";
    // 	for(int j = 0; j<strlen(suffixes[PSA[i]].suff); j++){
    // 		cout << "    " << suffixes[PSA[i]].p_suff[j];
    // 	}

    // 	cout << endl;
    // }
    for(int i = 0; i < n ; i++){
        printf("\n SA[%d] = %d,\n suffixes[SA[%d]] = %s",i,SA[i],i,suffixes[SA[i]].suff);
    }


    return 0;
}
