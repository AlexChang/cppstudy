// p1.cpp
// F1403022°à  5140309508  ÕÅ¸£Ã÷  2015.03.25

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	int answer[3], guess[3];						// answer[3]:three random number, guess[3]:guess three numbers
	int i, j, correctA, correctB, games=0, win=0;	// correctA, correctB: num of A,B,
													// games: innings, win: innings for the win  
	char choose;									// choose: the input of Y/N 
	
	srand(time(NULL));								// initialization of the seed of random numbers
	
	cout << "ÐèÒªÍæÓÎÏ·Âð£¨Y/N£©£¿ ";
	cin >> choose;
	while (choose=='Y'){
		answer[0]=rand()*10/(RAND_MAX+1);		// generate random num1 
		answer[1]=rand()*10/(RAND_MAX+1);		// generate random num2 
		while (answer[1]==answer[0]){
			answer[1]=rand()*10/(RAND_MAX+1);	// check if random num1 is the same as random num2 
		}
		answer[2]=rand()*10/(RAND_MAX+1);		// generate random num3
		while (answer[2]==answer[1] || answer[2]==answer[0]){
			answer[2]=rand()*10/(RAND_MAX+1);	// check if random num1 is the same as random num2 or num3 
		}
			
		games+=1;								// record innings								
		for (i=0; i<7; ++i){
			cout << "ÇëÊäÈëÄã²Â²âµÄÊý×Ö:" << endl;
			for (j=0; j<3; ++j)	cin >> guess[j];		// guess three numbers 
			correctA=0;
			correctB=0;
			for (j=0; j<3; ++j){				// calculate A 
				if (answer[j] == guess[j]) correctA+=1;		
			}
			for (j=0; j<3; ++j){				// calculate B
				if (answer[j]==guess[(j+1)%3] || answer[j]==guess[(j+2)%3])	correctB+=1;	
			}
			if (correctA==3){
				win+=1;							// record innings for the win 
				cout << "¹§Ï²£¬Äã²Â¶ÔÁË";
				break; 
			}
			else cout << correctA << 'A' << correctB << 'B' << endl;	// output A,B
		}
		if (correctA!=3) {
			cout << "ºÜÒÅº¶£¬ÄãÃ»ÓÐÔÚ¹æ¶¨´ÎÊýÄÚ²Â¶Ô¡£´ð°¸ÊÇ ";
			for (j=0; j<3; ++j){				// output the correct answer 
				cout << answer[j];
			}
		}
		cout << endl << "ÐèÒªÍæÓÎÏ·Âð£¨Y/N£©£¿ ";		// ask the player if he wants to continue
		cin >> choose; 
	}
	cout << "ÄãÒ»¹²ÍæÁË" << games << "¾Ö£¬Ó®ÁË" << win 
		 << "¾Ö£¬ÊäÁË" << games-win << "¾Ö\n";		// output the record
	
	return 0;
}
