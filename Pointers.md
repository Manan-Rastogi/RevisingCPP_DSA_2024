# Pointer Notes From ChatGPT. 

## Why Pointers are Essential?

- When a variable like `int x = 5;` is declared, it occupies memory.
- Memory is addressed using hexadecimal addresses.
- The compiler maintains a symbol table mapping variable names to their memory addresses and values.
- Example: `x -> SymbolTable[address(x)] -> value(x)`

## Memory Operations:

- Operations like `x = x + 1;` involve:
  - Retrieving `x`'s value from memory.
  - Updating `x`'s value.
  - Storing the updated value back in memory.
- This necessitates the use of pointers to handle memory addresses.

## Pointer Basics:

- Pointers store memory addresses.
- `int* ptr = &x;` assigns the address of `x` to `ptr`.
- Dereferencing: `*ptr` accesses the value at the address stored by `ptr`.

## Passing by Value vs. Passing by Reference:

- **Call by Value:** Changes to a variable inside a function do not affect the original variable.
- **Call by Reference:** Changes to a variable inside a function affect the original variable.

## Pointer Size:

- Pointers always occupy 8 bytes of memory, regardless of the type of data they point to.

## Pointer Arithmetic:

- Pointers support arithmetic operations like increment and decrement.
- Example: `*ptr = *ptr + 1;` increases the value at the memory address pointed by `ptr`.

## Coping a Pointer:

- `int *p = &num;`
- `int *q = p;` assigns the address stored in `p` to `q`.

### BAD Practices:

- Declaring a pointer without initialization can lead to accessing garbage memory addresses.
- Assigning NULL (0) to a pointer can result in segmentation faults.
- Avoid multiple steps in pointer initialization for clarity and to prevent errors.

## Pointers with Array

### Array and Addresses

- `int arr[10];`: Memory allocation: 10 * sizeof(int) = 10 * 4 bytes.
- `arr` indicates the first block of the array.
- Address of `arr[3]`: `arr + 3`.
- `arr[i] = *(arr + i)`.
- `i[arr] = *(i + arr)`: Internally calculated as `*(arr + i)`.
- `&arr == arr == &arr[0]`: All represent the address of the first element.

### Difference: Pointers vs. Array

- `int arr[10];`: `sizeof(arr) = 10 * 4 = 40` bytes.
- `int *pa= &arr[0]`: `sizeof(pa) = 8` bytes.
- `arr == &arr != &pa`: `&arr` is the address of the first element, `&pa` is the address of the pointer to the array.
- Changing content of Symbol Table not possible for arrays.
- Addresses can be changed for pointers.

## Pointers with char Array

### int vs char array and pointers

- `int arr[2] = {1, 2};`, `char carr[3] = "12";`: Last char is null character (`'\0'`).
- `cout <<` implemented differently for char and int.
- `char *pc = &carr[0];`: `pc` gives the first char, `*pc` prints entire string until `'\0'`.
- Risky: If `'\0'` is not present, it keeps iterating, printing garbage characters.

### Difference between char and char*

- `char ch[5] = "abcd";`: Temp memory for RHS string copied to `ch` array.
- `char *c = "abcd";`: Temp memory allocated to `"abcd\0"`, its first char's address referenced by `*c`.

## Pointers and Function

### Function Parameter Passing

- `void update(int *p)`: `p = p + 1;` does not update pointer, `*p++` updates value.
- Actual pointer cannot be changed inside a function.
- `int sum(int arr[], int n)`: `arr` is a pointer, not the array itself.
- `sizeof(arr)` inside `sum` function gives `8`.
- Benefit: Faster than passing the whole array, no copy of array created, only pointer passed.
  - Example: `sum(arr+2, 3)`: Sending from the 3rd element.
