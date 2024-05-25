#include<iostream>
#include<cstdlib>
#include<ctime>
//rand() use for the generate random number
// random=offset+(rand()%range);
//int random=1+(rand()%100);
using namespace std;
int main(){
	int choice,pchoice;
	
	cout<<"---------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t \t \t Welcome to The Gussing Number Game!!"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------"<<endl;
	cout<<"You have guess the number b/w 1 to 100. you have limited choice based on choose level. Good Luck!!"<<endl<<endl;
	while(true){
		cout<<"\t-------------------";
		cout<<"\n\t|Choose your Level|\n";
		cout<<"\t-------------------"<<endl;
		cout<<"\n\t|1. Easy  |"<<endl;
		cout<<"\n\t|2. Medium|"<<endl;
		cout<<"\n\t|3. Hard  |"<<endl;
		cout<<"\n\t|0. Exit  |"<<endl;
		cout<<"\t---------------------------";
		
		cout<<"\n\tEnter the Level number: ";
		cin>>choice;
		srand(time(0));
	    int sNumber=1+(rand()%100); //random variable use for the store random number
		if(choice==1){
			cout<<"You have 10 choice for the Guess Number b/w 1 to 100"<<endl;
			cout<<"---------------------------------------------------------------------------------------------------"<<endl;
			int leftchoice=10;
			for(int i=1; i<=10;i++){
				cout<<"\n Enter the Guess Number: ";
				cin>>pchoice;
				if(sNumber==pchoice){
					cout<<"Well Played you won"<<endl;
					cout<<"Thanks For Playing"<<endl;
					cout<<"Play the game again!!"<<endl;
					break;
					cout<<"---------------------------------------------------------------------------------------------------"<<endl;
				}
				else{
					cout<<"Nope!"<<pchoice<<"is not  the right guessing number"<<endl;
					if(pchoice>sNumber){
						cout<<"Secret number is the less than the number you have choosen"<<endl;
						
						
					}
					else{
						cout<<"Secret number is the Greater than the number you have choosen"<<endl;
						
					}
					leftchoice--;
					cout<<leftchoice<<"choice left"<<endl;
					cout<<"---------------------------------------------------------------------------------------------------"<<endl;
					if(leftchoice==0){
						cout<<"You  could't find the guessing number.it was "<<sNumber<<". you lose!"<<endl;
						cout<<"Play the game again"<<endl;
						cout<<"---------------------------------------------------------------------------------------------------"<<endl;
						
					}
				}
			}
		}
		else if(choice==2){
			cout<<"You have 7 choice for the Guess Number b/w 1 to 100"<<endl;
			cout<<"---------------------------------------------------------------------------------------------------"<<endl;
			int leftchoice=7;
			for(int i=1; i<=7;i++){
				cout<<"\n Enter the Guess Number: ";
				cin>>pchoice;
				if(sNumber==pchoice){
					cout<<"Well Played you won"<<endl;
					cout<<"Thanks For Playing"<<endl;
					cout<<"Play the game again!!"<<endl;
					break;
					cout<<"---------------------------------------------------------------------------------------------------"<<endl;
				}
				else{
					cout<<"Nope!"<<pchoice<<"is not  the right guessing number"<<endl;
					if(pchoice>sNumber){
						cout<<"Secret number is the less than the number you have choosen"<<endl;
						
						
					}
					else{
						cout<<"Secret number is the Greater than the number you have choosen"<<endl;
						
					}
					leftchoice--;
					cout<<leftchoice<<"choice left"<<endl;
					cout<<"---------------------------------------------------------------------------------------------------"<<endl;
					if(leftchoice==0){
						cout<<"You  could't find the guessing number.it was "<<sNumber<<". you lose!"<<endl;
						cout<<"Play the game again"<<endl;
						cout<<"---------------------------------------------------------------------------------------------------"<<endl;
						
					}
				}
			}
		}
		else if(choice==3){
				cout<<"You have 4 choice for the Guess Number b/w 1 to 100"<<endl;
				cout<<"---------------------------------------------------------------------------------------------------"<<endl;
			int leftchoice=4;
			for(int i=1; i<=4;i++){
				cout<<"\n Enter the Guess Number: ";
				cin>>pchoice;
				if(sNumber==pchoice){
					cout<<"Well Played you won"<<endl;
					cout<<"Thanks For Playing"<<endl;
					cout<<"Play the game again!!"<<endl;
					break;
					cout<<"---------------------------------------------------------------------------------------------------"<<endl;
				}
				else{
					cout<<"Nope!"<<pchoice<<"is not  the right guessing number"<<endl;
					if(pchoice>sNumber){
						cout<<"Secret number is the less than the number you have choosen"<<endl;
						
						
					}
					else{
						cout<<"Secret number is the Greater than the number you have choosen"<<endl;
						
					}
					leftchoice--;
					cout<<leftchoice<<"choice left"<<endl;
					cout<<"---------------------------------------------------------------------------------------------------"<<endl;
					if(leftchoice==0){
						cout<<"You  could't find the guessing number.it was "<<sNumber<<". you lose!"<<endl;
						cout<<"Play the game again"<<endl;
						cout<<"---------------------------------------------------------------------------------------------------"<<endl;
						
					}
				}
			}
		}
		else if(choice==0){
			exit(0);
		}
		else{
			cout<<"You Entered Wrong choice please Enter 0 to 3 thank you!"<<endl;
		}
		}
		
	
	
	return 0;
}
