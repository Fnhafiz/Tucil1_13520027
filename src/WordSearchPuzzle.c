#include<stdio.h>
#include<string.h>
#include <time.h>
#define BLANK ' '

void openFile();
void start();
int check(int a ,int b );
int VerDown(int a ,int n, int b,char test[]);
int VerUp(int a ,int n, int b,char test[]);
int HorRight(int a ,int n, int b,char test[]);
int HorLeft(int a ,int n, int b,char test[]);
int DiagDownRight(int a ,int n, int b,char test[]);
int DiagDownLeft(int a ,int n, int b,char test[]);
int DiagUpRight(int a ,int n, int b,char test[]);
int DiagUpLeft(int a ,int n, int b,char test[]);
void deleteblankspaces(char *s);

char word[100][100];
char puzzle[100][100];
char answer[50][50];
char *file;
int p , h ;

int main(){
    openFile ();
    clock_t t;
    t = clock();
    start();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Waktu eksekusi program :  %f detik", (time_taken));
	return 0 ; 
}

void openFile (){
	FILE *fp;
	int countrows;
	printf("Masukkan nama file : ");
	scanf("%s", file);
	fp = fopen(file,"r");
	if (fp== NULL) {
		printf("File tidak ditemukan\n");
	}
	p = 22;
	h = 20;
	char  line[100], line2[100];
	int i, rows=0;
	while (fgets (line, sizeof(line), fp) != NULL && rows < p){
		for (i=0; i < (strlen(line)-1); i++){
			puzzle[rows-1][i] = line[i];
		}   
		rows++;  
	}
	for(i=0; i<(strlen(line)-1); i++)
	puzzle[rows-1][i] = line[i];
	rows = -1;
	while (fgets(line2, sizeof(line2), fp) != NULL){
	for(i=0; i<(strlen(line2)-1); i++){
		word[rows][i] = line2[i];}
		rows++; 
	}
	for (rows = 0; rows<p; rows++){
		deleteblankspaces(puzzle[rows]);
	}	
}

void start(){
    int i=0 , j=0 ;
    int leter ,x=0, count = 0;
    char choose[5];
    printf("\n");
	for (x=0;x<h;x++){
		for(i=0;i<40;i++){
			for(j=0;j<40;j++){
				count++;
				if(puzzle[i][j] == word[x][0]){
					leter = strlen(word[x]);
					if (check(i+leter-1 ,j ) == 1 && VerDown (i,leter,j,word[x]) == 1){ //down					
						int a=0, b=0, c=0;
						for (a=0; a<p; a++){
							for (b=0; b<p; b++){
								if (a==i+c && b==j && c<leter){
									printf("%c", word[x][c]);
									c++;
									printf(" ");						
								}
								else {
									printf("-");
									printf(" ");
								}
							}
							printf("\n");
						}
						printf("%s", word[x]);
						printf("\nTotal Perbandingan Huruf : ");
						printf("%d", count); 
						printf("\n\n");
						count = 0;
					}
					else if ( check(i ,j+leter-1 )==1 && HorRight(i,leter,j,word[x])==2){ //right
						int a=0, b=0, c=0;
						for (a=0; a<p; a++){
							for (b=0; b<p; b++){
								if (a==i && b==j+c && c<leter){
									printf("%c", word[x][c]);
									c++;
									printf(" ");						
								}
								else {
									printf("-");
									printf(" ");
								}
							}
							printf("\n");
						} 
						printf("%s", word[x]);
						printf("\nTotal Perbandingan Huruf : ");
						printf("%d", count); 
						printf("\n\n");
						count = 0;
					}
					else if ( check(i+leter-1 ,j+leter-1 )==1 && DiagDownRight(i,leter,j,word[x])==3){ //Down, Right
						int a=0, b=0, c=0;
						for (a=0; a<p; a++){
							for (b=0; b<p; b++){
								if (a==i+c && b==j+c && c<leter){
									printf("%c", word[x][c]);
									c++;
									printf(" ");						
								}
								else {
									printf("-");
									printf(" ");
								}
							}
							printf("\n");
						} 
						printf("%s", word[x]);
						printf("\nTotal Perbandingan Huruf : ");
						printf("%d", count); 
						printf("\n\n");
						count = 0;
					}
					else if ( check(i ,j-leter+1 )==1&& HorLeft(i,leter,j,word[x])==4){ //left
						int a=0, b=0, c=leter-1, d=0;
						for (a=0; a<p; a++){
							for (b=0; b<p; b++){
								if (a==i && b==j-c && c>=0){
									printf("%c", word[x][c]);
									c--; d++;
									printf(" ");
								}
								else {
									printf("-");
									printf(" ");
								}
							}
							printf("\n");
						} 
						printf("%s", word[x]);
						printf("\nTotal Perbandingan Huruf : ");
						printf("%d", count); 
						printf("\n\n");
						count = 0;
					}
					else if ( check(i-leter+1 ,j )==1&&VerUp(i,leter,j,word[x])==5){ //up
						int a=0, b=0, c=leter-1, d=0;
						for (a=0; a<p; a++){
							for (b=0; b<p; b++){
								if (a==i-c && b==j && c>=0){
									printf("%c", word[x][c]);
									c--; d++;
									printf(" ");
								}
								else {
									printf("-");
									printf(" ");
								}
							}
							printf("\n");
						} 
						printf("%s", word[x]);
						printf("\nTotal Perbandingan Huruf : ");
						printf("%d", count); 
						printf("\n\n");
						count = 0;
					}
					else if ( check(i-leter+1 ,j+leter-1 )==1&&DiagUpRight(i,leter,j,word[x])==6){ //Up, Right
						int a=0, b=0, c=leter-1, d=0;
						for (a=0; a<p; a++){
							for (b=0; b<p; b++){
								if (a==i-c && b==j+c && c>=0){
									printf("%c", word[x][c]);
									c--; d++;
									printf(" ");
								}
								else {
									printf("-");
									printf(" ");
								}
							}
							printf("\n");
						} 
						printf("%s", word[x]);
						printf("\nTotal Perbandingan Huruf : ");
						printf("%d", count); 
						printf("\n\n");
						count = 0;
					}
					else if ( check(i-leter+1 ,j-leter+1 )==1&&DiagUpLeft(i,leter,j,word[x])==7){ //Up, Left
						int a=0, b=0, c=leter-1, d=0;
						for (a=0; a<p; a++){
							for (b=0; b<p; b++){
								if (a==i-c && b==j-c && c>=0){
									printf("%c", word[x][c]);
									c--; d++;
									printf(" ");
								}
								else {
									printf("-");
									printf(" ");
								}
							}
							printf("\n");
						} 
						printf("%s", word[x]);
						printf("\nTotal Perbandingan Huruf : ");
						printf("%d", count); 
						printf("\n\n");
						count = 0;
					}
					else if ( check(i+leter-1 ,j-leter+1 )==1&&DiagDownLeft(i,leter,j,word[x])==8){ //Down, Left
						int a=0, b=0, c=leter-1, d=0;
						for (a=0; a<p; a++){
							for (b=0; b<p; b++){
								if (a==i+c && b==j-c && c>=0){
									printf("%c", word[x][c]);
									c--; d++;
									printf(" ");
								}
								else {
									printf("-");
									printf(" ");
								}
							}
							printf("\n");
						} 
						printf("%s", word[x]);
						printf("\nTotal Perbandingan Huruf : ");
						printf("%d", count); 
						printf("\n\n");
						count = 0;
					}
				}
			}
		}
	}
}

int check(int a ,int b ){
	if(puzzle[a][b] != 0)
	return 1 ;
	else
	return -1 ;
}

int VerDown(int a ,int n, int b,char test[]){
	char test2[n];
	int i=0;
	for (i=0;i<n;i++){
		test2[i] = puzzle[a][b];
		a++;
	}
	test2[n] = '\0';
	if(strcmp(test2,test) == 0){
		return 1 ;
	}
	else
	return -1 ;
}

int HorRight(int a ,int n, int b,char test[]){
	char test2[n];
	int i=0;
	for (i=0;i<n;i++){
        test2[i]= puzzle[a][b];
        b++;
    }
	test2[n] = '\0';
	if(strcmp(test2,test)==0){
	    return 2 ;
    }
	else
	return -1 ;
}

int DiagDownRight(int a ,int n, int b,char test[]){
	char test2[n];
	int i=0;
	for (i=0;i<n;i++){
        test2[i]= puzzle[a][b];
        b++;
        a++ ;
	}
	test2[n] = '\0';
	if(strcmp(test2,test)==0){
	    return 3 ;
    }
	else
	return -1 ;
}
int HorLeft(int a ,int n, int b,char test[]){
	char test2[n];
	int i=0;
	for (i=0;i<n;i++){
        test2[i]=puzzle[a][b];
        b--;
	}
	test2[n] = '\0';
	if(strcmp(test2,test)==0){
	    return 4 ;
    }
	else
	return -1 ;
}
int VerUp(int a ,int n, int b,char test[]){
	char test2[n];
	int i=0;
	for (i=0;i<n;i++){
        test2[i]= puzzle[a][b];
        a--;
	}
	test2[n] = '\0';
	if(strcmp(test2,test)==0){
	    return 5 ;
    }
	else
	return -1 ;
}
int DiagUpRight(int a ,int n, int b,char test[]){
	char test2[n];
	int i=0;
	for (i=0;i<n;i++){
        test2[i]= puzzle[a][b];
        a--;
        b++;
	}
	test2[n] = '\0';
	if(strcmp(test2,test)==0){
	    return 6 ;
    }
	else
	return -1 ;
}
int DiagUpLeft(int a ,int n, int b,char test[]){
	char test2[n];
	int i=0;
	for (i=0;i<n;i++){
        test2[i]= puzzle[a][b];
        a--;
        b--;
	}
	test2[n] = '\0';
	if(strcmp(test2,test)==0){
	    return 7 ;
    }
	else
	return -1 ;
}
int DiagDownLeft(int a ,int n, int b,char test[]){
	char test2[n];
	int i=0;
	for (i=0;i<n;i++){
        test2[i]= puzzle[a][b];
        a++;
        b--;
	}
	test2[n] = '\0';
	if(strcmp(test2,test)==0){
	    return 8 ;
    }
	else
	return -1 ;
}

void deleteblankspaces(char *s)
{
	int  i,k=0;
 
	for(i=0;s[i];i++)
    {
     	s[i]=s[i+k];
 
     	
     	if(s[i]==' '|| s[i]=='\t')
     	{
		  k++;
		  i--;
	    }
     	
    }
}
