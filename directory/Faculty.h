/** ***********************************************************************
 * @remark  Faculty: a class derived from Entry for a School Directory    *
 *    faculty entry                                                       *
 *        inherits a first name, last name, and email address from Entry  *
 *        additional fields are the faculty member's office, extension,   *
 *            department, and year of initial aappointment to the school  *
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
 * @remark: files include header (Faculty.h), Implementation (Faculty.cpp)*
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
#ifndef FACULTY_H
#define FACULTY_H

#include "Entry.h"

// Directory entries specific to faculty
class Faculty : public Entry {
    // Faculty have four special fields

 public:

/** ***********************************************************************
 * @remark Full-parameter constructor                                     *
 *                                                                        *
 * @param first    a faculty member's first name                          *
 * @param last     a faculty member's last name                           *
 * @param eAddress a faculty member's email address                       *
 * @param room     a faculty member's office                              *
 * @param ext      the telelphone number extension for the office         *
 * @param department the faculty member's [primary] department            *
 * @param yr       the year of the faculty member's first appointment     *
 *                                                                        *
 **************************************************************************/
  Faculty (std::string first, std::string last, std::string addr, std::string room,
           int ext, std::string department, int yr);

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
  virtual std::ostream& print (std::ostream &os) const ;

      // Faculty have four special fields
private:
  std::string office ;
  int extension ;
  std::string dept ;
  int firstYear ;

};

#endif
