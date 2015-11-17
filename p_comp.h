#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include "suffix_struct.h"

// Comparator for string suffix
int cmp(suffix a, suffix b) {return std::strcmp(a.suff, b.suff) < 0? 1 : 0;}

// Comparator for parameterized suffixes 
int p_cmp(suffix a, suffix b){
	int select = 1;
	int length = a.p_suff.size();

	if(length > b.p_suff.size()){
		length = b.p_suff.size();
		select = 0;
	}

	for(int i = 0; i < length; i++){
		std::string checking = a.p_suff[i];
		std::cout << checking << std::endl;
		if((a.p_suff[i]) > (b.p_suff[i])) return 0;
		else if((a.p_suff[i]) >(b.p_suff[i])) return 1;
	}
	return select;
}
