#include <stdlib.h>
#include<stdio.h>
#include<string.h>

char* replaceWord(const char* s, const char* oldW, 
                const char* newW) {
	char *result  ;
	int i , cnt=0  ;
	int newlen = strlen(newW ) ;
	int oldlen =strlen(oldW);
	// ayoub va a l'ecole  ayoub , 
	for(i = 0 ; s[i]!='\0';i++) {
		if(strstr(&s[i] , oldW  )==&s[i])  {
			cnt++ ;
			i+=oldlen -1;
		}
		
	}
	int _m = abs(newlen-oldlen);
	result = (char* ) malloc(sizeof(char) *  (i+cnt * _m + 1)) ;
	
	i = 0;
	
	while(*s) {
	   if(strstr(s,oldW) == s) {
		   strcpy(result[i], newW);
		   i+= newlen ;
		   s+= oldlen;
	   }
	   else result[i++] = *s++;
	   
	   
	   result[i] = '\0';
	   
	   
	   return result;
	}
}


char *findAndreplace(char *_src  , const char *find_ , cont char *repl_) {
	
	 int srclen  =strlen(_src );
	 int find_len = strlen(find_ );
	 int repl_len =strlen(repl_ );
	 
	 char *result  ;
	 
	 int i , cnt=0 ;
	 for ( i=0 ; s[i] !='\0' ;i++ )
	 {
		 
	 }
	
	
}


int main()
{
   

  








      char *sfc = "254071268A1SC000R240670021";

    char *msg =(char *) malloc (sizeof(char) *1024 ) ;
		msg=strstr((char*)"254071268A1SC000R240670021",(char*)"254071268");

   

    int m =strstr((char*)"254071268A1SC000R240670021",(char*)"254071268")!=NULL;


    printf("%d",m );

	
	int                 Status = 0;
	// char test[8000];
	
	char Ciesn[50];
	int  ISncompareToFlachSfc = -1 ;
	char *SNSfccSearch="";
							 
	strcpy(Ciesn, (char*)"254071268"  ) ;
	  
	
		   //254071268
	do
	{
		
	   printf("printf ok") ;

        SNSfccSearch= strstr(sfc,Ciesn) ;

        printf("%s " , SNSfccSearch);
        ISncompareToFlachSfc = SNSfccSearch !=NULL ;
        printf("%d" , ISncompareToFlachSfc);
        
	}
	while ( strlen(sfc) != 27    &&  ISncompareToFlachSfc != 1   );
	 
		  

	
	return 0;
}




