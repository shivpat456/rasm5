    .global _main
	
	.data
	.text
	
_main:
    
    
    
    
// Setup the parameters to exit the program
// and then call Linux to do it.
   mov X0, #0 	// Use 0 return code   
   mov X8, #93 //  Service code 93 terminates
   svc 0 // Call Linux to terminate

	.end
