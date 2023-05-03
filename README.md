# c_libs

These libraries augment the C language with additional features and expedite development processes. My collection continually expands as new decisions are incorporated periodically. All libraries are personally developed by me.

# What are the solutions?

- **charMaster.h**
	- `Int2Char()` — Returns a number as a char literal.
	- `Char2Int()` — If literal is number returns its int equivalent.
- **dca.h**
	- `dca` — A new data type (dynamic character array) which is a structure containing the fields array (literal) and size (literal size in characters).
	- `create_dca()` — Returns dca which contains the literal passed as the argument.
	- `create_empty_dca` — Macro to create an empty dynamic character array (equal `create_dca(NULL)`).
	- `get()` — Function to get the value at a given position of the dynamic character array.
	- `add()` — Function to add a character to the end of the dynamic character array.
	- `clear` — Function to free the memory allocated for the dynamic character array and reset its size to zero (clear dca).
	- `set()` — Function to set a value at a given position of the dynamic character array.
	- `sets()` — Function to clear the dynamic character array and set a string of characters at the end of it.
	- `ksets()` — Function to set a string of characters at the end of the dynamic character array.
	- `del()` — Function to delete a value at a given position of the dynamic character array and shift all values after the specified position.
	- `input()` — Function to get input from the user and return a dynamic character array containing the input string.
