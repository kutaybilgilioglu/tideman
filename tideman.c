#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

	
	int preferences [MAX_VOTERS][MAX_CANDIDATES];
	typedef struct{
		char name[10];
		int votes;
		bool eliminated;
	}
	candidate;
	candidate candidates[MAX_CANDIDATES];
	int voter_count;
	int candidate_count;
	bool vote(int voter, int rank, char name[]);
	void tabulate(void);
	bool print_winner(void);
	int find_min(void);
	bool is_tie(int min);
	void eliminate(int min);
int main(){
	printf("oy sayisi");
	scanf("%d",&voter_count);
	printf("aday sayisi");
	scanf("%d",&candidate_count);
	int i;
	for(i=0;i<candidate_count ;i++){	
	printf(" %d. adayi giriniz",i+1);
	gets(candidates[i].name);
	candidates[i].votes=0;
	candidates[i].eliminated=false;
}
int j;

for(i=0;i<voter_count;i++){
	printf("%d.oy\n",i);
	for( j=0;j<candidate_count;j++){
		printf("%d.aday girin",j+1);
		char name[10];
		gets(name);
		if(!vote(i,j,name)){
			printf("invalid");
			return 2;
		}
	}
	printf("\n");
}
while(true){
	tabulate();
	bool won = print_winner();
	if(won){
		break;
	}
	int min = find_min();
	bool tie = is_tie(min);
	if(tie){
		for(i=0;i<candidate_count;i++){
			if(!candidates[i].eliminated){
				printf("%s\n",candidates[i].name);
			}
		}
		break;
	}
	eliminate(min);
	for(i=0;i<candidate_count;i++){
		candidates[i].votes=0;
	}
}
	
	return 0;
}

bool vote(int voter, int rank, char name[]){
	bool exist = false;
	int i;
	for( i=0;i<candidate_count;i++){
		if(strcmp(name,candidates[i].name)==0){
			preferences[voter][rank]=i;
			exist = true;
			break;
		}
	}
	return exist;
}
void tabulate(void){
	int i;
	int j;
	for( i=0;i<voter_count;i++){
		for( j=0;j<candidate_count;j++){
			if(candidates[preferences[i][j]].eliminated==0){
				candidates[preferences[i][j]].votes+=1;
				break;
			}
		}
		
	}
	return;
}
bool print_winner(void){
	int i;
	int j;
	char most[10];
	for(i=0;i<candidate_count;i++){
		for(j=0;j<10;j++){
		most[i]=candidates[i].name;
	}
		if(candidates[i].votes>voter_count/2){
			printf("%s",most);
			return true;
		}
	}
	return false;
}
int find_min(void){
	int i;
	int minvotes = voter_count;
	for( i=0;i<candidate_count;i++){
		if(candidates[i].eliminated==false && candidates[i].votes<minvotes){
			minvotes = candidates[i].votes;
		}
	}
	return minvotes;
}
bool is_tie(int minvotes){
	int i;
	for( i=0;i<candidate_count;i++){
		if(candidates[i].votes==minvotes){
			candidates[i].eliminated=true;
		}
	}
	return;
}
void eliminate(int minvotes){
	int i;
	for( i=0;i<candidate_count;i++){
		if(candidates[i].votes==minvotes){
			candidates[i].eliminated=true;
		}
	}
	return;
}












