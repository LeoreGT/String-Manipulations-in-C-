#ifndef __STRING_CLASS_H__
#define __STRING_CLASS_H__

#include <stdlib.h>
#include <string.h>
/*
 * Leore Golan
 * C++ implementstion of string class functions
*/
class String_t
{
	public:
		String_t();
    ~String_t();
    String_t(const char* string);
    String_t(const String_t& string);
    const String_t& operator=(const String_t& _str); 
		int 	          getLength() const; /* const outside because it recieves but doesn't alter the struct data */
    void            resizeString(int incomingSize); /* acts as a reallocator if it's needed  TODO can be private */
		void				    setString(const char* string);
		const char*     getString() const; /* const outside because it recieves but doesn't alter the struct data */
		int	            compareStrings(const String_t& string) const; /* checking against a reference to another string */
		void				    printString() const;


	private:
		char* m_string;
    int   m_stringSize;
		char* createFrom(char* string); /* TODO get const */
};

#endif /* __STRING_CLASS_H__ */
