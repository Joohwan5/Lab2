/* dltest.c */
#include <stdio.h>  
#include <dlfcn.h>
#include<stdlib.h>
int main()
{
	void *handle;
	int (*add)(int, int), (*minus)(int, int), (*multiply)(int,int); 
        int (*divide)(int,int) ;  
        char *error;
        
	handle = dlopen ("./sub/liboper.so", RTLD_LAZY);
	if (!handle) {
		fputs (dlerror(), stderr);  
		exit(1);
	}
	add = dlsym(handle, "add");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	minus = dlsym(handle, "minus");
	if ((error = dlerror()) != NULL) 
	{  
		fprintf (stderr, "%s", error);  
		exit(1);
	}
	multiply = dlsym(handle, "multiply");
	if ((error = dlerror()) != NULL) 
	{  
		fprintf (stderr, "%s", error);  
		exit(1);
	}

	divide = dlsym(handle, "divide");
	if ((error = dlerror()) != NULL) 
	{  
		fprintf (stderr, "%s", error);  
		exit(1);
	}

	printf ("add(4,2)=%d\n", (*add)(4,2));
	printf ("minus(4,2)=%d\n", (*minus)(4,2));
	printf ("multiply(4,2)=%d\n", (*multiply)(4,2));
	printf ("divide(4,2)=%d\n", (*divide)(4,2));  
	dlclose(handle);
}





 

