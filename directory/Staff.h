/** ***********************************************************************
 * @remark  Student: a class derived from Entry for a School Directory    *
 *    a staff member's entry                                              *
 *        inherits a first name, last name, and email address from Entry  *
 *        additional fields are the member's office, extension, title     *
 *                                                                        *
 * @remark Inherited capabilities include:                                *
 *    Base constructors                                                   *
 *    Comparison operations depend upon last names, then first names      *
 *    Formatted orubt abd output                                          *
 *                                                                        *
 * @remark Overwritten capabilities include:                              *
 *    Multi-parameter constructor                                         *
 *    Formatted print method                                              *
 *                                                                        *
 * @remark: files include header (Staff.h), Implementation (Staff.cpp)    *
 *                                                                        *
 * @remark  Uncomment a main program for unit testing                     *
 *                                                                        *
 * @author Henry M. Walker                                                *
 * @date January 11, 2023                                                 *
 *                                                                        *
 * @remark References                                                     *
 * @remark A School Directory as an Example of Object-Oriented Design     *
 *    http://localhost/courses/cpp-style-guide/directory/index.php        *
 *                                                                        *
 **************************************************************************/
#ifndef STAFF_H
#define STAFF_H

#include "Entry.h"

/** ***********************************************************************
 * @remark Full-parameter constructor                                     *
 *                                                                        *
 * @param first    a staff member's first name                            *
 * @param last     a staff member's last name                             *
 * @param eAddress a staff member's email address                         *
 * @param room     a staff member's office                                *
 * @param ext      the telelphone number extension for the office         *
 * @param title    the staff member's title                               *
 *                                                                        *
 **************************************************************************/
class Staff : public Entry {
 public:
  Staff (std::string first, std::string last, std::string addr,
         std::string room, int ext, std::string ttl) ;

/** ***********************************************************************
 * @remark output a format Faculty object                                 *
 *                                                                        *
 * @param os  output stream which will receive the formatted Faculty data *
 *                                                                        *
 * @ewmrk  by being a virtual function, implementations in subclasses     *
 *         will be interpreted via polymorphism                           *
 *                                                                        *
 * @returns formatted string on the given output stream                   *
 *                                                                        *
 **************************************************************************/
  std::ostream& print (std::ostream &os) const ;

// Staff have two special fields
 private:
  std::string office ;
  int extension ;
  std::string title ;

};

#endif
