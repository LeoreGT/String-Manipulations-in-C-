#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "string-class.h"

#define STARTER_SIZE 0

#define I_AM_LESSER -1 //TODO: change to static const int 
#define STRINGS_ARE_EQUAL 0
#define I_AM_GREATER 1

using namespace std;

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

String_t::String_t()
{
  m_string = new char[STARTER_SIZE]; /* CTOR + memory allocation *///TODO: check that new worked
  m_string[0] = 0;  /* this initialized it as 0 which can be freed */
  m_stringSize = STARTER_SIZE; /* make it equal to the starter size, to be changed later */
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

String_t::~String_t()
{
	delete[] m_string; /* DTOR and releases inner data */
  m_stringSize = 0;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

String_t::String_t(const char* _string)//TODO: just use createFrom
{
  m_string = new char[(strlen(_string) + 1)]; /* CTOR + memory allocation of given string size */
  m_stringSize = (strlen(_string)); /* make it equal to the length of the given string + '\0' */
  strcpy(m_string, _string);  /* copy that string into our newly allocated one */
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

String_t::String_t(const String_t& _string)
{
  m_stringSize = _string.getLength();
  strcpy(m_string, _string.getString());
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


char* String_t::createFrom(char* string)//TODO: can add m_stringSize in here too 
{
	char* temp = (char*) malloc(strlen(string) + 1);
	strcpy(temp, string);
	return temp;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int String_t::getLength() const
{
	return this->m_stringSize;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void String_t::resizeString(int incomingSize)
{
  if(incomingSize > m_stringSize)
  {
    delete[] m_string;
    m_string = new char[incomingSize + 1];
    m_stringSize = incomingSize;
  }
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void String_t::setString(const char* newString)
{
  resizeString(strlen(newString) + 1);
	strcpy(this->m_string, newString);
  this->m_stringSize = (strlen(newString));
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const char*  String_t::getString() const
{
	return this->m_string;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int String_t::compareStrings(const String_t& string) const
{
	int comparison;
  comparison = strcmp(this->m_string, string.getString()); /* 'this' can be used in c++ */
  if (comparison == 0)
  {
    return STRINGS_ARE_EQUAL;
  }
  return (comparison > 0) ? I_AM_GREATER : I_AM_LESSER;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void String_t::printString() const
{
	cout << this->m_string;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const String_t& String_t::operator=(const String_t& incomingString) 
{
  if(&incomingString != this)
  {
    resizeString(incomingString.getLength() + 1);

    strcpy(this->m_string, incomingString.getString());
  }

  return *this;
}
