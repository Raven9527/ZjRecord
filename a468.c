#include <stdio.h>
#include <string.h>
int MonthDate[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int GetMonth(char month[20]);
int isLeapyear();
int main() {
	
	int T , qwer;
	scanf("%d",&T);
	for(qwer = 0 ; qwer < T ; qwer++){
		
		char m1[20] , m2[20];
		int date1 , date2;
		int year1 , year2; 
		int month1 , month2;
		long long int sumday1 = 0 , sumday2 = 0; //西元1年~輸入該年所有經過的閏日數 
		scanf("%s %d, %d %s %d, %d",&m1 , &date1 , &year1 , &m2 , &date2 , &year2);
		
		month1 = GetMonth(m1);
		month2 = GetMonth(m2);
		
		sumday1 = year1/4 - year1/100 + year1/400; //到該年所經過的閏年數(算入該年)
		if(isLeapyear(year1) == 1){
			if(month1 < 2)
				sumday1--;
			else if(month1 == 2 && date1 <= 29){ // 起始日子當年的2/29必須算進去^^.... 
				sumday1--;
			}
		} 
		
		sumday2 = year2/4 - year2/100 + year2/400;
		if(isLeapyear(year2) == 1){
			if(month2 < 2)
				sumday2--;
			else if(month2 == 2 && date2 < 29){
				sumday2--;
			}
		}
		
		//printf("sum1 == %lld , sum2 == %lld\n",sumday1 , sumday2);
		printf("Case %d: %lld\n",qwer + 1 , sumday2 - sumday1);
	}
	
	return 0;
}

int GetMonth(char month[20])
{
	
	if(strcmp(month , "January") == 0){
		return 1;
	}
	else if(strcmp(month , "February") == 0){
		return 2;
	}
	else if(strcmp(month , "March") == 0){
		return 3;
	}
	else if(strcmp(month , "April") == 0){
		return 4;
	}
	else if(strcmp(month , "May") == 0){
		return 5;
	}
	else if(strcmp(month , "June") == 0){
		return 6;
	}
	else if(strcmp(month , "July") == 0){
		return 7;
	}
	else if(strcmp(month , "August") == 0){
		return 8;
	}
	else if(strcmp(month , "September") == 0){
		return 9;
	}
	else if(strcmp(month , "October") == 0){
		return 10;
	}
	else if(strcmp(month , "November") == 0){
		return 11;
	}
	else if(strcmp(month , "December") == 0){
		return 12;
	}
}

int isLeapyear(int year){
	if((year % 4 != 0)  || (year % 100 == 0 && year % 400 != 0) )
		return 2;
	else
		return 1;
}
