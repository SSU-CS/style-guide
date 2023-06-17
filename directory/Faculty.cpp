/** ***********************************************************************
 * @remark  Faculty: a class derived from Entry for a School Directory    *
 *   faculty entry                                                        *
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
#include <iostream>
#include "Faculty.h"

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
Faculty::Faculty (std::string first, std::string last, std::string addr, std::string room,
                 int ext, std::string department, int yr)
  :  Entry(first, last, addr)
    {
      office = room ;
      extension = ext ;
      dept = department ;
      firstYear = yr ; 
    };

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
std::ostream& Faculty::print (std::ostream &os) const {
  os <<  Entry::print(os)
     << "\n   Office:    " << this->office
     << "\tOffice Extension:  " << this->extension 
     << "\n   Department:  " << this->dept
     << "\t   First Year:  " << this->firstYear;
  return os;
}

/** ***********************************************************************
 *  @remark main procedure to control processing                          r
 *  uncomment this procedure for unit testing                             *
 **************************************************************************/
/*int main ( ) {
        // set up four objects
        Faculty A ("Henry", "Walker", "walker@cs.grinnell.edu",
                   "Science 3811", 4208, 
                   "Computer Science", 1974);
        Faculty B ("John", "Stone", "stone@cs.grinnell.edu",
                   "Science 3829", 3181,
                   "Computer Science", 1983);
        Faculty C  ("Samuel", "Rebelsky", "rebelsky@cs.grinnell.edu",
                    "Science 3824", 4410,
                    "Computer Science", 1997);
        Faculty D ("Janet", "Gibson", "gibson@grinnell.edu",
                   "Science 1610", 3168,
                   "Psychology", 1989);
 
        // print objects
        std::cout << "Entries declared in reverse order"  << std::endl;
        std::cout <<  "Person A:" << A << std::endl;
        std::cout <<  "Person B:" << B << std::endl;
        std::cout <<  "Person C:" << C << std::endl;
        std::cout <<  "Person D:" << D << std::endl;

        // since methods equals and comesBefore are inherited, 
        //     testing may or may not be done 
    // print true for 1, false for 0
    std::cout << std::boolalpha;
    
    std::cout <<  "Results of equals for entries"<< std::endl;
    std::cout <<  "\tA\tB\tC\tD"<< std::endl;
    std::cout <<  "A\t"
              << A.equals(A) << "\t" << A.equals(B) << "\t"
              << A.equals(C) << "\t" << A.equals(D) << std::endl;
    std::cout <<  "B\t"
              << B.equals(A) << "\t" << B.equals(B) << "\t"
              << B.equals(C) << "\t" << B.equals(D)
              << std::endl;
    std::cout <<  "C\t"
              << C.equals(A) << "\t" << C.equals(B) << "\t" 
              << C.equals(C) << "\t" << C.equals(D)
              << std::endl;
    std::cout <<  "D\t"
              << D.equals(A) << "\t" << D.equals(B) << "\t"
              << D.equals(C) << "\t" << D.equals(D)
              << std::endl << std::endl;

    std::cout <<  "Results of comesBefore for two strings" << std::endl;
    std::cout <<  "\tA\tB\tC\tD" << std::endl;
    std::cout <<  "A\t"
              << A.comesBefore("Henry", "Walker") << "\t"
              << A.comesBefore("John", "Stone") << "\t" 
              << A.comesBefore("Samuel", "Rebelsky") << "\t"
              << A.comesBefore("Janet", "Gibson")
              << std::endl;
    std::cout <<  "B\t"
              << B.comesBefore("Henry", "Walker") << "\t"
              << B.comesBefore("John", "Stone") << "\t" 
              << B.comesBefore("Samuel", "Rebelsky") << "\t"
              << B.comesBefore("Janet", "Gibson")
             << std::endl;
    std::cout <<  "C\t"
              << C.comesBefore("Henry", "Walker") << "\t"
              << C.comesBefore("John", "Stone") << "\t" 
              << C.comesBefore("Samuel", "Rebelsky") << "\t"
              << C.comesBefore("Janet", "Gibson")
              << std::endl;
    std::cout <<  "D\t"
              << D.comesBefore("Henry", "Walker") << "\t"
              << D.comesBefore("John", "Stone") << "\t" 
              << D.comesBefore("Samuel", "Rebelsky") << "\t"
              << D.comesBefore("Janet", "Gibson")
              << std::endl;

    return 0;
}
*/
