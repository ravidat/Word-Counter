#include <stdio.h>


int countWords(){
	FILE *fp;
	fp = fopen("file.txt","r");
      int c;
 	  int ans =0;
  	  while((c = fgetc(fp)) != EOF){
	       if(c != ' ' && c !='\n' && c != '\t'){
		   ans++;
	  	   c = fgetc(fp);
	           while(c != ' ' && c !='\n' && c != '\t'){
	   	       		c = fgetc(fp);
	   	  		}
  	      }
      }
  	 printf("%d \n",ans);
	fclose(fp);
	 return 0;
}  

int countChars(){
	FILE *fp;
	fp = fopen("file.txt","r");
          int c;
 	  int ans =0;
  	  while( (c = fgetc(fp)) != EOF){
	       if(c != ' ' && c !='\n' && c != '\t'){
		   ans++;
  	      }
          }
  	 printf("%d \n",ans);
	fclose(fp);	
	return 0;
}

int longestWord(){
	FILE *fp;
	fp = fopen("file.txt","r");
          int c;
 	  int tmp = 0;
	  int ans = 0;
  	  while( (c = fgetc(fp)) != EOF){
	       if(c != ' ' && c !='\n' && c != '\t'){
		   tmp++;
	  	   c = fgetc(fp);
	           while(c != ' ' && c !='\n' && c != '\t'){
		       tmp++; 
	   	       c = fgetc(fp);
	   	  }
		   if(tmp>ans){
		    ans=tmp;
		   }
		tmp=0;
  	      }
          }
  	 printf("%d \n",ans);
	fclose(fp);	
	return 0;
}

int main(int argc, char **argv){ 
	FILE *fp;
	fp = fopen("file.txt" , "w+");
	int c;
	while((c = fgetc(stdin)) != EOF){
		fputc(c	,fp);
	} 
	fclose(fp);    
    if(argc == 1)
		countWords();
    else{
	
	for(int i=1 ; i<argc ; i++){
  	   if (strcmp(argv[i],"-w")==0){
	       countWords();
   	   }
 	   else if ((strcmp(argv[i],"-c")==0)){
	       countChars();
  	   }
 	   else if ((strcmp(argv[i],"-l"))==0){
	       longestWord();
   	   }  	   	
       }
    }
    return 0; 
}

