/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_17.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-17.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sink: cpy
 *    BadSink : Copy string to data using strcpy()
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

struct fp 
{
    void (*fptr)(const char*);
};
/* MAINTENANCE NOTE: The length of this string should equal the 40 */
#define SRC_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_17_bad(char * activator)
{
    int i;
    char * data;
    struct fp * ptr;
    data = NULL;
    ptr = NULL;
    for(i = 0; i < 1; i++)
    {
        /* FLAW: Did not allocate space based on the source length */
        data = (char *)malloc(20*sizeof(char));
        if (data == NULL) {exit(-1);}
        ptr = (struct fp *)malloc(sizeof(struct fp));
        if (ptr == NULL) {exit(-1);}
    }
    {
        ptr->fptr = printLine;
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        if (activator[0] == '7' && activator[1] == '/' && activator[2] == '4'
	&& activator[3] == '2' && activator[4] == 'a' && activator[5] == '8' && activator[75] == 'a') 
        {
            strcpy(data, activator);
        }
        ptr->fptr("That's OK!");    
        printLine(data);
        free(data);
        free(ptr);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the conditions on the for statements */
static void goodG2B()
{
    int h;
    char * data;
    struct fp * ptr;
    data = NULL;
    ptr = NULL;
    for(h = 0; h < 1; h++)
    {
        /* FIX: Allocate space for a null terminator */
        data = (char *)malloc((40+1)*sizeof(char));
        if (data == NULL) {exit(-1);}
        ptr = (struct fp *)malloc(sizeof(struct fp));
        if (ptr == NULL) {exit(-1);}
    }
    {
        char source[40+1] = SRC_STRING;
        ptr->fptr = printLine;
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        strcpy(data, source);
        ptr->fptr("That's OK!"); 
        printLine(data);
        free(data);
        free(ptr);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_17_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */


int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_17_bad(argv[1]);
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

