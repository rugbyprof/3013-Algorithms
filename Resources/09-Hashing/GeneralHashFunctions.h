/*
 **************************************************************************
 *                                                                        *
 *          General Purpose Hash Function Algorithms Library              *
 *                                                                        *
 * Author: Arash Partow - 2002                                            *
 * URL: http://www.partow.net                                             *
 * URL: http://www.partow.net/programming/hashfunctions/index.html        *
 *                                                                        *
 * Copyright notice:                                                      *
 * Free use of the General Purpose Hash Function Algorithms Library is    *
 * permitted under the guidelines and in accordance with the most current *
 * version of the Common Public License.                                  *
 * http://www.opensource.org/licenses/cpl.php                             *
 *                                                                        *
 **************************************************************************
*/


#ifndef INCLUDE_GENERALHASHFUNCTION_CPP_H
#define INCLUDE_GENERALHASHFUNCTION_CPP_H


#include <string>
#include <iostream>

using namespace std;

unsigned int RSHash  (string str);
unsigned int JSHash  (string str);
unsigned int PJWHash (string str);
unsigned int ELFHash (string str);
unsigned int BKDRHash(string str);
unsigned int SDBMHash(string str);
unsigned int DJBHash (string str);
unsigned int DEKHash (string str);
unsigned int BPHash  (string str);
unsigned int FNVHash (string str);
unsigned int APHash  (string str);


#endif
