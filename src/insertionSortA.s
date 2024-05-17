    .global a_insertion_sort
    .data
    szTest:     .asciz          "Test"
    .text

a_insertion_sort:
    STR x30, [SP, #-16]!

    // X0 - The Address of Array
    // X1 - The Size

    MOV X19, #1             // i variable
    MOV X20, #0             // j variable
    MOV X23, X0             // Copy Of the Array a[j]
    MOV X24, X0             // Copy of the Array a[j+1]
    
outerLoop:
    CMP X19, X1             // Is step < Size?
    B.GE end                // If not, jump to end

    // key = array[step]
    ADD X2, X0, X19, LSL #3 // X2 = address of array[step]
    LDR X21, [X2]           // Load key into X21

    // j = step - 1
    SUB X20, X19, #1

innerLoop:
    CMP X20, #0             // Is j >= 0?
    B.LT insertKey           //  insert the key

    ADD X3, X0, X20, LSL #3 // X3 = address of array[j]
    LDR X22, [X3]           // Load array[j] into X22

    CMP X22, X21            // compare array[j] and key
    B.LE insertKey          // If array[j] <= key, insert the key

    // array[j + 1] = array[j]
    ADD X4, X0, X20, LSL #3 // x4 = address of array[j + 1]
    ADD X4, X4, #8
    STR X22, [X4]           // store array[j] into array[j + 1]

    // j--
    SUB X20, X20, #1
    B innerLoop             // repeat the inner loop

insertKey:
    ADD X5, X0, X20, LSL #3 // x5 = address of array[j + 1]
    ADD X5, X5, #8
    STR X21, [X5]           // store key into array[j + 1]

    // step++
    ADD X19, X19, #1
    B outerLoop             // repeat the outer loop

end:
    LDR x30, [SP], #16
    RET
