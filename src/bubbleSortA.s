        
    .global a_bubble_sort
	.data
    szTest:     .asciz          "Test"
	.text
	
a_bubble_sort:  
    STR x30, [SP, #-16]!
    
    // X0 - The Address of Array
    // X1 - The Size
    MOV X19, #0             // I variable
    MOV X20, #0             // J variable
    MOV X23, X0             // Copy Of the Array a[j]
    MOV X24, X0             // Copy of the Array a[j+1]
    outerLoop:
        CMP X19, X1         // Is I > Size
        b.ge end            // if true jump to end
        innerLoop:
            SUB X25, X1, X19    // Lenght - i
            SUB X25, X25, #1    // Length - i - 1
            CMP X20, X25        // IS J > length - i - 1
            b.ge endInnerLoop   // If true jump to endInnerLoop
            //----if SWAP----------------------
            ADD X2, X23, X20, LSL #3  // x2 = a[j]
            ADD X3, X2, #8            // X3 = a[j+1]

            LDR X4, [X2]               // value in a[j]
            LDR X5, [X3]               // value in a[j+1]

            CMP X4, X5
            B.LE noSwap                 // a[j] < a[j+1]

            STR X5, [X2]                    // Store a[j+1] into a[j]
            STR X4, [X3]                    // Store a[j] into a[j+1]


            //------------------------------
    noSwap:
        ADD X20, X20, #1 // increment(j++)
        b innerLoop

    
    endInnerLoop:
        MOV X20, #0         // reset j 
        ADD X19, X19, #1    // Increment (i++)  
        b outerLoop
end:
    ldr x30, [SP], #16
    ret
