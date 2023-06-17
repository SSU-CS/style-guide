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
#include <iostream>
#include "Staff.h"

Staff::Staff (std::string first, std::string last, std::string addr,
         std::string room, int ext, std::string ttl) 
  :  Entry(first, last, addr)
    {
      office = room;
      extension = ext;
      title = ttl;
    }

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
std::ostream& Staff::print (std::ostream &os) const {
   os <<  Entry::print(os)
      << "   Office:  " << this->office << "\tOffice Extenstion:  " << this->extension << std::endl
      << "   Title:  " << this->title + "\n";
   return os;
    }

/** ***********************************************************************
 *  @remark main procedure to control processing                          r
 *  uncomment this procedure for unit testing                             *
 **************************************************************************/
/*
int main ( ) {
        // set up three objects
  Staff A ("Muffin", "Cat", "muffin@cat.meow",
           "Campus", 10, "pet");
  Staff B ("Minne", "Mouse", "minnie@cs.myschool.edu",
           "Magic Kingdon", 31416, "Sys. Admin.");
  Staff C ("Winnie", "Pooh", "winnie@cs.myschool.edu",
           "100 Acre Wood", 2718,"Support");
  
  // print objects
  std::cout <<  "Results of equals" << std::endl;
  std::cout <<  "Person A:" << A << std::endl;
  std::cout <<  "Person B:" << B << std::endl;
  std::cout <<  "Person C:" << C << std::endl;
  
  // since methods equals and comesBefore are inherited, 
  //     testing may or may not be done here
  
  //check comparisons
  std::cout << "Entries declared in directory order"  << std::endl;
  std::cout <<  "\tA\tB\tC" << std::endl;
  std::cout <<  "A\t"
            << A.equals(A) << "\t"
            << A.equals(B) << "\t"
            << A.equals(C)
            << std::endl;
  std::cout <<  "B\t"
            << B.equals(A) << "\t"
            << B.equals(B) << "\t"
            << B.equals(C)
            << std::endl;
  std::cout <<  "C\t"
            << C.equals(A) << "\t"
            << C.equals(B) << "\t"
            << C.equals(C)
            << std::endl << std::endl;
  
  std::cout <<  "Results of comesBefore"
            << std::endl;
  std::cout << "\tA\tB\tC"
            << std::endl;
  std::cout << "A\t"
            << A.comesBefore(A)<<  "\t"
            << A.comesBefore(B)<<  "\t"
            << A.comesBefore(C)
            << std::endl;
  std::cout << "B\t"
            << B.comesBefore(A) <<  "\t"
            << B.comesBefore(B)<<  "\t"
            << B.comesBefore(C)
            << std::endl;
  std::cout << "C\t"
            << C.comesBefore(A) <<  "\t"
            << C.comesBefore(B) <<  "\t"
            << C.comesBefore(C)
            << std::endl << std::endl;
}

*/
