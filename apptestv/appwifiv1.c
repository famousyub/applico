//==============================================================================
//
// Title:		appwifiv1
// Purpose:		A short description of the application.
//
// Created on:	03/06/2024 at 08:37:46 by .
// Copyright:	. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include  <string.h>
#include <stdlib.h>

#include <stdio.h>



#include "appwifiv1.h"
#include "toolbox.h"





//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

static int panelHandle = 0;

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

/// HIFN The main entry-point function.





void search (int a , const char *tag ,  char  *msg , int _input ) ;



void search (int a , const char *tag ,  char  *msg , int _input )
{
	
   
	 
	      
	  
	   int i = 0;
	   int  taglen = strlen(tag );
	   int msglen =strlen(msg ) ;
	    char *ptr = msg ;
		
	   
	   char * searching  =  (char * ) malloc (  msglen * sizeof (char  ))  ;
	   
	   searching  = (char *) strstr(ptr, tag);
	   
	   
	   
	   
	   
	   while (*ptr!= '\0' ) 
	   {
		   if(    searching!= NULL)
			   
            {
				puts(searching) ;
				
				
				ptr +=  taglen ;
				
				
				
				
				printf(" searching %s  pos  %d     tag %s   %s , \n" ,  searching , i , tag , ptr);
				
				i+= taglen;
				
				 
			}  else {ptr++ ; i++; } 
			searching  = (char *) strstr(ptr, tag);
					
	   }
	  
	   
	   
	   
	   						  
											  
											  
	
	   
	
}







// --helper function to find length--
// return string length
int getLen(char *string){
    int len = 0;
    for(int i = 0; string[i] != '\0'; i++) len++;
    return len;
}


// -- use this for inputs taken with fgets() and functions that add newline to your string input --
// removes trailing newlines
void trim(char *string, int strLength){
    int i;
    // get index of last non-newline character
    for(i = strLength - 1; string[i] == '\n'; i--){
    }
    string[++i] = '\0';
}


// helper function to check if group matches pattern
int matchFound(int start, char *str, char *pattern){
    int patternLen = getLen(pattern);
    
    // compare current group with pattern
    for(int i = start, k = 0; i < patternLen + start; i++, k++){
        if (str[i] != pattern[k]) return 0;
    }
    return 1;
}


// return the string with replaced pattern
// args: original string, pattern string, replacing substring 
char *replace(char *original, char *pattern, char *newSubstr){

    char *newStr = malloc(100);
    int i;
    // to traverse the result string
    int newIndex = 0;
    int oldLength = getLen(original);
    int newLength = getLen(newSubstr);
    int patternLen = getLen(pattern);

    // get the (first) index of character that cant be grouped
    int end = oldLength - oldLength % patternLen;

    // go through all possible groups
    for(i = 0; i < end; ){
        
        // replace group with new substring
        if (matchFound(i, original, pattern)){
            for(int k = 0; k<newLength; k++, newIndex++){
                newStr[newIndex] = newSubstr[k];
            }
            //start from next group index
            i += patternLen;
            continue;
        }

        // copy unmatched character to result
        newStr[newIndex] = original[i];
        newIndex++;
        i++;
    }

    // copy remaining unmatched characters 
    for(; i<oldLength; i++, newIndex++){
        newStr[newIndex] = original[i];
    }

    newStr[newIndex] = '\0';
    return newStr;
}






int main (int argc, char *argv[])
{
	int error = 0;
	
	
	search(12 , "#telnet" , "#telnet, hello thzere  ,  hello  #telnet " ,15 ) ;
	
	
	/* initialize and load resources */
	nullChk (InitCVIRTE (0, argv, 0));
	errChk (panelHandle = LoadPanel (0, "appwifiv1.uir", PANEL));
	
	/* display the panel and run the user interface */
	errChk (DisplayPanel (panelHandle));
	errChk (RunUserInterface ());

Error:
	/* clean up */
	if (panelHandle > 0)
		DiscardPanel (panelHandle);
	return 0;
}

//==============================================================================
// UI callback function prototypes

/// HIFN Exit when the user dismisses the panel.
int CVICALLBACK panelCB (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	if (event == EVENT_CLOSE)
		QuitUserInterface (0);
	return 0;
}
