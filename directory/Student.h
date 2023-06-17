/** ***********************************************************************
 * @remark  Student: a class derived from Entry for a School Directory    *
 *    a student entry                                                     *
 *        inherits a first name, last name, and email address from Entry  *
 *        additional fields are the studentr's year and PO Box            *
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
 * @remark: files include header (Student.h), Implementation (Student.cpp)*
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
#ifndef STUDENT_H
#define STUDENT_H

#include "Entry.h"


class Student : public Entry {
 public:
/** ***********************************************************************
 * @remark Full-parameter constructor                                     *
 *                                                                        *
 * @param first    a student's first name                                 *
 * @param last     a student's last name                                  *
 * @param eAddress a student's email address                              *
 * @param year     the student's class or expected-graduation year        *
 * @param box      the student's campus post office box                   *
 *                                                                        *
 **************************************************************************/
  Student (std::string first, std::string last, std::string addr, int yr, std::string box) ;

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

// Students have two special fields
 private:
    int year;
    std::string POBox;

};

#endif
