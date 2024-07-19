#include<iostream>
// #define NAME rest of line 
// name of this macro = NAME 
// #define MAC(x,y) argument1 : x argument2 : y 
#define FOREVER for(;;)
#define MIN(a,b) ((a < b )? a : b)
#define NEWSTRING(a,b) a##b /* '##' is used to concatenate string through macros */
#define PRINTX(x) std::cout << #x << " =  " << x << std::endl ;
#define ARG 2 


#ifdef ARG
void fn(int a) {
	std::cout << ARG << a << std::endl;
}
#endif

 
int main() {
	FOREVER{
		std::cout << "TRue " << std::endl;
		break;
	}
	std::cout << MIN(2, 3) << std::endl;
	std::cout << NEWSTRING("NOMAAN", "MUMTAZ") << std::endl;
	PRINTX(2);
	fn(2);
	std::cout << __cplusplus << std::endl;
	std::cout << __DATE__ << std::endl;
	std::cout << __TIME__ << std::endl;
	// There are more predefined MACROS as well
}
