// Naive Suffix Array Algorithm
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include "p_comp.h"
#include "suffix_struct.h"

using namespace std;

void suffix_sort(int n, suffix* suffixes){std::sort(suffixes, suffixes+n, cmp);}
void param_suffix_sort(int n, suffix* suffixes){std::sort(suffixes, suffixes+n, p_cmp);}

char txt[] = "banana$";

string match(char *s,int n){
    for(int i = 0; i<n;i++){
        if (s[i] == s[n]){
        	return std::to_string(n-i);
        }
    }
    return std::to_string(0);
}

void parameterize(char *suff, std::vector<std::string>* p_suff, int n){

    for(int i = 0; i < n; i++){
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
		for(int j = 0; j<strlen(suffixes[i].suff); j++){
			cout << suffixes[i].p_suff[j];
			cout << endl;
		}
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
    suffix_constructor(txt,  n, suffixes);
    suffix_array(n, suffixes, SA);
    prev(suffixes,n);
    param_suffix_array(n, suffixes, PSA);
	cout << "____Suffix Array________Suffixes_______Prev" << endl;

    for(int i = 0; i < n; i++){
    	cout << "    " <<SA[i]+1 << PSA[i]+1 << "                    " << suffixes[SA[i]].suff << "   ";
    	for(int j = 0; j<strlen(suffixes[PSA[i]].suff); j++){
    		cout << "    " << suffixes[PSA[i]].p_suff[j];
    	}

    	cout << endl;
    }



    return 0;
}
