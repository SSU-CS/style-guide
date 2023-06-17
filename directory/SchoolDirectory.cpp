/** ***********************************************************************
 * @remark  Example of a School Directory application                     *
 *          Entries take the form of Students, Faculty and Staff          *
 *                                                                        *
 * @remark  Example illustrates a class hierarchy                         *                                *
 *    Base class:  Entry                                                  *
 *    Subclasses:  Student, Faculty, Staff                                *
 *                                                                        *
 * @remark Each class has a header (.h) and implementation (.cpp) files   *  
 * @remark Other features:  overwritten << operator and virtual print     *                                            *
 *                                                                        *
 * @remark: file:  SchoolDirectory.cpp                                    *
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
#include <vector>
#include "Entry.h"
#include "Student.h"
#include "Faculty.h"
#include "Staff.h"


class SchoolDirectory {

private:
  std::vector <Entry> entryVec;

public:
  /** ***********************************************************************
   * @remark Default constructor (with no parameters)                       *
   **************************************************************************/
    SchoolDirectory () {
    }

  /** ***********************************************************************
   * @remark  insert a person into the SchoolDirectory                      *
   * @remark  eirectory entries are maintained in lastname/firstname order  *
   *                                                                        *
   * @param  person  the entry to be inserted into the underlying directory *
   *                                                                        *
   * @pre    entries in the underlying directory are ordered by name        *
   * @post   the underlying directory continues to be ordered by name       *
   **************************************************************************/
   void add (Entry person) {
        // add person to array, maintaining alphabetical order
      int i = entryVec.size() ;
        while (i > 0 && person.comesBefore(entryVec[i-1])) {
            i--;
        }
       entryVec.insert(entryVec.begin() + i, person);
     }

  /** ***********************************************************************
   * @remark  entries in the underlying directory are printed to cout       *
   *          with beginning and end markers                                *
   *                                                                        *
   **************************************************************************/
    void print () {
      std::cout <<  "----------Directory Listing----------" << std::endl;
      //for (std::vector<Entry>::iterator ent = entryVec.begin(); ent != entryVec.end(); ++ent) {
      //  std::cout << *ent << std::endl;
      //}

      for (int i = 0; i < entryVec.size(); i++) {
         std::cout << entryVec[i] << std::endl;
      }
      std::cout <<  "----------End of Listing------------" << std::endl << std::endl;
    }

  /** ***********************************************************************
   * @remark  entries in the directory are searched by first and last name  *
   *                                                                        *
   * @param  first  the first name of a person                              *
   * @param  last   the last name of a person                               *
   *                                                                        *
   * @pre    the underlying directory is ordered by last/first name         *
   * @returns  if the name is found, a pointer to the entry is returned     *
   *           if the name is not found, NULL is returned                   *
   *                                                                        *
   * @remark  searching is performed via a binarysearch                     *
   *                                                                        *
   **************************************************************************/
    Entry * lookup (std::string first, std::string second) {
        int lo = 0;
        int hi = entryVec.size();
        int mid = (hi + lo)/2;
        while (lo < hi) {
            if (entryVec[mid].equals(first, second))
                return &entryVec[mid];
            if (entryVec[mid].comesBefore(first, second))
                lo = mid + 1;
            else hi = mid;
            mid = (hi + lo)/2;
        }
        return NULL;  // return a null entry if entry not found
    }
};
  
  /** ***********************************************************************
   * @remark main performs a reasonable level of testing                    *
   *                                                                        *
   **************************************************************************/
int main ( ) {
  std::cout << "Test Program of a School Directory" << std::endl  << std::endl;

  // constructors
  std::cout << ">>>Declaring Entry Variables" << std::endl;

  SchoolDirectory dir ;
  Student stu1 ("Terry", "Walker", "walkert@math.grinnell.edu",
                1970, "off-campus");
  Student stu2 ("Barbara", "Ellen", "barbara@cs.grinnell.edu",
                2002, "12-34-56");
  Student stu3 ("Donna", "Marie", "donna@math.grinnell.edu",
                1998, "3.1415926535");
  Student stu4 ("Shamrock", "The Cat", "none",
                3000, "varies");
  Student stu5 ("Muffin", "The Cat", "none",
                3000, "varies");
  
  Faculty fac1 ("John", "Stone", "stone@math.grinnell.edu",
                "Science 3829", 3181,
                "Computer Science", 1983);
  Faculty fac2 ("Henry", "Walker", "walker@cs.grinnell.edu",
                "Science 3811", 4208, 
                "Computer Science", 1973);
  Faculty fac3 ("Janet", "Gibson", "gibson@grinnell.edu",
                "Science 1610", 3168,
                "Psychology", 1989);
  Faculty fac4 ("Samuel", "Rebelsky","rebelsky@cs.grinnell.edu",
                "Science 3824", 4410,
                "Computer Science", 1997);
  
  Staff stf1 ("Cat", "In The Hat", "muffin@cat.meow",
              "Campus", 10, "pet");
  Staff stf2 ("Minnie", "Mouse", "minnie@cs.myschool.edu",
              "Magic Kingdon", 31416, "Sys. Admin.");
  Staff stf3 ("Winnie", "Pooh", "winnie@cs.myschool.edu",
              "100 Acre Wood", 2718,"Support");

  // add entries to directory
  std::cout << ">>>Adding entries to the School Directory" << std::endl;
  dir.add(stu1);
  dir.add(fac1);
  dir.add(stu2);
  dir.add(stf1);
  dir.add(fac2);
  dir.add(stu3);
  dir.add(stf2);
  dir.add(fac3);
  dir.add(stu4);
  dir.add(fac4);
  dir.add(stf3);
  dir.add(stu5);
  
  // print directory
  std::cout << ">>>Testing printing of the Directory" << std::endl;

  dir.print();
  
  // check lookup
  std::cout << ">>>Testing the lookup method" << std::endl;
  Entry * ent ;
  std::cout <<  "Searching for Barbara Ellen -- first entry in diretory" << std::endl;
  
  ent = dir.lookup("Barbara", "Ellen");
  if (ent == NULL) {
    std::cout << "Barbara Ellen not found" << std::endl << std::endl;
  } else {
    std::cout << *ent << std::endl << std::endl;
  }

  std::cout <<  "\nSearching for Terry Walker -- last entry in directory" << std::endl;
  ent = dir.lookup("Terry", "Walker");
  if (ent == NULL) {
    std::cout << "Terry Walker not found" << std::endl << std::endl << std::endl;
  } else {
    std::cout << *ent << std::endl << std::endl;
  }
  
  std::cout <<  "\nSearching for Winnie Pooh" << std::endl;
  ent = dir.lookup("Winnie", "Pooh");
  if (ent == NULL) {
    std::cout << "Winnie Pooh not found" << std::endl << std::endl;
  } else {
    std::cout << *ent << std::endl << std::endl;
  }
  
  std::cout <<  "\nSearching for Muffin, The Cat" << std::endl;
  ent = dir.lookup("Muffin", "The Cat");
  if (ent == NULL) {
    std::cout << "Muffin, The Cat, not found" << std::endl << std::endl << std::endl;
  } else {
    std::cout << *ent << std::endl << std::endl;
  }
  
  std::cout <<  "Searching for Muffin, The Dog" << std::endl;
  ent = dir.lookup("Muffin", "The Dog");
  if (ent == NULL) {
    std::cout << "Muffin, The Dog, not found" << std::endl << std::endl;
  } else {
    std::cout << *ent << std::endl << std::endl;
  }

  std::cout << ">>>End of Testing" << std::endl;

  return 0;
}
