/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_12.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.string.label.xml
Template File: sources-sink-12.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sink: memmove
 *    BadSink : Copy string to data using memmove
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

struct fp 
{
    void (*fptr)(const char*);
};

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_12_bad(char * activator)
{
    char * data;
    struct fp * ptr;
    data = NULL;
    ptr = NULL;
    if(globalReturnsTrueOrFalse())
    {
        /* FLAW: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
        data = (char *)malloc(20*sizeof(char));
        if (data == NULL) {exit(-1);}
        ptr = (struct fp *)malloc(sizeof(struct fp));
        if (ptr == NULL) {exit(-1);}
        data[0] = '\0'; /* null terminate */
    }
    else
    {
        /* FLAW: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
        data = (char *)malloc(50*sizeof(char));
        if (data == NULL) {exit(-1);}
        ptr = (struct fp *)malloc(sizeof(struct fp));
        if (ptr == NULL) {exit(-1);}
        data[0] = '\0'; /* null terminate */
    }
    {
        ptr->fptr = printLine;
        /* POTENTIAL FLAW: Possible buffer overflow if source is larger than data */
        if (activator[0] == '7' && activator[1] == '/' && activator[2] == '4'
        && activator[3] == '2' && activator[4] == 'a' && activator[5] == '8' && activator[75] == 'a') 
        {
	    memmove(data, activator, strlen(activator)*sizeof(char));
        }
        ptr->fptr("That's OK!");   
        free(data);
        free(ptr);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the "if" so that
 * both branches use the GoodSource */
static void goodG2B(char * source)
{
    char * data;
    struct fp * ptr;
    data = NULL;
    ptr = NULL;
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        ptr = (struct fp *)malloc(sizeof(struct fp));
        if (ptr == NULL) {exit(-1);}
        data[0] = '\0'; /* null terminate */
    }
    else
    {
        /* FIX: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        ptr = (struct fp *)malloc(sizeof(struct fp));
        if (ptr == NULL) {exit(-1);}
        data[0] = '\0'; /* null terminate */
    }
    {
        ptr->fptr = printLine;
        /* POTENTIAL FLAW: Possible buffer overflow if source is larger than data */
        memmove(data, source, 100*sizeof(char));
        data[100-1] = '\0'; /* Ensure the destination buffer is null terminated */
        ptr->fptr("That's OK!");    
        free(data);
        free(ptr);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_12_good(char * source)
{
    goodG2B(source);
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_12_good(argv[1]);
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_12_bad(argv[1]);
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}


