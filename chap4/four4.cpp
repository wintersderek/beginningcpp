// Requirements Qualifier
#include <iostream>

enum class AcademicDegree {NONE, ASSOCIATE, BACHELOR, PROFESSIONAL,  
                            MASTER, DOCTOR};
int main ()
{
    // We are looking for someone older than 21 and younger than 35, is 
    // female, has a bachelor or master degree, is unmarried, and speaks hindi
    // or Urdu.

    int age {0};
    char gender {0};
    AcademicDegree degree {0};
    bool married {0};
    bool speaksHindi {0};
    bool speaksUrdu {0};
    bool qualified {0};

    std::cout << "Job application: \n"
              << "-----------------------------------------------\n"
              << "What is your age? ";
    std::cin >> age;
    if (age > 21 && age < 35){
        std::cout << "\nAre you female?  Enter m for male and f for female: ";
        std::cin >> gender;
        if (gender == 'f') {
            std::cout << "Enter your degree (0 = none, 1 = associate, \n"
                      << "2 = bachelor, 3 = professional, 4 = master, and \n"
                      << "5 = doctor): ";
            std::cin >> (age);
            degree = static_cast<AcademicDegree>(age);
            if (degree == AcademicDegree::BACHELOR || 
                    degree == AcademicDegree::MASTER) {
                std::cout << "\nAre you married (0 = No, 1 = Yes)? ";
                std::cin >> married;
                if (!married) {
                    std::cout << "\nDo you speak Hindi (0 = No, 1 = Yes)? ";
                    std::cin >> speaksHindi;
                    std::cout << "\nDo you speak Urdu (0 = No, 1 = Yes)? ";
                    std::cin >> speaksUrdu;
                    if (speaksUrdu || speaksHindi) {
                        qualified = true;
                    }
                }
            }
        }
    }

    if (qualified) {
        std::cout << "Yey! You are qualified for the job!!!";
    } else {
        std::cout << "Thank you for applying for the job.";
    }
    std::cout << std::endl;
    return 0;
}