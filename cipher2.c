
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *fp;  			//Global file pointer
int i;				//Global i so it can record how many characters in the array have been encryped.
//function used for encryption
void encrypt(char inputText[], int inputLength, int key)
{   
    int mapping[inputLength+1],num,a,b;
    char alp;
    //save letters as coursponding numbers in a array
    for( a = 0; a <= inputLength; a = a + 1 ){
        while(!feof(fp)){
            fscanf(fp,"%c,%d",&alp,&num);
            if(alp==inputText[i]){
            mapping[i] = num;
            i = i+1; 
            rewind(fp);
              }}}
    //encryption process
    for(b = 0;b < inputLength;b = b + 1){
            mapping[b] = mapping[b]-key;
            mapping[b] = mapping[b]+26 ;
            printf(" %d",mapping[b]);  
                                         }
    exit(EXIT_FAILURE);                                     
}  
//function used for decryption 
void decrypt(int cipherText[], int inputLength, int key)
{   
    int num,a,b;
    char alp;
    //add key to numbers
    for(b = 0;b < inputLength;b = b + 1){
            cipherText[b] = cipherText[b]+key;
            if(cipherText[b]>26){
            	cipherText[b] = cipherText[b]-26 ;
        		}

    }
    //decryption process
    for( a = 0; a <= inputLength; a = a + 1 ){
        while(!feof(fp)){
            fscanf(fp,"%c,%d",&alp,&num);
            if(num == cipherText[i]){
                printf("%c",alp);
                i = i+1; 
                rewind(fp);
              }}}
    printf("\n");
    exit(EXIT_FAILURE);
   
}   
int main (int argc, char *argv[])
{
    int i_position,k_position,m_position,check_position,pos,k_value,m_value,inputLength,cipherText[21],a,b,counter;
    char inputText[21];
    check_position = 9;
   //check number of argument
    if (argc != 7) {
		printf("Extra arguments or insufficient arguments.  Please re-run the program\n");
		exit(EXIT_FAILURE);}
   //check -i position
    pos = 1;
    while(strcmp(argv[pos],"-i")!= 0 && pos < 5){
        pos = pos +2;}
    if(strcmp(argv[pos],"-i")==0){
            i_position = pos;
    } 
    else{
            i_position = 0;
    }
   //check -k position
    pos = 1;
    while(strcmp(argv[pos],"-k") !=0 && pos < 5){
        pos = pos +2;}
    if(strcmp(argv[pos],"-k")==0){
        k_position = pos;
    } 
    else{
        k_position = 0;
    }
     
   //check -m position
    pos = 1;
    while(strcmp(argv[pos],"-m")!= 0 && pos < 5){
    pos = pos +2;}
    if(strcmp(argv[pos],"-m")==0){
        m_position = pos;
    } 
    else{
        m_position = 0;
    }
       
    //find out which argument is missing and print error message
    if(m_position == 0||i_position == 0||k_position == 0){
         check_position =  check_position-m_position-i_position-k_position;
         printf("Unrecognized argument %s. Please re-run the program\n",argv[check_position]);
         exit(EXIT_FAILURE);

    }
    //check if the file exist
    fp = fopen(argv[i_position + 1],"r");
	if (fp == NULL){ 
		fprintf(stderr, "Cannot open mapping file\n");
		exit(EXIT_FAILURE);
	}
    //check if k value is right
    k_value = atoi(argv[k_position+1]);
    if(k_value > 25||k_value < 1){
        printf("You entered %d. Sorry, your key must be between 1 and 25. Re-run the program and try again\n",k_value);
        exit(EXIT_FAILURE);
    }
    m_value = atoi(argv[m_position+1]); 
    if(m_value != 1 && m_value != 2){
        printf("Unidentified mode. Run again!\n");
        }
    //run encrypt
    if(m_value == 1){ 
    printf("Enter the word you want to encrypt, up to 20 characters\n");
    scanf("%s",inputText);
    inputLength = strlen(inputText);
    encrypt(inputText,inputLength,k_value);
    }
    //run decrypt
    else if(m_value == 2){
        printf("Enter the encrypted word you want to decrypt, upto 20 space-separated numbers. Put any letter at the end of your message\n"); 
        for(b = 0;b < 21;b = b + 1){
            if(scanf("%d",&a)){;
            cipherText[b] = a;
            counter = counter + 1;
        					  }     
        						   }
    decrypt(cipherText,counter,k_value);
    					}   
    }
